`timescale 1ns / 1ps
module breakout(
    input left,
    input right, 
    input fire1,
    input fire2,
    input clock, 
    input rst_n,
    output hsync, 
    output vsync, 
    output r, 
    output g, 
    output b,
    output reg endGame,
    output reg winGame
);
    localparam BRICK_WIDTH = 60;
    localparam BRICK_HEIGHT = 20;
    localparam BRICK_GAP = 5;
    localparam BRICK_OFFSET_X = 10;
    localparam BRICK_OFFSET_Y = -10;
    
    localparam PADDLE_WIDTH = 64;
    localparam PADDLE_HEIGHT = 4;
    localparam PADDLE_SPEED = 10;
    
    localparam BALL_HALF_WIDTH = 4;
    localparam BALL_HALF_HEIGHT = 2;
    localparam BALL_SPEED_X = 3'b100;
    localparam BALL_SPEED_Y = 3'b100;
    localparam BALL_INIT_Y = 466;
    localparam BALL_INIT_X = 415;
    
    localparam LEFT_BORDER = 140;
    localparam RIGHT_BORDER = 680;
    localparam TOP_BORDER = 35;
    localparam BOTTOM_BORDER = 480;
    
    localparam BALL_INIT_DIR_X = 1'b1;
    localparam BALL_INIT_DIR_Y = 1'b0;
    localparam PADDLE_INIT_X = 415;
    localparam PADDLE_INIT_Y = 468;

    localparam GAME_STATE_START = 1'b0;
    localparam GAME_STATE_RUN = 1'b1;

    integer i, j, k;
    integer brickIndex = -1;
    
    wire inDispArea, border, ball, ballX, ballY, paddle, paddleX, paddleY;
    wire bouncingObject, resetFrame, brickCollision;
    wire[23:0] num;
    wire[9:0] cX, cY, gX, gY;
 
    reg brickX[0:31];
    reg brickY[0:31];
    
    reg[9:0] ballPX = BALL_INIT_X;  
    reg[9:0] ballPY = BALL_INIT_Y;  
    reg[9:0] paddlePX = PADDLE_INIT_X;
    reg[9:0] paddlePY = PADDLE_INIT_Y;
    
    reg game_state = GAME_STATE_START;
    reg game_started = 1'b0;
    
    reg[3:0] bricks = 4'b0;

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
    
    reg[31:0] brickState = 32'hFFFFFFFF;

    reg bricksRow = 1'b1;
    
    reg collisionX1 = 1'b0, collisionX2 = 1'b0, collisionY1 = 1'b0;
    reg collisionPaddle = 1'b0;           
    reg collisionBottom = 1'b0;            
    
    reg ball_dirX = BALL_INIT_DIR_X;
    reg ball_dirY = BALL_INIT_DIR_Y;
    
    reg flash_en = 1'b0;
    reg[9:0] light_x = LEFT_BORDER;

    wire start_screen_border;
    wire start_screen_text;
    wire start_screen_bg;

    assign start_screen_border = inDispArea & ((cX == LEFT_BORDER - 20) | (cX == RIGHT_BORDER + 20) | 
                                              (cY == TOP_BORDER - 20) | (cY == BOTTOM_BORDER + 20));

    assign start_screen_text = inDispArea & (cX >= 250 && cX <= 550) & (cY >= 200 && cY <= 220)
                            | inDispArea & (cX >= 250 && cX <= 550) & (cY >= 230 && cY <= 250);

    assign start_screen_bg = inDispArea & (cX > LEFT_BORDER - 20 && cX < RIGHT_BORDER + 20) 
                            & (cY > TOP_BORDER - 20 && cY < BOTTOM_BORDER + 20) & ~start_screen_text & ~start_screen_border;
    
    always @(posedge clock or negedge rst_n) begin
        if(game_state == GAME_STATE_START) begin
            if(~left) begin
                game_state <= GAME_STATE_RUN;
            end
        end
        else if(game_state == GAME_STATE_RUN) begin
            if(!rst_n) begin
                ballPX <= BALL_INIT_X;
                ballPY <= BALL_INIT_Y;
                paddlePX <= PADDLE_INIT_X;
                paddlePY <= PADDLE_INIT_Y;
                
                brickState <= 32'hFFFFFFFF;
                
                endGame <= 1'b0;
                winGame <= 1'b0;
                game_started <= 1'b0;
                bricksRow <= 1'b1;
                
                collisionX1 <= 1'b0;
                collisionX2 <= 1'b0;
                collisionY1 <= 1'b0;
                collisionPaddle <= 1'b0;
                collisionBottom <= 1'b0;
                brickIndex <= -1;
                
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
                
                ball_dirX <= BALL_INIT_DIR_X;
                ball_dirY <= BALL_INIT_DIR_Y;
                
                flash_en <= 1'b0;
                light_x <= LEFT_BORDER;
                
                game_state <= GAME_STATE_RUN;
            end
            else begin
                if(brickState[0] == 1'b0 && !brickCollision && !resetFrame) begin
                    brickState[0] <= 1'b1;
                end
                
                if(brickState == 32'h0 && !endGame) begin
                    winGame <= 1'b1;
                end
                
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
    end
    
    always @(posedge num[0]) begin
        if(game_state == GAME_STATE_RUN) begin
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
    end
    
    counter c(.clock(clock), .out(num));
    syncGen generator(.clock(num[0]), .hsync(hsync), .vsync(vsync), 
                     .hcount(cX), .vcount(cY), .inDispArea(inDispArea));
    
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
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
    end
    
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
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
    end
    
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
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
    end
    
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
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
                    if(game_started && brickIndex >= 0 && brickIndex < 32) begin
                        brickState[brickIndex] <= 1'b0;
                        ball_dirY <= ~ball_dirY;
                        brickIndex <= -1;
                    end
                    
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
                    
                    else if(game_started && !winGame && !endGame) begin
                        if(collisionX1) begin 
                            ball_dirX <= 1'b0;
                            ballPX <= LEFT_BORDER + BALL_HALF_WIDTH + BALL_SPEED_X;
                        end else if(collisionX2) begin 
                            ball_dirX <= 1'b1;
                            ballPX <= RIGHT_BORDER - BALL_HALF_WIDTH - BALL_SPEED_X;
                        end else begin 
                            ballPX <= ballPX + (ball_dirX ? -BALL_SPEED_X : BALL_SPEED_X);
                        end
                        
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
                        
                        if(~left && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin
                            paddlePX <= paddlePX - PADDLE_SPEED;
                        end else if(~right && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin
                            paddlePX <= paddlePX + PADDLE_SPEED;
                        end
                    end
                end
            end
        end
    end
    
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
    
    wire win_border, win_light;
    assign win_border = flash_en & inDispArea & ((cX == LEFT_BORDER) | (cX == RIGHT_BORDER) | (cY == TOP_BORDER) | (cY == BOTTOM_BORDER));
    assign win_light = inDispArea & (cX == light_x) & (cY >= (TOP_BORDER + BOTTOM_BORDER)/2 - 10) & (cY <= (TOP_BORDER + BOTTOM_BORDER)/2 + 10);
    
    assign r = (game_state == GAME_STATE_START) ? (start_screen_border | start_screen_text) 
              : (winGame ? (win_border | win_light) : (endGame ? (cX[5] ^ cY[5]) : (border | bricks[0] | bricks[3] | paddle)));
    assign g = (game_state == GAME_STATE_START) ? start_screen_bg 
              : (winGame ? (win_light) : (endGame ? (cX[4] ^ cY[4]) : (border | bricks[1] | bricks[3] | paddle | ball)));
    assign b = (game_state == GAME_STATE_START) ? start_screen_border 
              : (winGame ? (win_border) : (endGame ? (cX[3] ^ cY[3]) : (border | bricks[2] | paddle | ball)));
endmodule


