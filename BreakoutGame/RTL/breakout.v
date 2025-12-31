// Time unit: 1 nanosecond, Time precision: 1 picosecond
`timescale 1ns / 1ps

/**
 * Module: breakout
 * Function: Core logic for the classic Breakout (Brick Breaker) video game.
 *           Handles game state management, object (ball/paddle/brick) positioning,
 *           collision detection, user input processing, and graphics rendering for VGA output.
 * Port List:
 *   - Input:  left    - User input for moving paddle left (active low)
 *   - Input:  right   - User input for moving paddle right (active low)
 *   - Input:  fire1   - User input to start game with ball moving right (active low)
 *   - Input:  fire2   - User input to start game with ball moving left (active low)
 *   - Input:  clock   - Main system clock for game logic synchronization
 *   - Input:  rst_n   - Active low asynchronous reset (resets game to initial state)
 *   - Output: hsync   - VGA horizontal sync signal (passed through from syncGen module)
 *   - Output: vsync   - VGA vertical sync signal (passed through from syncGen module)
 *   - Output: r       - 1-bit red color channel for VGA graphics
 *   - Output: g       - 1-bit green color channel for VGA graphics
 *   - Output: b       - 1-bit blue color channel for VGA graphics
 *   - Output: endGame - High when game ends (ball hits bottom border)
 *   - Output: winGame - High when game is won (all bricks are destroyed)
 */
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
    // ------------------------------ Local Parameter Definitions (Game Constants) ------------------------------
    // Brick dimensions and positioning parameters
    localparam BRICK_WIDTH = 60;        // Horizontal size of each brick
    localparam BRICK_HEIGHT = 20;       // Vertical size of each brick
    localparam BRICK_GAP = 5;           // Gap between adjacent bricks
    localparam BRICK_OFFSET_X = 10;     // Horizontal offset for brick alignment
    localparam BRICK_OFFSET_Y = -10;    // Vertical offset for brick alignment
    
    // Paddle (player) dimensions and movement parameters
    localparam PADDLE_WIDTH = 64;       // Horizontal size of the paddle
    localparam PADDLE_HEIGHT = 4;       // Vertical size of the paddle
    localparam PADDLE_SPEED = 10;       // Horizontal movement speed of the paddle
    
    // Ball dimensions and movement parameters
    localparam BALL_HALF_WIDTH = 4;     // Half of the ball's horizontal size
    localparam BALL_HALF_HEIGHT = 2;    // Half of the ball's vertical size
    localparam BALL_SPEED_X = 3'b100;   // Horizontal movement speed of the ball (4 in decimal)
    localparam BALL_SPEED_Y = 3'b100;   // Vertical movement speed of the ball (4 in decimal)
    localparam BALL_INIT_Y = 466;       // Initial vertical position of the ball
    localparam BALL_INIT_X = 415;       // Initial horizontal position of the ball
    
    // Game screen border parameters (visible area boundaries)
    localparam LEFT_BORDER = 140;       // Left screen boundary (paddle/ball cannot cross)
    localparam RIGHT_BORDER = 680;      // Right screen boundary (paddle/ball cannot cross)
    localparam TOP_BORDER = 35;         // Top screen boundary (ball cannot cross)
    localparam BOTTOM_BORDER = 480;     // Bottom screen boundary (ball crossing ends game)
    
    // Ball and paddle initial direction/position parameters
    localparam BALL_INIT_DIR_X = 1'b1;  // Initial horizontal direction of ball (1 = left, 0 = right)
    localparam BALL_INIT_DIR_Y = 1'b0;  // Initial vertical direction of ball (1 = up, 0 = down)
    localparam PADDLE_INIT_X = 415;     // Initial horizontal position of the paddle
    localparam PADDLE_INIT_Y = 468;     // Initial vertical position of the paddle

    // Game state machine parameters
    localparam GAME_STATE_START = 1'b0; // Game state: Start screen (waiting for user input)
    localparam GAME_STATE_RUN = 1'b1;   // Game state: Active game play (running)

    // ------------------------------ Internal Variable/Signal Declarations ------------------------------
    // Loop iteration variables and brick collision index
    integer i, j, k;
    integer brickIndex = -1;            // Index of the brick hit by the ball (-1 = no collision)
    
    // Graphics and game logic status wires
    wire inDispArea, border, ball, ballX, ballY, paddle, paddleX, paddleY;
    wire bouncingObject, resetFrame, brickCollision;
    wire[23:0] num;                     // 24-bit counter value from counter module
    wire[9:0] cX, cY, gX, gY;           // VGA pixel coordinates (horizontal/vertical)
 
    // Brick position registers (array for multiple bricks)
    reg brickX[0:31];                   // Horizontal position flag for each brick (0-31)
    reg brickY[0:31];                   // Vertical position flag for each brick (0-31)
    
    // Ball and paddle current position registers
    reg[9:0] ballPX = BALL_INIT_X;      // Current horizontal position of the ball
    reg[9:0] ballPY = BALL_INIT_Y;      // Current vertical position of the ball
    reg[9:0] paddlePX = PADDLE_INIT_X;  // Current horizontal position of the paddle
    reg[9:0] paddlePY = PADDLE_INIT_Y;  // Current vertical position of the paddle
    
    // Game state control registers
    reg game_state = GAME_STATE_START;  // Current game state (start/running)
    reg game_started = 1'b0;            // Flag indicating if game play has started (ball in motion)
    
    // Brick status registers
    reg[3:0] bricks = 4'b0;             // Composite brick render flag (4 rows of bricks)
    reg[9:0] brickPX[0:7] = '{          // Initial horizontal position of bricks (8 bricks per row)
        140+33+(BRICK_WIDTH+BRICK_GAP)*0 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*1 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*2 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*3 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*4 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*5 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*6 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*7 + BRICK_OFFSET_X
    };
    reg[9:0] brickPY[0:3] = '{          // Initial vertical position of bricks (4 rows total)
        35+30+25*0 + BRICK_OFFSET_Y, 35+30+25*1 + BRICK_OFFSET_Y,
        35+30+25*2 + BRICK_OFFSET_Y, 35+30+25*3 + BRICK_OFFSET_Y
    };
    reg[31:0] brickState = 32'hFFFFFFFF;// Brick active state (1 = active, 0 = destroyed; 32 bricks total)
    reg bricksRow = 1'b1;               // Flag for checking if a row of bricks is destroyed
    
    // Collision detection registers
    reg collisionX1 = 1'b0, collisionX2 = 1'b0, collisionY1 = 1'b0;
    reg collisionPaddle = 1'b0;          // Flag for ball-paddle collision
    reg collisionBottom = 1'b0;          // Flag for ball hitting bottom border (game over)
    
    // Ball direction control registers
    reg ball_dirX = BALL_INIT_DIR_X;    // Current horizontal direction of the ball
    reg ball_dirY = BALL_INIT_DIR_Y;    // Current vertical direction of the ball
    
    // Win screen animation registers
    reg flash_en = 1'b0;                // Flag for enabling win screen border flash
    reg[9:0] light_x = LEFT_BORDER;     // Horizontal position of win screen animation light

    // Start screen graphics wires
    wire start_screen_border;
    wire start_screen_text;
    wire start_screen_bg;

    // ------------------------------ Start Screen Graphics Assignments ------------------------------
    assign start_screen_border = inDispArea & ((cX == LEFT_BORDER - 20) | (cX == RIGHT_BORDER + 20) | 
                                              (cY == TOP_BORDER - 20) | (cY == BOTTOM_BORDER + 20));
    assign start_screen_text = inDispArea & (cX >= 250 && cX <= 550) & (cY >= 200 && cY <= 220)
                            | inDispArea & (cX >= 250 && cX <= 550) & (cY >= 230 && cY <= 250);
    assign start_screen_bg = inDispArea & (cX > LEFT_BORDER - 20 && cX < RIGHT_BORDER + 20) 
                            & (cY > TOP_BORDER - 20 && cY < BOTTOM_BORDER + 20) & ~start_screen_text & ~start_screen_border;
    
    // ------------------------------ Game State Machine Logic ------------------------------
    /**
     * Sequential Logic: Game State Control
     * Triggered by clock positive edge or asynchronous active low reset.
     * Manages transitions between start screen and active game play, and handles game reset.
     */
    always @(posedge clock or negedge rst_n) begin
        if(game_state == GAME_STATE_START) begin
            // Transition from start screen to active game when left button is pressed
            if(~left) begin
                game_state <= GAME_STATE_RUN;
            end
        end
        else if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: restore all game objects to initial state
            if(!rst_n) begin
                ballPX <= BALL_INIT_X;
                ballPY <= BALL_INIT_Y;
                paddlePX <= PADDLE_INIT_X;
                paddlePY <= PADDLE_INIT_Y;
                
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
                
                // Restore initial brick positions
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
                
                // Restore initial ball direction and win animation state
                ball_dirX <= BALL_INIT_DIR_X;
                ball_dirY <= BALL_INIT_DIR_Y;
                flash_en <= 1'b0;
                light_x <= LEFT_BORDER;
                
                game_state <= GAME_STATE_RUN;
            end
            else begin
                // Restore first brick if it was incorrectly destroyed
                if(brickState[0] == 1'b0 && !brickCollision && !resetFrame) begin
                    brickState[0] <= 1'b1;
                end
                
                // Set winGame flag when all bricks are destroyed (brickState all 0s)
                if(brickState == 32'h0 && !endGame) begin
                    winGame <= 1'b1;
                end
                
                // Win screen animation: control border flash based on counter value
                if(winGame) begin
                    if(num[17] == 1'b1) begin
                        flash_en <= 1'b1;
                    end else begin
                        flash_en <= 1'b0;
                    end
                    
                    // Animate the horizontal light bar on win screen
                    if(resetFrame) begin
                        light_x <= (light_x >= RIGHT_BORDER) ? LEFT_BORDER : light_x + 2;
                    end
                end
                
                // Game start logic: launch ball with fire1 (right) or fire2 (left)
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
    
    // ------------------------------ Brick Rendering Logic ------------------------------
    /**
     * Sequential Logic: Brick Graphics Generation
     * Triggered on the positive edge of the 0th bit of the 24-bit counter.
     * Renders active bricks by setting position flags for VGA output.
     */
    always @(posedge num[0]) begin
        if(game_state == GAME_STATE_RUN) begin
            bricks = 4'b0;
            // Check if the last row of bricks is destroyed
            for(i=24; i<32; i=i+1)
                bricksRow = bricksRow & ~brickState[i];
            
            // Iterate over all 32 bricks to set their position flags (active bricks only)
            for(i=0; i<32; i=i+1) begin
                j = i % 8;    // Column index of the brick (0-7)
                k = i / 8;    // Row index of the brick (0-3)
                if(brickState[i]) begin
                    if(i == 0 || i == 1) begin
                        brickX[i] = (cX >= brickPX[j] - BRICK_WIDTH/2) && (cX <= brickPX[j] + BRICK_WIDTH/2 - 1) ? 1'b1 : 1'b0;
                        brickY[i] = (cY >= brickPY[k] - BRICK_HEIGHT/2) && (cY <= brickPY[k] + BRICK_HEIGHT/2 - 1) ? 1'b1 : 1'b0;
                    end else begin
                        brickX[i] = (cX == brickPX[j] - BRICK_WIDTH/2) ? 1 : (cX == brickPX[j] + BRICK_WIDTH/2 - 1) ? 0 : brickX[i];
                        brickY[i] = (cY == brickPY[k] - BRICK_HEIGHT/2) ? 1 : (cY == brickPY[k] + BRICK_HEIGHT/2 - 1) ? 0 : brickY[i];
                    end
                    // Set composite brick flag for each row
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
    
    // ------------------------------ Module Instantiations ------------------------------
    // Instantiate 24-bit counter for timing and animation control
    counter c(.clock(clock), .out(num));
    // Instantiate VGA sync signal generator for graphics rendering
    syncGen generator(.clock(num[0]), .hsync(hsync), .vsync(vsync), 
                     .hcount(cX), .vcount(cY), .inDispArea(inDispArea));
    
    // ------------------------------ Boundary Collision Detection ------------------------------
    /**
     * Sequential Logic: Ball-Boundary Collision Detection (Horizontal/Top)
     * Triggered by counter bit 0 positive edge or asynchronous active low reset.
     * Detects ball collisions with left, right, and top screen borders.
     */
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
            if(!rst_n) begin
                collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
            end else if(resetFrame) begin
                // Reset collision flags at the end of each frame
                collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
            end else begin
                // Left border collision (ball hits LEFT_BORDER)
                if(game_started && bouncingObject & (ballPX - BALL_HALF_WIDTH <= LEFT_BORDER) & (cY == ballPY))
                    collisionX1 <= 1'b1;

                // Right border collision (ball hits RIGHT_BORDER)
                if(game_started && bouncingObject & (ballPX + BALL_HALF_WIDTH >= RIGHT_BORDER) & (cY == ballPY))
                    collisionX2 <= 1'b1;

                // Top border collision (ball hits TOP_BORDER)
                if(game_started && bouncingObject & (ballPY - BALL_HALF_HEIGHT <= TOP_BORDER) & (cX == ballPX))
                    collisionY1 <= 1'b1;
            end
        end
    end
    
    // ------------------------------ Paddle Collision Detection ------------------------------
    /**
     * Sequential Logic: Ball-Paddle Collision Detection
     * Triggered by counter bit 0 positive edge or asynchronous active low reset.
     * Detects when the ball collides with the player's paddle.
     */
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
            if(!rst_n) begin
                collisionPaddle <= 1'b0;
            end else if(resetFrame) begin
                // Reset paddle collision flag at the end of each frame
                collisionPaddle <= 1'b0;
            end else if(game_started && bouncingObject & (ball_dirY == 1'b0) & 
                       (ballPY + BALL_HALF_HEIGHT >= paddlePY - PADDLE_HEIGHT/2) &
                       (ballPY - BALL_HALF_HEIGHT <= paddlePY + PADDLE_HEIGHT/2) & 
                       (ballPX + BALL_HALF_WIDTH >= paddlePX - PADDLE_WIDTH/2) & 
                       (ballPX - BALL_HALF_WIDTH <= paddlePX + PADDLE_WIDTH/2)) begin
                // Set collision flag when ball is within paddle boundaries
                collisionPaddle <= 1'b1;
            end
        end
    end
    
    // ------------------------------ Bottom Border Collision (Game Over) ------------------------------
    /**
     * Sequential Logic: Ball-Bottom Border Collision Detection
     * Triggered by counter bit 0 positive edge or asynchronous active low reset.
     * Detects when the ball hits the bottom border (triggers game over).
     */
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
            if(!rst_n) begin
                collisionBottom <= 1'b0;
            end else if(resetFrame) begin
                // Reset bottom collision flag at the end of each frame
                collisionBottom <= 1'b0;
            end else begin
                // Bottom border collision (triggers game over)
                if(game_started && bouncingObject & (ballPY + BALL_HALF_HEIGHT >= BOTTOM_BORDER) & (cX == ballPX)) begin
                    collisionBottom <= 1'b1;
                end
            end
        end
    end
    
    // ------------------------------ Object Movement and Collision Response ------------------------------
    /**
     * Sequential Logic: Game Object Update (Ball/Paddle/Bricks)
     * Triggered by counter bit 0 positive edge or asynchronous active low reset.
     * Updates object positions, handles collision responses, and manages brick destruction.
     */
    always @(posedge num[0] or negedge rst_n) begin
        if(game_state == GAME_STATE_RUN) begin
            if(!rst_n) begin
                brickIndex <= -1;
            end else begin
                // Identify the brick hit by the ball (if any collision)
                if(brickCollision) begin
                    brickIndex <= -1;
                    for(i=0; i<32; i=i+1) begin
                        if(brickX[i] & brickY[i]) begin
                            brickIndex <= i;
                            break;
                        end
                    end
                end
                
                // Update object states at the end of each frame (resetFrame)
                if(resetFrame) begin
                    // Brick destruction: mark hit brick as destroyed and reverse ball vertical direction
                    if(game_started && brickIndex >= 0 && brickIndex < 32) begin
                        brickState[brickIndex] <= 1'b0;
                        ball_dirY <= ~ball_dirY;
                        brickIndex <= -1;
                    end
                    
                    // Paddle/ball movement before game starts (ball locked to paddle)
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
                    
                    // Active game play: update ball and paddle positions based on collisions
                    else if(game_started && !winGame && !endGame) begin
                        // Update ball horizontal position and direction (border collisions)
                        if(collisionX1) begin 
                            ball_dirX <= 1'b0;
                            ballPX <= LEFT_BORDER + BALL_HALF_WIDTH + BALL_SPEED_X;
                        end else if(collisionX2) begin 
                            ball_dirX <= 1'b1;
                            ballPX <= RIGHT_BORDER - BALL_HALF_WIDTH - BALL_SPEED_X;
                        end else begin 
                            ballPX <= ballPX + (ball_dirX ? -BALL_SPEED_X : BALL_SPEED_X);
                        end
                        
                        // Update ball vertical position and direction (paddle/top border collisions)
                        if(collisionPaddle) begin 
                            ball_dirY <= 1'b1;
                            ballPY <= paddlePY - PADDLE_HEIGHT/2 - BALL_HALF_HEIGHT - 1;
                        end 
                        else if(collisionY1) begin 
                            ball_dirY <= 1'b0;
                            ballPY <= TOP_BORDER + BALL_HALF_HEIGHT + BALL_SPEED_Y;
                        end 
                        else if(collisionBottom) begin 
                            endGame <= 1'b1; // Game over: ball hit bottom border
                        end 
                        else begin
                            ballPY <= ballPY + (ball_dirY ? -BALL_SPEED_Y : BALL_SPEED_Y);
                        end
                        
                        // Update paddle position (user input, boundary constrained)
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
    
    // ------------------------------ Graphics Signal Assignments ------------------------------
    assign ballX = (cX == ballPX - BALL_HALF_WIDTH) ? 1'b1 : (cX == ballPX + BALL_HALF_WIDTH) ? 1'b0 : ballX;
    assign brickCollision = |bricks & ball;  // Detect ball-brick collision
    assign bouncingObject = border | paddle | bricks;  // All objects that the ball can bounce off
    assign resetFrame = (cX==639) & (cY==479);  // End of frame trigger (VGA vertical blanking start)
    assign border = (cX==LEFT_BORDER) | (cX==RIGHT_BORDER) |  // Screen border graphics
                    (cY==TOP_BORDER) | (cY==BOTTOM_BORDER);
    assign gX = cX; assign gY = cY;  // Alias for pixel coordinates
    assign ballY = (cY == ballPY - BALL_HALF_HEIGHT) ? 1'b1 : (cY == ballPY + BALL_HALF_HEIGHT) ? 1'b0 : ballY;
    assign ball = ballX & ballY;  // Composite ball graphics flag
    assign paddleX = (cX == paddlePX - PADDLE_WIDTH/2) ? 1'b1 : (cX == paddlePX + PADDLE_WIDTH/2 - 1) ? 1'b0 : paddleX;
    assign paddleY = (cY == paddlePY - PADDLE_HEIGHT/2) ? 1'b1 : (cY == paddlePY + PADDLE_HEIGHT/2 - 1) ? 1'b0 : paddleY;
    assign paddle = paddleX & paddleY;  // Composite paddle graphics flag
    
    // Win screen graphics assignments
    wire win_border, win_light;
    assign win_border = flash_en & inDispArea & ((cX == LEFT_BORDER) | (cX == RIGHT_BORDER) | (cY == TOP_BORDER) | (cY == BOTTOM_BORDER));
    assign win_light = inDispArea & (cX == light_x) & (cY >= (TOP_BORDER + BOTTOM_BORDER)/2 - 10) & (cY <= (TOP_BORDER + BOTTOM_BORDER)/2 + 10);
    
    // ------------------------------ VGA Color Channel Assignments ------------------------------
    /**
     * Combinational Logic: VGA Red/Green/Blue Color Channel Control
     * Selects graphics output based on game state (start screen/active play/win/loss).
     */
    assign r = (game_state == GAME_STATE_START) ? (start_screen_border | start_screen_text) 
              : (winGame ? (win_border | win_light) : (endGame ? (cX[5] ^ cY[5]) : (border | bricks[0] | bricks[3] | paddle)));
    assign g = (game_state == GAME_STATE_START) ? start_screen_bg 
              : (winGame ? (win_light) : (endGame ? (cX[4] ^ cY[4]) : (border | bricks[1] | bricks[3] | paddle | ball)));
    assign b = (game_state == GAME_STATE_START) ? start_screen_border 
              : (winGame ? (win_border) : (endGame ? (cX[3] ^ cY[3]) : (border | bricks[2] | paddle | ball)));
endmodule
