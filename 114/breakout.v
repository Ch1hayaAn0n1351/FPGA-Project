`timescale 1ns / 1ps

// 修复端口定义、模块实例化、信号映射后的打砖块主模块
module breakout(
    input wire sys_clk,        // 新增：counter需要的系统时钟（如50MHz）
    input wire sys_rst_n,      // 新增：全局复位（低有效）
    input wire left,           // 左移控制
    input wire right,          // 右移控制
    output wire hsync,         // VGA行同步
    output wire vsync,         // VGA场同步
    output wire [15:0] rgb,    // VGA显示数据
    output reg endGame         // 游戏结束标志
);

// ====================== 内部参数定义（保留原有游戏参数） ======================
    localparam H_VALID   = 10'd640;  // 可视区域宽度（与syncGen一致）
    localparam V_VALID   = 10'd480;  // 可视区域高度（与syncGen一致）
    localparam RGB_BLACK     = 16'h0000;  
    localparam RGB_WHITE     = 16'hFFFF;  
    localparam RGB_RED       = 16'hF800;  
    localparam RGB_GREEN     = 16'h07E0;  
    localparam RGB_BLUE      = 16'h001F;  
    localparam RGB_YELLOW    = 16'hFFE0;  
    localparam RGB_CHECK1    = 16'h8410;  
    localparam RGB_CHECK2    = 16'h0088;  

    integer brW = 60, brH = 20;     // 砖块尺寸
    integer pW = 64;                // 挡板宽度
    integer pH = 4;                 // 挡板高度
    integer paddle_speed = 10;      // 挡板速度
    integer ball_half_width = 4;    // 小球半宽
    integer ball_half_height = 2;   // 小球半高
    integer ballSpeedX = 4;         // 小球X速度（修正原3'b100为整数）
    integer ballSpeedY = 4;         // 小球Y速度

    // 边界参数（与可视区域匹配）
    integer left_border = 0;       
    integer right_border = H_VALID - 1;     
    integer top_border = 0;        
    integer bottom_border = V_VALID - 1;    

// ====================== 内部信号定义 ======================
    // 模块实例化信号
    wire vga_clk;                  // counter输出的25MHz VGA时钟
    wire [9:0] cX, cY;             // 像素坐标（对应syncGen的pix_x/pix_y）
    wire rgb_valid;                // 有效显示区域（对应syncGen的rgb_valid）
    reg [15:0] pix_data;           // 传给syncGen的像素数据（核心修复点）

    // 【修复1：显式声明所有隐式net，解决Implicit Net警告】
    wire border;          // 边界检测
    wire ballX, ballY, ball; // 小球显示相关
    wire paddleX, paddleY, paddle; // 挡板显示相关
    wire brickCollision, bouncingObject, resetFrame; // 碰撞相关

    // 游戏逻辑信号
    reg [9:0] ballPX = 415;        // 小球X坐标
    reg [9:0] ballPY = 460;        // 小球Y坐标
    reg [9:0] paddlePX = 415;      // 挡板X坐标
    reg [9:0] paddlePY = 468;      // 挡板Y坐标

    reg [31:0] brickState = 32'hFFFFFFFF;  // 砖块状态（1=存在，0=消失）
    reg [9:0] brickPX[0:7], brickPY[0:3];  // 砖块坐标数组
    integer brickIndex = -1;               // 碰撞砖块索引
    reg [3:0] bricks = 4'b0;               // 行砖块显示标志
    reg bricksRow = 1'b1;                  // 行砖块清空标志

    // 碰撞检测信号
    reg collisionX1, collisionX2, collisionY1;
    reg collisionPaddle, collisionBottom;
    reg ball_dirX = 0, ball_dirY = 1;      // 小球方向（0=右/下，1=左/上）

// ====================== 模块实例化（核心修复：端口严格匹配） ======================
    // 1. 实例化时钟分频模块（counter）：50MHz→25MHz VGA时钟
    counter u_counter(
        .sys_clk    (sys_clk),    // 系统时钟（如50MHz）
        .sys_rst_n  (sys_rst_n),  // 全局复位
        .vga_clk    (vga_clk)     // 输出25MHz VGA时钟
    );

    // 2. 实例化VGA同步信号生成模块（syncGen）
    syncGen u_syncGen(
        .vga_clk    (vga_clk),    // 25MHz VGA时钟
        .sys_rst_n  (sys_rst_n),  // 全局复位
        .pix_data   (pix_data),   // 输入像素数据（由游戏逻辑生成）
        .pix_x      (cX),         // 输出像素X坐标（映射到cX）
        .pix_y      (cY),         // 输出像素Y坐标（映射到cY）
        .hsync      (hsync),      // VGA行同步（直接输出）
        .vsync      (vsync),      // VGA场同步（直接输出）
        .rgb        (rgb)         // VGA最终显示数据（直接输出）
    );

// ====================== 初始化砖块坐标（修正时序+变量声明） ======================
    initial begin
        // 【修复2：在initial块内声明j/k变量，解决未声明错误】
        integer j, k;
        // 初始化8列×4行砖块坐标
        for(j=0; j<8; j=j+1) begin
            brickPX[j] = left_border + 33 + 60*j;
        end
        for(k=0; k<4; k=k+1) begin
            brickPY[k] = top_border + 30 + 25*k;
        end
        // 初始化游戏状态
        endGame <= 1'b0;
        collisionX1 <= 1'b0;
        collisionX2 <= 1'b0;
        collisionY1 <= 1'b0;
        collisionPaddle <= 1'b0;
        collisionBottom <= 1'b0;
    end

// ====================== 游戏逻辑（保留原有逻辑，修正语法） ======================
    // 帧复位信号：每帧结束（最后一个有效像素）清零碰撞标志
    assign resetFrame = (cX == H_VALID - 1) && (cY == V_VALID - 1) && rgb_valid;

    // 边界检测
    assign border = (cX == left_border) | (cX == right_border) | 
                    (cY == top_border) | (cY == bottom_border);

    // 小球显示判断
    assign ballX = (cX >= ballPX - ball_half_width) && (cX <= ballPX + ball_half_width);
    assign ballY = (cY >= ballPY - ball_half_height) && (cY <= ballPY + ball_half_height);
    assign ball = ballX & ballY;

    // 挡板显示判断
    assign paddleX = (cX >= paddlePX - pW/2) && (cX <= paddlePX + pW/2 - 1);
    assign paddleY = (cY >= paddlePY - pH/2) && (cY <= paddlePY + pH/2 - 1);
    assign paddle = paddleX & paddleY;

    // 碰撞对象总判断
    assign bouncingObject = border | paddle | (|bricks);
    // 砖块碰撞判断
    assign brickCollision = |bricks & ball;

    // 砖块显示逻辑（核心修复：变量声明移到always块首）
    always @(posedge vga_clk or negedge sys_rst_n) begin
        // 【修复3：所有变量声明必须放在always块内第一条语句位置】
        integer i, j, k;
        reg brick_show;
        
        if(!sys_rst_n) begin
            bricks <= 4'b0;
            bricksRow <= 1'b1;
        end else begin
            bricks <= 4'b0;
            bricksRow <= 1'b1;
            // 遍历所有砖块（8列×4行=32个）
            for(i=0; i<32; i=i+1) begin
                j = i % 8;
                k = i / 8;
                brick_show = 1'b0;
                if(brickState[i]) begin
                    brick_show = (cX >= brickPX[j] - brW/2) && (cX <= brickPX[j] + brW/2 - 1) &&
                                 (cY >= brickPY[k] - brH/2) && (cY <= brickPY[k] + brH/2 - 1);
                    // 按行标记砖块显示
                    case(k)
                        0: bricks[0] <= bricks[0] | brick_show;
                        1: bricks[1] <= bricks[1] | brick_show;
                        2: bricks[2] <= bricks[2] | brick_show;
                        3: bricks[3] <= bricks[3] | brick_show;
                    endcase
                end
                bricksRow <= bricksRow & ~(brickState[i] & brick_show);
            end
        end
    end

    // 边界碰撞检测
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if(!sys_rst_n) begin
            collisionX1 <= 1'b0;
            collisionX2 <= 1'b0;
            collisionY1 <= 1'b0;
        end else if(resetFrame) begin
            collisionX1 <= 1'b0;
            collisionX2 <= 1'b0;
            collisionY1 <= 1'b0;
        end else begin
            if(bouncingObject & (ballPX - ball_half_width <= left_border) & (cY == ballPY))
                collisionX1 <= 1'b1;
            if(bouncingObject & (ballPX + ball_half_width >= right_border) & (cY == ballPY))
                collisionX2 <= 1'b1;
            if(bouncingObject & (ballPY - ball_half_height <= top_border) & (cX == ballPX))
                collisionY1 <= 1'b1;
        end
    end

    // 挡板碰撞检测
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if(!sys_rst_n) begin
            collisionPaddle <= 1'b0;
        end else if(resetFrame) begin
            collisionPaddle <= 1'b0;
        end else if(bouncingObject & (ball_dirY == 0) & 
                   (ballPY + ball_half_height >= paddlePY - pH/2) &
                   (ballPY - ball_half_height <= paddlePY + pH/2) & 
                   (ballPX + ball_half_width >= paddlePX - pW/2) & 
                   (ballPX - ball_half_width <= paddlePX + pW/2)) begin
            collisionPaddle <= 1'b1;
        end
    end

    // 底部碰撞（游戏结束）检测【核心修复：合并endGame所有赋值到该块】
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if(!sys_rst_n) begin
            collisionBottom <= 1'b0;
            endGame <= 1'b0; // 复位时游戏未结束
        end else if(resetFrame) begin
            collisionBottom <= 1'b0;
        end else if(bouncingObject & (ballPY + ball_half_height >= bottom_border) & (cX == ballPX)) begin
            collisionBottom <= 1'b1;
            endGame <= 1'b1; // 唯一的endGame赋值源
        end
        // 游戏结束后保持endGame为1（避免被复位）
        else if(endGame) begin
            endGame <= 1'b1;
        end
    end

    // 小球&挡板运动逻辑（核心修复：移除此处的endGame赋值）
    always @(posedge vga_clk or negedge sys_rst_n) begin
        // 【修复4：所有变量声明必须放在always块内第一条语句位置】
        integer i, j, k;
        
        if(!sys_rst_n) begin
            // 复位：恢复初始位置
            ballPX <= 415;
            ballPY <= 460;
            paddlePX <= 415;
            paddlePY <= 468;
            ball_dirX <= 0;
            ball_dirY <= 1;
            brickIndex <= -1;
            brickState <= 32'hFFFFFFFF;
        end else if(resetFrame) begin
            // 帧结束：更新位置和方向
            // 1. 处理砖块碰撞
            if(brickIndex != -1) begin
                brickState[brickIndex] <= 1'b0; // 消除碰撞的砖块
                ball_dirY <= ~ball_dirY;        // Y方向反弹
                brickIndex <= -1;
            end

            // 2. 处理边界碰撞
            if(collisionX1) begin 
                ball_dirX <= 0; // 左边界→向右
                ballPX <= left_border + ball_half_width + 1;
            end else if(collisionX2) begin 
                ball_dirX <= 1; // 右边界→向左
                ballPX <= right_border - ball_half_width - 1;
            end else begin 
                ballPX <= ballPX + (ball_dirX ? -ballSpeedX : ballSpeedX);
            end

            // 3. 处理挡板/上边界碰撞（移除endGame赋值）
            if(collisionPaddle) begin 
                ball_dirY <= 1; // 碰挡板→向上
                ballPY <= paddlePY - pH/2 - ball_half_height;
            end else if(collisionY1) begin 
                ball_dirY <= 0; // 上边界→向下
                ballPY <= top_border + ball_half_height + 1;
            end else if(collisionBottom) begin 
                // 移除：endGame <= 1'b1; （避免多驱动）
                // 仅更新小球位置，endGame由底部碰撞块单独驱动
                ballPY <= bottom_border - ball_half_height - 1;
            end else begin 
                ballPY <= ballPY + (ball_dirY ? -ballSpeedY : ballSpeedY);
            end
            
            // 4. 处理挡板移动
            if(!left && (paddlePX - pW/2 > left_border)) begin
                paddlePX <= paddlePX - paddle_speed;
            end else if(!right && (paddlePX + pW/2 < right_border)) begin
                paddlePX <= paddlePX + paddle_speed;
            end

            // 5. 记录碰撞的砖块索引
            if(brickCollision) begin
                for(i=0; i<32; i=i+1) begin
                    j = i % 8;
                    k = i / 8;
                    if(brickState[i] && (cX >= brickPX[j] - brW/2) && (cX <= brickPX[j] + brW/2 - 1) &&
                       (cY >= brickPY[k] - brH/2) && (cY <= brickPY[k] + brH/2 - 1)) begin
                        brickIndex <= i;
                    end
                end
            end
        end
    end

    // 像素数据生成（传给syncGen的pix_data）
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if(!sys_rst_n) begin
            pix_data <= RGB_BLACK;
        end else if(!rgb_valid) begin
            pix_data <= RGB_BLACK; // 非有效区域显示黑色
        end else if(endGame) begin
            // 游戏结束：棋盘格背景
            pix_data <= ((cX[5] ^ cY[5]) ? RGB_CHECK1 : RGB_CHECK2);
        end else begin
            // 游戏中：按优先级显示（小球>挡板>砖块>边界>背景）
            if(ball) begin
                pix_data <= RGB_GREEN;
            end else if(paddle) begin
                pix_data <= RGB_YELLOW;
            end else if(bricks[0] | bricks[3]) begin
                pix_data <= RGB_RED;
            end else if(bricks[1]) begin
                pix_data <= RGB_GREEN;
            end else if(bricks[2]) begin
                pix_data <= RGB_BLUE;
            end else if(border) begin
                pix_data <= RGB_WHITE;
            end else begin
                pix_data <= RGB_BLACK;
            end
        end
    end

endmodule