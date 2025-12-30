// 屏蔽DECLFILENAME警告（解决文件名与模块名不匹配问题）
/* verilator lint_off DECLFILENAME */
`timescale 1ns/1ps
// 定义计数器模块，模块名 counter，端口列表：clock（时钟输入）、out（24位计数器输出）
module counter(clock, out);
    input clock;
    output [23:0] out;
    reg[23:0] out;
    always @(posedge clock) out <= out + 1;
endmodule

`timescale 1ns/1ps
module syncGen(clock, hsync, vsync, hcount, vcount, inDispArea);
    input clock;
    output hsync, vsync, inDispArea;
    output [9:0] hcount, vcount;
    
    reg hsync, vsync, hblank, vblank, inDispArea, inDispAreaX, inDispAreaY;
    reg[9:0] hcount, vcount;
    
    wire hson, hsoff, hreset, hblankon;
    wire vson, vsoff, vreset, vblankon;
    
    assign hblankon = hcount == 639;
    assign hson = hcount == 652;
    assign hsoff = hcount == 746;
    assign hreset = hcount == 793;
    
    assign vblankon = hreset & (vcount == 479);
    assign vson = hreset & (vcount == 492);
    assign vsoff = hreset & (vcount == 494);
    assign vreset = hreset & (vcount == 527);

    always @(posedge clock) begin
        inDispAreaX <= hreset ? 1 : hblankon ? 0 : inDispAreaX;
        inDispAreaY <= vreset ? 1 : vblankon ? 0 : inDispAreaY;
        inDispArea <= inDispAreaX & inDispAreaY;
    
        hcount <= hreset ? 0 : hcount + 1;
        hblank <= hreset ? 0 : hblankon ? 1 : hblank;
        hsync <= hson ? 0 : hsoff ? 1 : hsync;
        
        vcount <= hreset ? (vreset ? 0: vcount + 1): vcount;
        vblank <= vreset ? 0 : vblankon ? 1 : vblank;
        vsync <= vson ? 0 : vsoff ? 1 : vsync;
    end
endmodule

`timescale 1ns / 1ps
// 纯ANSI风格端口声明，避免重复声明
module breakout(
    input disp, 
    input left, 
    input right, 
    input fire1,       // 发射按键1（左上方）
    input fire2,       // 发射按键2（右上方）
    input clock, 
    input rst_n,       // 低电平有效复位
    output hsync, 
    output vsync, 
    output r, 
    output g, 
    output b,
    output reg endGame,  // 直接指定为output reg，避免后续重复声明
    output reg winGame   // 直接指定为output reg，避免后续重复声明
);
    // ---------------------- 所有常量封装为localparam（统一管理，删除防抖专属常量） ----------------------
    // 砖块常量
    localparam BRICK_WIDTH = 60;
    localparam BRICK_HEIGHT = 20;
    localparam BRICK_GAP = 5;
    localparam BRICK_OFFSET_X = 10;
    localparam BRICK_OFFSET_Y = -10;
    
    // 挡板常量
    localparam PADDLE_WIDTH = 64;
    localparam PADDLE_HEIGHT = 4;
    localparam PADDLE_SPEED = 10;
    
    // 小球常量
    localparam BALL_HALF_WIDTH = 4;
    localparam BALL_HALF_HEIGHT = 4;
    localparam BALL_SPEED_X = 3'b100;
    localparam BALL_SPEED_Y = 3'b100;
    localparam BALL_INIT_Y = 466;  // 小球初始Y坐标
    localparam BALL_INIT_X = 415;  // 小球初始X坐标
    
    // 边界常量
    localparam LEFT_BORDER = 140;
    localparam RIGHT_BORDER = 680;
    localparam TOP_BORDER = 35;
    localparam BOTTOM_BORDER = 480;
    
    // 小球方向常量
    localparam BALL_INIT_DIR_X = 1'b1;
    localparam BALL_INIT_DIR_Y = 1'b0;
    
    // 挡板初始坐标常量
    localparam PADDLE_INIT_X = 415;
    localparam PADDLE_INIT_Y = 468;
    // ---------------------- 常量封装结束 ----------------------

    // 内部变量定义（仅变量，无常量，删除所有防抖相关寄存器）
    integer i, j, k;
    integer brickIndex = -1;
    
    wire inDispArea, border, ball, ballX, ballY, paddle, paddleX, paddleY;
    wire bouncingObject, resetFrame, brickCollision;
    wire[23:0] num;
    wire[9:0] cX, cY, gX, gY;
 
    // 砖块状态数组
    reg brickX[0:31];
    reg brickY[0:31];
    
    // 小球/挡板坐标（使用封装常量初始化）
    reg[9:0] ballPX = BALL_INIT_X;  
    reg[9:0] ballPY = BALL_INIT_Y;  
    reg[9:0] paddlePX = PADDLE_INIT_X;
    reg[9:0] paddlePY = PADDLE_INIT_Y;
    
    // 游戏启动状态寄存器
    reg game_started = 1'b0;
    
    reg[3:0] bricks = 4'b0;

    // 砖块坐标初始化（使用封装常量）
    reg[9:0] brickPX[0:7] = '{
        140+33+(BRICK_WIDTH+BRICK_GAP)*0 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*1 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*2 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*3 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*4 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*5 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*6 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*7 + BRICK_OFFSET_X
    };
    
    reg[9:0] brickPY[0:3] = '{
        35+30+25*0 + BRICK_OFFSET_Y, 35+30+25*1 + BRICK_OFFSET_Y,
        35+30+25*2 + BRICK_OFFSET_Y, 35+30+25*3 + BRICK_OFFSET_Y
    };
    
    // 砖块初始状态（全存在）
    reg[31:0] brickState = 32'hFFFFFFFF;
    reg[7:0] font0[7:0], font1[7:0], font2[7:0], font3[7:0], font4[7:0];
    reg[7:0] font5[7:0], font6[7:0], font7[7:0], font8[7:0], font9[7:0];

    // 游戏状态辅助寄存器
    reg bricksRow = 1'b1;
    
    reg collisionX1 = 1'b0, collisionX2 = 1'b0, collisionY1 = 1'b0;
    reg collisionPaddle = 1'b0;           
    reg collisionBottom = 1'b0;            
    
    // 小球运动方向（使用封装常量）
    reg ball_dirX = BALL_INIT_DIR_X;
    reg ball_dirY = BALL_INIT_DIR_Y;
    
    // 胜利动画寄存器
    reg flash_en = 1'b0;
    reg[9:0] light_x = LEFT_BORDER;
    
    // 数字0点阵字体初始化
    initial begin
        font0[0] = 8'b01111110; font0[1] = 8'b01000010;
        font0[2] = 8'b01000010; font0[3] = 8'b01000010;
        font0[4] = 8'b01000010; font0[5] = 8'b01000010;
        font0[6] = 8'b01000010; font0[7] = 8'b01111110;
    end
    
    // 复位与游戏状态更新
    always @(posedge clock or negedge rst_n) begin
        if(!rst_n) begin
            // 复位小球/挡板坐标（使用封装常量）
            ballPX <= BALL_INIT_X;
            ballPY <= BALL_INIT_Y;
            paddlePX <= PADDLE_INIT_X;
            paddlePY <= PADDLE_INIT_Y;
            
            // 复位砖块状态
            brickState <= 32'hFFFFFFFF;
            
            // 复位游戏标记
            endGame <= 1'b0;
            winGame <= 1'b0;
            game_started <= 1'b0;
            bricksRow <= 1'b1;
            
            // 复位碰撞标记
            collisionX1 <= 1'b0;
            collisionX2 <= 1'b0;
            collisionY1 <= 1'b0;
            collisionPaddle <= 1'b0;
            collisionBottom <= 1'b0;
            brickIndex <= -1;
            
            // 复位砖块坐标（使用封装常量）
            brickPX[0] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*0 + BRICK_OFFSET_X;
            brickPX[1] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*1 + BRICK_OFFSET_X;
            brickPX[2] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*2 + BRICK_OFFSET_X;
            brickPX[3] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*3 + BRICK_OFFSET_X;
            brickPX[4] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*4 + BRICK_OFFSET_X;
            brickPX[5] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*5 + BRICK_OFFSET_X;
            brickPX[6] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*6 + BRICK_OFFSET_X;
            brickPX[7] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*7 + BRICK_OFFSET_X;
            
            brickPY[0] <= 35+30+25*0 + BRICK_OFFSET_Y;
            brickPY[1] <= 35+30+25*1 + BRICK_OFFSET_Y;
            brickPY[2] <= 35+30+25*2 + BRICK_OFFSET_Y;
            brickPY[3] <= 35+30+25*3 + BRICK_OFFSET_Y;
            
            // 复位小球方向
            ball_dirX <= BALL_INIT_DIR_X;
            ball_dirY <= BALL_INIT_DIR_Y;
            
            // 复位胜利动画
            flash_en <= 1'b0;
            light_x <= LEFT_BORDER;
        end
        else begin
            // 保护左上角砖块
            if(brickState[0] == 1'b0 && !brickCollision && !resetFrame) begin
                brickState[0] <= 1'b1;
            end
            
            // 胜利触发检测
            if(brickState == 32'h0 && !endGame) begin
                winGame <= 1'b1;
            end
            
            // 胜利动画逻辑
            if(winGame) begin
                if(num[17] == 1'b1) begin
                    flash_en <= 1'b1;
                end else begin
                    flash_en <= 1'b0;
                end
                
                if(resetFrame) begin
                    light_x <= (light_x >= RIGHT_BORDER) ? LEFT_BORDER : light_x + 2;
                end
            end
            
            // 发射按键处理（直接使用原始按键信号，无防抖）
            if(!game_started && !winGame && !endGame) begin
                if(~fire1) begin
                    game_started <= 1'b1;
                    ball_dirX <= 1'b1;
                    ball_dirY <= 1'b1;
                end
                else if(~fire2) begin
                    game_started <= 1'b1;
                    ball_dirX <= 1'b0;
                    ball_dirY <= 1'b1;
                end
            end
        end
    end
    
    // 砖块扫描逻辑（使用封装常量）
    always @(posedge num[0]) begin
        bricks = 4'b0;
        for(i=24; i<32; i=i+1)
            bricksRow = bricksRow & ~brickState[i];
        
        for(i=0; i<32; i=i+1) begin
            j = i % 8;
            k = i / 8;
            if(brickState[i]) begin
                if(i == 0 || i == 1) begin
                    brickX[i] = (cX >= brickPX[j] - BRICK_WIDTH/2) && (cX <= brickPX[j] + BRICK_WIDTH/2 - 1) ? 1'b1 : 1'b0;
                    brickY[i] = (cY >= brickPY[k] - BRICK_HEIGHT/2) && (cY <= brickPY[k] + BRICK_HEIGHT/2 - 1) ? 1'b1 : 1'b0;
                end else begin
                    brickX[i] = (cX == brickPX[j] - BRICK_WIDTH/2) ? 1 : (cX == brickPX[j] + BRICK_WIDTH/2 - 1) ? 0 : brickX[i];
                    brickY[i] = (cY == brickPY[k] - BRICK_HEIGHT/2) ? 1 : (cY == brickPY[k] + BRICK_HEIGHT/2 - 1) ? 0 : brickY[i];
                end
                case(k)
                    0: bricks[0] |= brickX[i] & brickY[i];
                    1: bricks[1] |= brickX[i] & brickY[i];
                    2: bricks[2] |= brickX[i] & brickY[i];
                    3: bricks[3] |= brickX[i] & brickY[i];
                endcase
            end
        end
    end
    
    // 模块例化
    counter c(.clock(clock), .out(num));
    syncGen generator(.clock(num[0]), .hsync(hsync), .vsync(vsync), 
                     .hcount(cX), .vcount(cY), .inDispArea(inDispArea));
    
    // 边界碰撞检测（使用封装常量）
    always @(posedge num[0] or negedge rst_n) begin
        if(!rst_n) begin
            collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
        end else if(resetFrame) begin
            collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
        end else begin
            if(game_started && bouncingObject & (ballPX - BALL_HALF_WIDTH <= LEFT_BORDER) & (cY == ballPY))
                collisionX1 <= 1'b1;

            if(game_started && bouncingObject & (ballPX + BALL_HALF_WIDTH >= RIGHT_BORDER) & (cY == ballPY))
                collisionX2 <= 1'b1;

            if(game_started && bouncingObject & (ballPY - BALL_HALF_HEIGHT <= TOP_BORDER) & (cX == ballPX))
                collisionY1 <= 1'b1;
        end
    end
    
    // 挡板碰撞检测（使用封装常量）
    always @(posedge num[0] or negedge rst_n) begin
        if(!rst_n) begin
            collisionPaddle <= 1'b0;
        end else if(resetFrame) begin
            collisionPaddle <= 1'b0;
        end else if(game_started && bouncingObject & (ball_dirY == 1'b0) & 
                   (ballPY + BALL_HALF_HEIGHT >= paddlePY - PADDLE_HEIGHT/2) &
                   (ballPY - BALL_HALF_HEIGHT <= paddlePY + PADDLE_HEIGHT/2) & 
                   (ballPX + BALL_HALF_WIDTH >= paddlePX - PADDLE_WIDTH/2) & 
                   (ballPX - BALL_HALF_WIDTH <= paddlePX + PADDLE_WIDTH/2)) begin
            collisionPaddle <= 1'b1;
        end
    end
    
    // 下边界碰撞检测（使用封装常量）
    always @(posedge num[0] or negedge rst_n) begin
        if(!rst_n) begin
            collisionBottom <= 1'b0;
        end else if(resetFrame) begin
            collisionBottom <= 1'b0;
        end else begin
            if(game_started && bouncingObject & (ballPY + BALL_HALF_HEIGHT >= BOTTOM_BORDER) & (cX == ballPX)) begin
                collisionBottom <= 1'b1;
            end
        end
    end
    
    // 核心游戏逻辑（使用封装常量，直接使用原始按键信号）
    always @(posedge num[0] or negedge rst_n) begin
        if(!rst_n) begin
            brickIndex <= -1;
        end else begin
            if(brickCollision) begin
                brickIndex <= -1;
                for(i=0; i<32; i=i+1) begin
                    if(brickX[i] & brickY[i]) begin
                        brickIndex <= i;
                        break;
                    end
                end
            end
            
            if(resetFrame) begin
                // 砖块击碎逻辑
                if(game_started && brickIndex >= 0 && brickIndex < 32) begin
                    brickState[brickIndex] <= 1'b0;
                    ball_dirY <= ~ball_dirY;
                    brickIndex <= -1;
                end
                
                // 未发射状态：同步移动（直接使用原始按键信号）
                if(!game_started && !winGame && !endGame) begin
                    if(~left && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin
                        paddlePX <= paddlePX - PADDLE_SPEED;
                        ballPX <= paddlePX - PADDLE_SPEED;
                    end
                    else if(~right && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin
                        paddlePX <= paddlePX + PADDLE_SPEED;
                        ballPX <= paddlePX + PADDLE_SPEED;
                    end
                    ballPY <= BALL_INIT_Y;
                end
                
                // 已发射状态：正常运动（直接使用原始按键信号）
                else if(game_started && !winGame && !endGame) begin
                    // 左右边界处理
                    if(collisionX1) begin 
                        ball_dirX <= 1'b0;
                        ballPX <= LEFT_BORDER + BALL_HALF_WIDTH + BALL_SPEED_X;
                    end else if(collisionX2) begin 
                        ball_dirX <= 1'b1;
                        ballPX <= RIGHT_BORDER - BALL_HALF_WIDTH - BALL_SPEED_X;
                    end else begin 
                        ballPX <= ballPX + (ball_dirX ? -BALL_SPEED_X : BALL_SPEED_X);
                    end
                    
                    // 上下/挡板碰撞处理
                    if(collisionPaddle) begin 
                        ball_dirY <= 1'b1;
                        ballPY <= paddlePY - PADDLE_HEIGHT/2 - BALL_HALF_HEIGHT - 1;
                    end 
                    else if(collisionY1) begin 
                        ball_dirY <= 1'b0;
                        ballPY <= TOP_BORDER + BALL_HALF_HEIGHT + BALL_SPEED_Y;
                    end 
                    else if(collisionBottom) begin 
                        endGame <= 1'b1; 
                    end 
                    else begin
                        ballPY <= ballPY + (ball_dirY ? -BALL_SPEED_Y : BALL_SPEED_Y);
                    end
                    
                    // 挡板移动（直接使用原始按键信号）
                    if(~left && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin
                        paddlePX <= paddlePX - PADDLE_SPEED;
                    end else if(~right && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin
                        paddlePX <= paddlePX + PADDLE_SPEED;
                    end
                end
            end
        end
    end
    
    // 组合逻辑赋值（使用封装常量）
    assign ballX = (cX == ballPX - BALL_HALF_WIDTH) ? 1'b1 : (cX == ballPX + BALL_HALF_WIDTH) ? 1'b0 : ballX;
    assign brickCollision = |bricks & ball;
    assign bouncingObject = border | paddle | bricks;
    assign resetFrame = (cX==639) & (cY==479);
    assign border = (cX==LEFT_BORDER) | (cX==RIGHT_BORDER) | 
                    (cY==TOP_BORDER) | (cY==BOTTOM_BORDER);
    assign gX = cX; assign gY = cY;
    assign ballY = (cY == ballPY - BALL_HALF_HEIGHT) ? 1'b1 : (cY == ballPY + BALL_HALF_HEIGHT) ? 1'b0 : ballY;
    assign ball = ballX & ballY;
    assign paddleX = (cX == paddlePX - PADDLE_WIDTH/2) ? 1'b1 : (cX == paddlePX + PADDLE_WIDTH/2 - 1) ? 1'b0 : paddleX;
    assign paddleY = (cY == paddlePY - PADDLE_HEIGHT/2) ? 1'b1 : (cY == paddlePY + PADDLE_HEIGHT/2 - 1) ? 1'b0 : paddleY;
    assign paddle = paddleX & paddleY;
    
    // 胜利动画组合逻辑
    wire win_border, win_light;
    assign win_border = flash_en & inDispArea & ((cX == LEFT_BORDER) | (cX == RIGHT_BORDER) | (cY == TOP_BORDER) | (cY == BOTTOM_BORDER));
    assign win_light = inDispArea & (cX == light_x) & (cY >= (TOP_BORDER + BOTTOM_BORDER)/2 - 10) & (cY <= (TOP_BORDER + BOTTOM_BORDER)/2 + 10);
    
    // RGB输出逻辑
    assign r = winGame ? (win_border | win_light) : (endGame ? (cX[5] ^ cY[5]) : (border | bricks[0] | bricks[3] | paddle));
    assign g = winGame ? (win_light) : (endGame ? (cX[4] ^ cY[4]) : (border | bricks[1] | bricks[3] | paddle | ball));
    assign b = winGame ? (win_border) : (endGame ? (cX[3] ^ cY[3]) : (border | bricks[2] | paddle | ball));
endmodule

`timescale 1ns / 1ps
module DevelopmentBoard(
    input wire clk, //50MHz
    input wire reset, B2, B3, B4, B5,  // B2=左移、B3=右移、B4=发射1、B5=发射2
    output wire h_sync, v_sync,
    output wire [15:0] rgb,
    
    output wire led1,
    output wire led2,
    output wire led3,
    output wire led4,
    output wire led5
);

wire rst_n;
wire r_1bit, g_1bit, b_1bit;
wire game_end;
wire game_win;

// 复位极性调整
assign rst_n = reset; 

// 例化breakout模块
breakout u_breakout(
    .disp(1'b0),
    .left(B2),
    .right(B3),
    .fire1(B4),
    .fire2(B5),
    .clock(clk),
    .rst_n(rst_n),
    .hsync(h_sync),
    .vsync(v_sync),
    .r(r_1bit),
    .g(g_1bit),
    .b(b_1bit),
    .endGame(game_end),
    .winGame(game_win)
);

// RGB位宽扩展
wire [4:0] r_5, g_5, b_5;
assign r_5 = {5{r_1bit}};
assign g_5 = {5{g_1bit}};
assign b_5 = {5{b_1bit}};
assign rgb = {1'b0, r_5, g_5, b_5};

// LED对应关系
assign led1 = ~rst_n;
assign led2 = ~B2;
assign led3 = ~B3;
assign led4 = ~B4;
assign led5 = ~B5;

endmodule
/* verilator lint_on DECLFILENAME */

