`timescale 1ns / 1ps
module breakout(
    input wire disp, 
    input wire left, 
    input wire right, 
    input wire vga_clk,
    output wire hsync, 
    output wire vsync, 
    output wire [15:0] rgb, 
    output reg endGame  // 核心修改：改为reg类型，支持过程块赋值              
    );
    
    integer i, j, k, brickIndex;
    integer brW = 60, brH = 20;     
    integer pW = 64;                
    integer pH = 4;                 
    integer paddle_speed = 10;      
    integer ball_half_width = 4;    
    integer ball_half_height = 2;   
    integer ballSpeedX = 3'b100;    
    integer ballSpeedY = 3'b100;    
    
    integer left_border = 140;      
    integer right_border = 630;     
    integer top_border = 35;        
    integer bottom_border = 480;    
    
    wire inDispArea, border, ball, ballX, ballY, paddle, paddleX, paddleY;
    wire bouncingObject, resetFrame, brickCollision;
    wire[23:0] num;
    wire[9:0] cX, cY, gX, gY;
	 
    localparam RGB_BLACK     = 16'h0000;  
    localparam RGB_WHITE     = 16'hFFFF;  
    localparam RGB_RED       = 16'hF800;  
    localparam RGB_GREEN     = 16'h07E0;  
    localparam RGB_BLUE      = 16'h001F;  
    localparam RGB_YELLOW    = 16'hFFE0;  
    localparam RGB_CHECK1    = 16'h8410;  
    localparam RGB_CHECK2    = 16'h0088;  

    // 砖块状态数组
    reg brickX[0:31];
    reg brickY[0:31];
    
    reg[9:0] ballPX = 415;  
    reg[9:0] ballPY = 460;  
    reg[9:0] paddlePX = 415;
    reg[9:0] paddlePY = 468;
    
    reg[3:0] bricks = 4'b0;

    reg[9:0] brickPX[0:7], brickPY[0:3];
    reg[31:0] brickState = 32'hFFFFFFFF;
    reg[7:0] font0[7:0], font1[7:0], font2[7:0], font3[7:0], font4[7:0];
    reg[7:0] font5[7:0], font6[7:0], font7[7:0], font8[7:0], font9[7:0];

    reg bricksRow = 1'b1;
    
    reg collisionX1, collisionX2, collisionY1;
    reg collisionPaddle;           
    reg collisionBottom;            
    // 小球运动方向（0=右/下，1=左/上）
    reg ball_dirX = 0, ball_dirY = 1; 
    

    initial begin
        brickIndex = -1;  // 初始化砖块索引
        
        for(j=0; j<8; j=j+1) 
            brickPX[j] = left_border + 33 + 60*j;
        for(k=0; k<4; k=k+1) 
            brickPY[k] = top_border + 30 + 25*k;
        
        font0[0] = 8'b01111110; font0[1] = 8'b01000010;
        font0[2] = 8'b01000010; font0[3] = 8'b01000010;
        font0[4] = 8'b01000010; font0[5] = 8'b01000010;
        font0[6] = 8'b01000010; font0[7] = 8'b01111110;
    end
    
    always @(posedge num[0]) begin
        bricks <= 4'b0; // 修正：时序赋值<=
        for(i=24; i<32; i=i+1)
            bricksRow <= bricksRow & ~brickState[i]; // 修正：时序赋值<=
        
        for(i=0; i<32; i=i+1) begin
            j = i % 8;
            k = i / 8;
            if(brickState[i]) begin
                // 修正：砖块范围判断（无循环赋值）
                brickX[i] <= (cX >= brickPX[j] - brW/2) && (cX <= brickPX[j] + brW/2 - 1);
                brickY[i] <= (cY >= brickPY[k] - brH/2) && (cY <= brickPY[k] + brH/2 - 1);
                // 修正：时序块内位或赋值
                case(k)
                    0: bricks[0] <= bricks[0] | (brickX[i] & brickY[i]);
                    1: bricks[1] <= bricks[1] | (brickX[i] & brickY[i]);
                    2: bricks[2] <= bricks[2] | (brickX[i] & brickY[i]);
                    3: bricks[3] <= bricks[3] | (brickX[i] & brickY[i]);
                endcase
            end
        end
    end
    
    // 修正：clock改为vga_clk（模块输入是vga_clk，无clock端口）
    counter c(.clock(vga_clk), .out(num));
    syncGen generator(.clock(num[0]), .hsync(hsync), .vsync(vsync), 
                     .hcount(cX), .vcount(cY), .inDispArea(inDispArea));
    

    always @(posedge num[0]) begin
        if(resetFrame) begin
            collisionX1 <= 0; collisionX2 <= 0; collisionY1 <= 0;
        end else begin
            if(bouncingObject & (ballPX - ball_half_width <= left_border) & (cY == ballPY))
                collisionX1 <= 1;

            if(bouncingObject & (ballPX + ball_half_width >= right_border) & (cY == ballPY))
                collisionX2 <= 1;

            if(bouncingObject & (ballPY - ball_half_height <= top_border) & (cX == ballPX))
                collisionY1 <= 1;
        end
    end
    

    always @(posedge num[0]) begin
        if(resetFrame) begin  // 帧结束时清零碰撞标记
            collisionPaddle <= 0;
        end else if(bouncingObject & (ball_dirY == 0) &  // 检测挡板碰撞
                   (ballPY + ball_half_height >= paddlePY - pH/2) &
                   (ballPY - ball_half_height <= paddlePY + pH/2) & 
                   (ballPX + ball_half_width >= paddlePX - pW/2) & 
                   (ballPX - ball_half_width <= paddlePX + pW/2)) begin
            collisionPaddle <= 1;
        end
    end
    

    always @(posedge num[0]) begin
        if(resetFrame) begin
            collisionBottom <= 0;
        end else begin
            if(bouncingObject & (ballPY + ball_half_height >= bottom_border) & (cX == ballPX)) begin
                collisionBottom <= 1;
            end
        end
    end
    

    always @(posedge num[0]) begin
        if(brickCollision) begin
            for(i=0; i<32; i=i+1) begin
                if(brickX[i] & brickY[i]) brickIndex <= i;
            end
        end
        
        if(resetFrame) begin
            if(brickIndex != -1) begin
                brickState[brickIndex] <= 0;
                ball_dirY <= ~ball_dirY; 
                brickIndex <= -1;
            end
            
            if(collisionX1) begin 
                ball_dirX <= 0;
                ballPX <= left_border + ball_half_width + 1;
            end else if(collisionX2) begin 
                ball_dirX <= 1;
                ballPX <= right_border - ball_half_width - 1;
            end else begin 
                ballPX <= ballPX + (ball_dirX ? -ballSpeedX : ballSpeedX);
            end
            
            if(collisionPaddle) begin 
                ball_dirY <= 1; // Y轴方向改为向上
                ballPY <= paddlePY - pH/2 - ball_half_height; // 紧贴挡板上边界反弹
            end 
            else if(collisionY1) begin 
                ball_dirY <= 0;
                ballPY <= top_border + ball_half_height + 1;
            end 
            else if(collisionBottom) begin 
                endGame <= 1; // 此处赋值合法，因为endGame已定义为reg
            end 
            else begin 
                ballPY <= ballPY + (ball_dirY ? -ballSpeedY : ballSpeedY);
            end
            
            if(~left && (paddlePX - pW/2 > left_border)) begin
                paddlePX <= paddlePX - paddle_speed;
            end else if(~right && (paddlePX + pW/2 < right_border)) begin
                paddlePX <= paddlePX + paddle_speed;
            end
        end
    end
    
    assign brickCollision = |bricks & ball;
    assign bouncingObject = border | paddle | bricks;
    assign resetFrame = (cX==639) & (cY==479);
    assign border = (cX==left_border) | (cX==right_border) | 
                    (cY==top_border) | (cY==bottom_border);
    assign gX = cX; assign gY = cY;
    
    // 保留正确的范围判断赋值，删除重复的错误赋值
    assign ballX = (cX >= ballPX - ball_half_width) && (cX <= ballPX + ball_half_width);
    assign ballY = (cY >= ballPY - ball_half_height) && (cY <= ballPY + ball_half_height);
    assign ball = ballX & ballY;

    assign paddleX = (cX >= paddlePX - pW/2) && (cX <= paddlePX + pW/2 - 1);
    assign paddleY = (cY >= paddlePY - pH/2) && (cY <= paddlePY + pH/2 - 1);
    assign paddle = paddleX & paddleY;
    
    // 游戏RGB输出逻辑（修正后）
    assign rgb = endGame ? 
                 // 游戏结束：棋盘格（原cX[5]^cY[5]映射为两种对比色）
                 ((cX[5] ^ cY[5]) ? RGB_CHECK1 : RGB_CHECK2) : 
                 // 游戏中：按优先级赋值（小球 > 挡板 > 砖块 > 边界 > 背景）
                 (ball ? RGB_GREEN : 
                  (paddle ? RGB_YELLOW : 
                   (bricks[0] | bricks[3] ? RGB_RED : 
                    (bricks[1] ? RGB_GREEN : 
                     (bricks[2] ? RGB_BLUE : 
                      (border ? RGB_WHITE : RGB_BLACK))))));
endmodule