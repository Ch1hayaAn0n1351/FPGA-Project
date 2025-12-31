// Time unit: 1 nanosecond, Time precision: 1 picosecond
// Ensures accurate simulation timing for digital logic and VGA video signals
`timescale 1ns / 1ps

/**
 * Module: breakout
 * Core Function: Implements the full logic of the classic Breakout (Brick Breaker) arcade game,
 *                specifically optimized for VGA 640x480 video output. This module integrates
 *                4 key subsystems: 1) Game state management (start/running/win/loss),
 *                2) Object kinematics (ball/paddle movement, boundary constraints),
 *                3) Collision detection (ball vs brick/paddle/borders),
 *                4) VGA graphics rendering (pixel-level drawing for game objects and UI states).
 * 
 * Key Features:
 *  - Asynchronous active-low reset for full game state restoration
 *  - Active-low user inputs (compatible with physical development board buttons, debounce-free)
 *  - 32 bricks (4 rows × 8 columns) with individual active state tracking
 *  - Win/loss condition detection and corresponding visual feedback
 *  - Ball paddle locking (before game start) for improved player aiming experience
 *  - VGA sync signal passthrough and 1-bit RGB color channel generation
 * 
 * Port List (Detailed):
 *   - Input:  left    - Active low user input for paddle left movement.
 *                       Only effective when game is in start state or running state (non-win/loss).
 *   - Input:  right   - Active low user input for paddle right movement.
 *                       Boundary-constrained to prevent paddle from exiting game area.
 *   - Input:  fire1   - Active low user input to launch ball (initial direction: right-up).
 *                       Triggers game start only when game is in idle (non-started, non-win/loss) state.
 *   - Input:  fire2   - Active low user input to launch ball (initial direction: left-up).
 *                       Alternative launch direction for player flexibility.
 *   - Input:  clock   - Main system clock (typically VGA pixel clock or divided system clock)
 *                       for synchronizing all sequential game logic and graphics rendering.
 *   - Input:  rst_n   - Active low asynchronous reset. Immediately restores all game objects,
 *                       state flags, and graphics to initial values without waiting for clock edge.
 *   - Output: hsync   - VGA horizontal sync signal (passthrough from syncGen module).
 *                       Follows standard VGA 640x480 timing (low-active pulse).
 *   - Output: vsync   - VGA vertical sync signal (passthrough from syncGen module).
 *                       Follows standard VGA 640x480 timing (low-active pulse).
 *   - Output: r       - 1-bit red color channel for VGA display. Determines red pixel intensity
 *                       (0 = off, 1 = full on) based on current game state and object position.
 *   - Output: g       - 1-bit green color channel for VGA display. Complementary to red/blue
 *                       for distinguishing game objects (e.g., ball, paddle, bricks).
 *   - Output: b       - 1-bit blue color channel for VGA display. Used for UI elements (e.g.,
 *                       start screen border, win screen flash) and game boundaries.
 *   - Output: endGame - Active high flag indicating game over (ball has hit the bottom border).
 *                       Remains high until asynchronous reset is triggered.
 *   - Output: winGame - Active high flag indicating game victory (all 32 bricks have been destroyed).
 *                       Triggers win screen animation and remains high until reset.
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
    // ------------------------------ Local Parameter Definitions (Game & VGA Constants) ------------------------------
    // Parameter design principle: All constants are defined here for easy game tuning and maintenance
    // No hard-coded values in logic blocks to simplify future modifications (e.g., brick size, ball speed)

    // Brick dimensions and positioning parameters (4 rows × 8 columns = 32 bricks total)
    localparam BRICK_WIDTH = 60;        // Horizontal pixel width of each individual brick
                                        // Chosen to fit 8 bricks across the game area with gaps
    localparam BRICK_HEIGHT = 20;       // Vertical pixel height of each individual brick
                                        // Balanced with brick width for visual proportionality
    localparam BRICK_GAP = 5;           // Horizontal/vertical pixel gap between adjacent bricks
                                        // Prevents brick overlap and improves visual clarity
    localparam BRICK_OFFSET_X = 10;     // Horizontal calibration offset for brick row alignment
                                        // Adjusts to center brick grid within game boundaries
    localparam BRICK_OFFSET_Y = -10;    // Vertical calibration offset for brick row alignment
                                        // Fine-tunes brick grid position to avoid top border overlap
    
    // Paddle (player-controlled) dimensions and movement parameters
    localparam PADDLE_WIDTH = 64;       // Horizontal pixel width of the paddle
                                        // Balanced with brick width for reasonable ball deflection
    localparam PADDLE_HEIGHT = 4;       // Vertical pixel height of the paddle
                                        // Thin enough to challenge players, thick enough to catch the ball
    localparam PADDLE_SPEED = 10;       // Horizontal pixel movement speed of the paddle per clock cycle
                                        // Tuned for smooth, responsive player control without being overly fast
    
    // Ball dimensions and movement parameters (half-size used for simplified collision detection)
    localparam BALL_HALF_WIDTH = 4;     // Half of the ball's horizontal pixel width (full width = 8)
                                        // Simplifies boundary and object collision calculations
    localparam BALL_HALF_HEIGHT = 2;    // Half of the ball's vertical pixel height (full height = 4)
                                        // Matches paddle height for consistent collision logic
    localparam BALL_SPEED_X = 3'b100;   // Horizontal pixel speed of the ball (4 in decimal, 3-bit binary)
                                        // Binary representation for easy speed scaling (left/right shift) in future
    localparam BALL_SPEED_Y = 3'b100;   // Vertical pixel speed of the ball (4 in decimal, 3-bit binary)
                                        // Matches horizontal speed for balanced ball movement
    localparam BALL_INIT_Y = 466;       // Initial vertical pixel position of the ball
                                        // Positioned just above the paddle (pre-game lock state)
    localparam BALL_INIT_X = 415;       // Initial horizontal pixel position of the ball
                                        // Centered on the initial paddle position for symmetry
    
    // Game screen boundary parameters (visible game area, within VGA 640x480 display)
    localparam LEFT_BORDER = 140;       // Left horizontal boundary of the playable game area
                                        // Prevents paddle/ball from exiting the left side of the brick grid
    localparam RIGHT_BORDER = 680;      // Right horizontal boundary of the playable game area
                                        // Prevents paddle/ball from exiting the right side of the brick grid
    localparam TOP_BORDER = 35;         // Top vertical boundary of the playable game area
                                        // Stops the ball from moving above the brick grid
    localparam BOTTOM_BORDER = 480;     // Bottom vertical boundary of the playable game area
                                        // Ball crossing this boundary triggers game over (endGame = 1)
    
    // Ball and paddle initial direction/position parameters (direction: 1 = negative axis, 0 = positive axis)
    localparam BALL_INIT_DIR_X = 1'b1;  // Initial horizontal direction of the ball (1 = left, 0 = right)
                                        // Default direction set to left for fire2 compatibility
    localparam BALL_INIT_DIR_Y = 1'b0;  // Initial vertical direction of the ball (1 = up, 0 = down)
                                        // Default direction set to down (only active post-game start)
    localparam PADDLE_INIT_X = 415;     // Initial horizontal pixel position of the paddle
                                        // Centered within the game area for balanced initial player position
    localparam PADDLE_INIT_Y = 468;     // Initial vertical pixel position of the paddle
                                        // Positioned just above the bottom border (safe zone for players)

    // Game state machine parameters (2-state finite state machine for simplicity)
    localparam GAME_STATE_START = 1'b0; // Game state: Start screen (idle, waiting for user input)
                                        // Displays start UI and waits for left button to enter run state
    localparam GAME_STATE_RUN = 1'b1;   // Game state: Active game play (running, all logic enabled)
                                        // Enables movement, collision detection, and brick destruction

    // ------------------------------ Internal Variable/Signal Declarations ------------------------------
    // Loop iteration variables (for brick array traversal and collision detection)
    integer i, j, k;                    // i = total brick index (0-31), j = brick column index (0-7), k = brick row index (0-3)
    integer brickIndex = -1;            // Index of the brick hit by the ball (-1 = no brick collision detected)
                                        // Updated during collision detection, reset after brick destruction

    // Graphics and game logic status wires (combinational signals, no sequential storage)
    wire inDispArea;                    // Active high when current pixel is within VGA visible display area
                                        // Passthrough from syncGen module, used to mask off-screen pixels
    wire border;                        // Active high when current pixel is part of the game area border
                                        // Used for rendering game boundaries and collision detection
    wire ball, ballX, ballY;            // Ball graphics signals: ballX (horizontal pixel flag), ballY (vertical pixel flag)
                                        // ball = ballX & ballY (composite flag for ball pixel rendering)
    wire paddle, paddleX, paddleY;      // Paddle graphics signals: paddleX (horizontal pixel flag), paddleY (vertical pixel flag)
                                        // paddle = paddleX & paddleY (composite flag for paddle pixel rendering)
    wire bouncingObject;                // Active high when current pixel is part of a bounceable object (border/paddle/brick)
                                        // Used to filter valid ball collision targets (ignore background)
    wire resetFrame;                    // Active high at the end of a VGA frame (cX=639, cY=479)
                                        // Triggers object position updates and collision flag resets (frame synchronization)
    wire brickCollision;                // Active high when the ball collides with an active brick
                                        // Triggers brick destruction and ball vertical direction reversal
    wire[23:0] num;                     // 24-bit counter value from counter module (timing and animation control)
                                        // Used for win screen flash animation and sub-clock logic triggering
    wire[9:0] cX, cY, gX, gY;           // 10-bit VGA pixel coordinates (cX=horizontal, cY=vertical)
                                        // cX/cY = raw pixel counters from syncGen; gX/gY = aliases for graphics rendering

    // Brick position registers (1-bit array flags for pixel-level brick rendering, 0-31 = 32 bricks)
    reg brickX[0:31];                   // Horizontal pixel flag for each brick (1 = within brick horizontal range)
                                        // Updated per pixel clock to mark brick horizontal boundaries
    reg brickY[0:31];                   // Vertical pixel flag for each brick (1 = within brick vertical range)
                                        // Updated per pixel clock to mark brick vertical boundaries
    
    // Ball and paddle current position registers (10-bit for VGA 640x480 compatibility, non-blocking assignment)
    reg[9:0] ballPX = BALL_INIT_X;      // Current horizontal pixel position of the ball's center
                                        // Updated per frame (resetFrame) based on direction and collisions
    reg[9:0] ballPY = BALL_INIT_Y;      // Current vertical pixel position of the ball's center
                                        // Updated per frame (resetFrame) based on direction and collisions
    reg[9:0] paddlePX = PADDLE_INIT_X;  // Current horizontal pixel position of the paddle's center
                                        // Updated per frame (resetFrame) based on user input and boundaries
    reg[9:0] paddlePY = PADDLE_INIT_Y;  // Current vertical pixel position of the paddle's center
                                        // Fixed (no vertical movement) - only horizontal control for players
    
    // Game state control registers (1-bit flags for state machine and game flow)
    reg game_state = GAME_STATE_START;  // Current game state (start/running) - initialized to start screen
                                        // Transitions to run state on left button press (active low)
    reg game_started = 1'b0;            // Flag indicating if game play has started (ball in motion, not locked to paddle)
                                        // Set high on fire1/fire2 press, low on reset

    // Brick status registers (array and composite flags for rendering and collision)
    reg[3:0] bricks = 4'b0;             // Composite brick render flag (4 bits = 4 brick rows, 1 = row has active bricks)
                                        // Simplifies collision detection by aggregating brick row status
    reg[9:0] brickPX[0:7] = '{          // Initial horizontal center position of bricks (8 elements = 8 columns per row)
        140+33+(BRICK_WIDTH+BRICK_GAP)*0 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*1 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*2 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*3 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*4 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*5 + BRICK_OFFSET_X,
        140+33+(BRICK_WIDTH+BRICK_GAP)*6 + BRICK_OFFSET_X, 140+33+(BRICK_WIDTH+BRICK_GAP)*7 + BRICK_OFFSET_X
    };                                  // Calculation: base position + column offset + calibration
    reg[9:0] brickPY[0:3] = '{          // Initial vertical center position of bricks (4 elements = 4 rows total)
        35+30+25*0 + BRICK_OFFSET_Y, 35+30+25*1 + BRICK_OFFSET_Y,
        35+30+25*2 + BRICK_OFFSET_Y, 35+30+25*3 + BRICK_OFFSET_Y
    };                                  // Calculation: base position + row offset + calibration
    reg[31:0] brickState = 32'hFFFFFFFF;// Brick active state register (32 bits = 32 bricks, 1 = active, 0 = destroyed)
                                        // Initialized to all 1's (all bricks active) - updated on brick collision
    reg bricksRow = 1'b1;               // Flag for checking if the last brick row (row 3, indices 24-31) is destroyed
                                        // Used for internal game logic (future expansion: level progression)
    
    // Collision detection registers (1-bit flags for different collision types, reset per frame)
    reg collisionX1 = 1'b0;             // Active high when ball collides with left border (LEFT_BORDER)
    reg collisionX2 = 1'b0;             // Active high when ball collides with right border (RIGHT_BORDER)
    reg collisionY1 = 1'b0;             // Active high when ball collides with top border (TOP_BORDER)
    reg collisionPaddle = 1'b0;         // Active high when ball collides with the player's paddle
                                        // Only triggers when ball is moving downward (ball_dirY = 0)
    reg collisionBottom = 1'b0;         // Active high when ball collides with bottom border (BOTTOM_BORDER)
                                        // Triggers game over (endGame = 1) immediately
    
    // Ball direction control registers (1-bit flags, 1 = negative axis, 0 = positive axis)
    reg ball_dirX = BALL_INIT_DIR_X;    // Current horizontal direction of the ball (1 = left, 0 = right)
                                        // Reversed on left/right border collision or brick horizontal collision
    reg ball_dirY = BALL_INIT_DIR_Y;    // Current vertical direction of the ball (1 = up, 0 = down)
                                        // Reversed on top border/paddle/brick collision
    
    // Win screen animation registers (for visual feedback on game victory)
    reg flash_en = 1'b0;                // Flag for enabling win screen border flash animation
                                        // Controlled by num[17] (slow clock for visible flash)
    reg[9:0] light_x = LEFT_BORDER;     // Horizontal pixel position of the win screen moving light bar
                                        // Animates from left to right across the screen post-victory

    // Start screen graphics wires (combinational signals for start UI rendering)
    wire start_screen_border;           // Active high when current pixel is part of the start screen outer border
    wire start_screen_text;             // Active high when current pixel is part of the start screen text area
    wire start_screen_bg;               // Active high when current pixel is part of the start screen background

    // ------------------------------ Start Screen Graphics Assignments (Combinational Logic) ------------------------------
    // Assign start screen outer border (20 pixels outside game boundaries for visual prominence)
    assign start_screen_border = inDispArea & ((cX == LEFT_BORDER - 20) | (cX == RIGHT_BORDER + 20) | 
                                              (cY == TOP_BORDER - 20) | (cY == BOTTOM_BORDER + 20));
    // Assign start screen text area (two horizontal bars for "BREAKOUT" and "PRESS LEFT TO START" (implied))
    assign start_screen_text = inDispArea & (cX >= 250 && cX <= 550) & (cY >= 200 && cY <= 220)
                            | inDispArea & (cX >= 250 && cX <= 550) & (cY >= 230 && cY <= 250);
    // Assign start screen background (fills area inside border, excludes text and border pixels)
    assign start_screen_bg = inDispArea & (cX > LEFT_BORDER - 20 && cX < RIGHT_BORDER + 20) 
                            & (cY > TOP_BORDER - 20 && cY < BOTTOM_BORDER + 20) & ~start_screen_text & ~start_screen_border;
    
    // ------------------------------ Game State Machine Logic (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Game State Control & Reset Handling
     * Trigger: Positive edge of system clock (synchronous logic) OR negative edge of rst_n (asynchronous reset)
     * Function:
     *  1. Manages state transitions between GAME_STATE_START and GAME_STATE_RUN
     *  2. Executes full asynchronous reset (restores all game objects/flags to initial values)
     *  3. Detects game victory (all bricks destroyed) and triggers win screen animation
     *  4. Handles game start (fire1/fire2) to unlock ball from paddle
     *  5. Restores accidental first brick destruction (edge case handling)
     * 
     * Key Notes:
     *  - Asynchronous reset has highest priority (immediate response, no clock wait)
     *  - State transitions are one-way (start → run) unless reset is triggered
     *  - Win/loss flags remain high until reset (persistent status indication)
     */
    always @(posedge clock or negedge rst_n) begin
        // Game state: Start screen (idle, waiting for user input to enter run state)
        if(game_state == GAME_STATE_START) begin
            // Transition to run state when left button is pressed (active low, debounce-free assumption)
            if(~left) begin
                game_state <= GAME_STATE_RUN;
            end
        end
        // Game state: Active run (all game logic enabled, no return to start state without reset)
        else if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: Restore all game components to initial state (highest priority)
            if(!rst_n) begin
                // Reset ball and paddle positions to initial values
                ballPX <= BALL_INIT_X;
                ballPY <= BALL_INIT_Y;
                paddlePX <= PADDLE_INIT_X;
                paddlePY <= PADDLE_INIT_Y;
                
                // Reset win/loss flags to inactive (low)
                endGame <= 1'b0;
                winGame <= 1'b0;
                // Reset game start flag (ball locked to paddle)
                game_started <= 1'b0;
                // Reset brick row check flag
                bricksRow <= 1'b1;
                
                // Reset all collision detection flags to inactive (low)
                collisionX1 <= 1'b0;
                collisionX2 <= 1'b0;
                collisionY1 <= 1'b0;
                collisionPaddle <= 1'b0;
                collisionBottom <= 1'b0;
                // Reset brick collision index (no collision)
                brickIndex <= -1;
                
                // Restore initial horizontal positions of all 8 brick columns
                brickPX[0] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*0 + BRICK_OFFSET_X;
                brickPX[1] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*1 + BRICK_OFFSET_X;
                brickPX[2] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*2 + BRICK_OFFSET_X;
                brickPX[3] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*3 + BRICK_OFFSET_X;
                brickPX[4] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*4 + BRICK_OFFSET_X;
                brickPX[5] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*5 + BRICK_OFFSET_X;
                brickPX[6] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*6 + BRICK_OFFSET_X;
                brickPX[7] <= 140+33+(BRICK_WIDTH+BRICK_GAP)*7 + BRICK_OFFSET_X;
                
                // Restore initial vertical positions of all 4 brick rows
                brickPY[0] <= 35+30+25*0 + BRICK_OFFSET_Y;
                brickPY[1] <= 35+30+25*1 + BRICK_OFFSET_Y;
                brickPY[2] <= 35+30+25*2 + BRICK_OFFSET_Y;
                brickPY[3] <= 35+30+25*3 + BRICK_OFFSET_Y;
                
                // Restore initial ball direction (left/down)
                ball_dirX <= BALL_INIT_DIR_X;
                ball_dirY <= BALL_INIT_DIR_Y;
                // Reset win screen animation flags (flash off, light bar at left border)
                flash_en <= 1'b0;
                light_x <= LEFT_BORDER;
                
                // Maintain run state (reset does not return to start screen unless modified)
                game_state <= GAME_STATE_RUN;
            end
            // Normal operation (no reset, game is running)
            else begin
                // Edge case handling: Restore first brick if it was incorrectly destroyed (no collision/frame reset)
                if(brickState[0] == 1'b0 && !brickCollision && !resetFrame) begin
                    brickState[0] <= 1'b1;
                end
                
                // Game victory detection: Set winGame high when all bricks are destroyed (brickState = 32'h0)
                // Only triggers if game is not already over (endGame = 0) to avoid conflicting status
                if(brickState == 32'h0 && !endGame) begin
                    winGame <= 1'b1;
                end
                
                // Win screen animation control: Flash border and move light bar across screen
                if(winGame) begin
                    // Toggle flash enable flag based on num[17] (slow clock for visible, non-annoying flash)
                    if(num[17] == 1'b1) begin
                        flash_en <= 1'b1;
                    end else begin
                        flash_en <= 1'b0;
                    end
                    
                    // Animate horizontal light bar: Move right by 2 pixels per frame, wrap to left border when at right
                    if(resetFrame) begin
                        light_x <= (light_x >= RIGHT_BORDER) ? LEFT_BORDER : light_x + 2;
                    end
                end
                
                // Game start logic: Unlock ball from paddle when fire1 or fire2 is pressed (active low)
                // Only effective if game is not started, not won, and not over (idle run state)
                if(!game_started && !winGame && !endGame) begin
                    // Fire1: Launch ball right and up (ball_dirX = 0, ball_dirY = 1)
                    if(~fire1) begin
                        game_started <= 1'b1;
                        ball_dirX <= 1'b0;
                        ball_dirY <= 1'b1;
                    end
                    // Fire2: Launch ball left and up (ball_dirX = 1, ball_dirY = 1)
                    else if(~fire2) begin
                        game_started <= 1'b1;
                        ball_dirX <= 1'b0;
                        ball_dirY <= 1'b1;
                    end
                end
            end
        end
    end
    
    // ------------------------------ Brick Rendering Logic (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Brick Graphics Generation & Row Status Check
     * Trigger: Positive edge of num[0] (sub-clock, derived from 24-bit counter - reduces logic load)
     * Function:
     *  1. Checks if the last brick row (row 3, indices 24-31) is destroyed (bricksRow flag)
     *  2. Traverses all 32 bricks (4 rows × 8 columns) to set horizontal/vertical pixel flags (brickX/brickY)
     *  3. Generates composite brick row flags (bricks[0:3]) for simplified collision detection
     *  4. Only renders active bricks (brickState[i] = 1) to avoid drawing destroyed bricks
     * 
     * Key Notes:
     *  - Uses two rendering logics for bricks 0/1 (interval check) and others (edge check) for efficiency
     *  - Composite bricks flag aggregates row status to reduce downstream collision logic complexity
     *  - Only executes in run state (no brick rendering on start screen)
     */
    always @(posedge num[0]) begin
        // Only execute brick rendering if game is in run state
        if(game_state == GAME_STATE_RUN) begin
            // Reset composite brick row flag to 0 (rebuild per sub-clock cycle)
            bricks = 4'b0;
            // Check if last brick row (indices 24-31) is destroyed: AND of ~brickState[i] for all row 3 bricks
            // bricksRow = 1 only if all row 3 bricks are destroyed (~brickState[i] = 1 for all i=24-31)
            for(i=24; i<32; i=i+1)
                bricksRow = bricksRow & ~brickState[i];
            
            // Traverse all 32 bricks (0-31) to set pixel flags and composite row flags
            for(i=0; i<32; i=i+1) begin
                // Calculate column index (j = 0-7) and row index (k = 0-3) from total brick index (i)
                j = i % 8;    // Column index (mod 8 to wrap every 8 bricks)
                k = i / 8;    // Row index (integer division by 8 to get row number)
                
                // Only process active bricks (brickState[i] = 1 - not destroyed)
                if(brickState[i]) begin
                    // Brick rendering logic for first two bricks (0/1): Interval check for full pixel range
                    // More efficient for early bricks, avoids redundant edge checks
                    if(i == 0 || i == 1) begin
                        brickX[i] = (cX >= brickPX[j] - BRICK_WIDTH/2) && (cX <= brickPX[j] + BRICK_WIDTH/2 - 1) ? 1'b1 : 1'b0;
                        brickY[i] = (cY >= brickPY[k] - BRICK_HEIGHT/2) && (cY <= brickPY[k] + BRICK_HEIGHT/2 - 1) ? 1'b1 : 1'b0;
                    end 
                    // Brick rendering logic for all other bricks (2-31): Edge check with state retention
                    // More efficient for large brick arrays, only updates on edge crossing
                    else begin
                        brickX[i] = (cX == brickPX[j] - BRICK_WIDTH/2) ? 1 : (cX == brickPX[j] + BRICK_WIDTH/2 - 1) ? 0 : brickX[i];
                        brickY[i] = (cY == brickPY[k] - BRICK_HEIGHT/2) ? 1 : (cY == brickPY[k] + BRICK_HEIGHT/2 - 1) ? 0 : brickY[i];
                    end
                    
                    // Set composite brick row flag (bricks[k]) by OR-ing brickX[i] & brickY[i] for all bricks in row k
                    // bricks[k] = 1 if any brick in row k is active and visible at current pixel
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
    
    // ------------------------------ Sub-Module Instantiations (Counter & VGA Sync Generator) ------------------------------
    // Instantiate 24-bit counter module for timing control (animation, sub-clock logic)
    // Connects system clock to counter input, 24-bit output to internal num wire
    counter c(.clock(clock), .out(num));
    
    // Instantiate VGA sync signal generator module for pixel timing and display area detection
    // Connects sub-clock (num[0]) to syncGen clock, outputs hsync/vsync and pixel coordinates
    syncGen generator(.clock(num[0]), .hsync(hsync), .vsync(vsync), 
                     .hcount(cX), .vcount(cY), .inDispArea(inDispArea));
    
    // ------------------------------ Boundary Collision Detection (Horizontal/Top) (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Ball vs Left/Right/Top Border Collision Detection
     * Trigger: Positive edge of num[0] (sub-clock) OR negative edge of rst_n (asynchronous reset)
     * Function:
     *  1. Detects ball collisions with left (LEFT_BORDER), right (RIGHT_BORDER), and top (TOP_BORDER) boundaries
     *  2. Sets corresponding collision flags (collisionX1/collisionX2/collisionY1) when collision occurs
     *  3. Resets collision flags at the end of each frame (resetFrame) to avoid cross-frame residual triggers
     *  4. Only executes in run state and when game is started (ball in motion)
     * 
     * Key Collision Conditions (all must be met):
     *  - game_started = 1 (ball is in motion, not locked to paddle)
     *  - bouncingObject = 1 (current pixel is a bounceable object - border)
     *  - Ball position is within boundary threshold (e.g., ballPX - BALL_HALF_WIDTH <= LEFT_BORDER)
     *  - Current pixel coordinate matches ball position (cY == ballPY for horizontal, cX == ballPX for vertical)
     */
    always @(posedge num[0] or negedge rst_n) begin
        // Only execute boundary collision detection if game is in run state
        if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: Reset all boundary collision flags to inactive (low)
            if(!rst_n) begin
                collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
            end 
            // Reset collision flags at the end of each frame (avoid cross-frame residual triggers)
            else if(resetFrame) begin
                collisionX1 <= 1'b0; collisionX2 <= 1'b0; collisionY1 <= 1'b0;
            end 
            // Normal operation: Detect collisions and set flags
            else begin
                // Left border collision detection: Ball's left edge hits LEFT_BORDER
                if(game_started && bouncingObject & (ballPX - BALL_HALF_WIDTH <= LEFT_BORDER) & (cY == ballPY))
                    collisionX1 <= 1'b1;

                // Right border collision detection: Ball's right edge hits RIGHT_BORDER
                if(game_started && bouncingObject & (ballPX + BALL_HALF_WIDTH >= RIGHT_BORDER) & (cY == ballPY))
                    collisionX2 <= 1'b1;

                // Top border collision detection: Ball's top edge hits TOP_BORDER
                if(game_started && bouncingObject & (ballPY - BALL_HALF_HEIGHT <= TOP_BORDER) & (cX == ballPX))
                    collisionY1 <= 1'b1;
            end
        end
    end
    
    // ------------------------------ Paddle Collision Detection (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Ball vs Paddle Collision Detection
     * Trigger: Positive edge of num[0] (sub-clock) OR negative edge of rst_n (asynchronous reset)
     * Function:
     *  1. Detects ball collisions with the player's paddle (only when ball is moving downward)
     *  2. Sets collisionPaddle flag when ball is within paddle's horizontal/vertical boundaries
     *  3. Resets collisionPaddle flag at the end of each frame (resetFrame) to avoid repeated triggers
     *  4. Only executes in run state and when game is started (ball in motion)
     * 
     * Key Collision Conditions (all must be met):
     *  - game_started = 1 (ball in motion)
     *  - bouncingObject = 1 (current pixel is paddle - bounceable)
     *  - ball_dirY = 0 (ball is moving downward - only valid collision direction)
     *  - Ball's vertical range overlaps with paddle's vertical range
     *  - Ball's horizontal range overlaps with paddle's horizontal range
     */
    always @(posedge num[0] or negedge rst_n) begin
        // Only execute paddle collision detection if game is in run state
        if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: Reset paddle collision flag to inactive (low)
            if(!rst_n) begin
                collisionPaddle <= 1'b0;
            end 
            // Reset paddle collision flag at the end of each frame (avoid cross-frame residual triggers)
            else if(resetFrame) begin
                collisionPaddle <= 1'b0;
            end 
            // Normal operation: Detect ball-paddle collision and set flag
            else if(game_started && bouncingObject & (ball_dirY == 1'b0) & 
                       (ballPY + BALL_HALF_HEIGHT >= paddlePY - PADDLE_HEIGHT/2) &
                       (ballPY - BALL_HALF_HEIGHT <= paddlePY + PADDLE_HEIGHT/2) & 
                       (ballPX + BALL_HALF_WIDTH >= paddlePX - PADDLE_WIDTH/2) & 
                       (ballPX - BALL_HALF_WIDTH <= paddlePX + PADDLE_WIDTH/2)) begin
                // Collision detected: Ball is within paddle's horizontal and vertical boundaries (moving downward)
                collisionPaddle <= 1'b1;
            end
        end
    end
    
    // ------------------------------ Bottom Border Collision (Game Over) (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Ball vs Bottom Border Collision Detection (Game Over Trigger)
     * Trigger: Positive edge of num[0] (sub-clock) OR negative edge of rst_n (asynchronous reset)
     * Function:
     *  1. Detects ball collisions with the bottom border (BOTTOM_BORDER - game over condition)
     *  2. Sets collisionBottom flag when ball's bottom edge hits the bottom border
     *  3. Resets collisionBottom flag at the end of each frame (resetFrame)
     *  4. Triggers endGame (game over) flag in downstream logic when collision occurs
     *  5. Only executes in run state and when game is started (ball in motion)
     * 
     * Key Notes:
     *  - Bottom border collision is the only boundary collision that triggers game over (no ball bounce)
     *  - Collision condition matches other boundary checks for consistency
     */
    always @(posedge num[0] or negedge rst_n) begin
        // Only execute bottom border collision detection if game is in run state
        if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: Reset bottom border collision flag to inactive (low)
            if(!rst_n) begin
                collisionBottom <= 1'b0;
            end 
            // Reset bottom border collision flag at the end of each frame (avoid cross-frame residual triggers)
            else if(resetFrame) begin
                collisionBottom <= 1'b0;
            end 
            // Normal operation: Detect bottom border collision and set flag (game over imminent)
            else begin
                if(game_started && bouncingObject & (ballPY + BALL_HALF_HEIGHT >= BOTTOM_BORDER) & (cX == ballPX)) begin
                    collisionBottom <= 1'b1;
                end
            end
        end
    end
    
    // ------------------------------ Object Movement and Collision Response (Sequential Logic) ------------------------------
    /**
     * Sequential Logic Block: Game Object Update (Ball/Paddle/Bricks) & Collision Response
     * Trigger: Positive edge of num[0] (sub-clock) OR negative edge of rst_n (asynchronous reset)
     * Function:
     *  1. Identifies the hit brick index (brickIndex) when brick collision is detected
     *  2. Destroys hit bricks (sets brickState[brickIndex] = 0) and reverses ball vertical direction
     *  3. Updates paddle position (user input, boundary-constrained) - pre and post game start
     *  4. Updates ball position and direction (collision response for borders/paddle)
     *  5. Locks ball to paddle (pre-game start) for improved aiming experience
     *  6. Triggers game over (endGame = 1) when ball hits bottom border
     * 
     * Key Notes:
     *  - All object updates occur at the end of the frame (resetFrame) for frame synchronization
     *  - Collision responses (direction reversal, position correction) are applied immediately after collision detection
     *  - Paddle movement is boundary-constrained to prevent exiting the game area
     */
    always @(posedge num[0] or negedge rst_n) begin
        // Only execute object updates if game is in run state
        if(game_state == GAME_STATE_RUN) begin
            // Asynchronous reset: Reset brick collision index to -1 (no collision)
            if(!rst_n) begin
                brickIndex <= -1;
            end 
            // Normal operation: Identify hit brick and update objects
            else begin
                // Identify hit brick index: Traverse all 32 bricks when brickCollision is detected
                if(brickCollision) begin
                    brickIndex <= -1; // Reset index first to avoid residual values
                    for(i=0; i<32; i=i+1) begin
                        if(brickX[i] & brickY[i]) begin // Brick is active and colliding with ball
                            brickIndex <= i; // Store hit brick index
                            break; // Exit loop early (only one brick can be hit per frame)
                        end
                    end
                end
                
                // Object update phase: Execute at the end of each frame (resetFrame) for synchronization
                if(resetFrame) begin
                    // Brick destruction & ball vertical direction reversal (collision response)
                    // Only execute if game is started and valid brick index is detected (0-31)
                    if(game_started && brickIndex >= 0 && brickIndex < 32) begin
                        brickState[brickIndex] <= 1'b0; // Mark brick as destroyed (inactive)
                        ball_dirY <= ~ball_dirY; // Reverse ball vertical direction (bounce)
                        brickIndex <= -1; // Reset brick index (no active collision)
                    end
                    
                    // Pre-game start: Paddle movement (user input) with ball locked to paddle
                    // Ball follows paddle horizontally, vertical position fixed to initial value
                    if(!game_started && !winGame && !endGame) begin
                        // Paddle left movement: Only if left button is pressed and paddle is within left boundary
                        if(~left && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin
                            paddlePX <= paddlePX - PADDLE_SPEED; // Move paddle left
                            ballPX <= paddlePX - PADDLE_SPEED;   // Lock ball to paddle (left movement)
                        end
                        // Paddle right movement: Only if right button is pressed and paddle is within right boundary
                        else if(~right && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin
                            paddlePX <= paddlePX + PADDLE_SPEED; // Move paddle right
                            ballPX <= paddlePX + PADDLE_SPEED;   // Lock ball to paddle (right movement)
                        end
                        // Fix ball vertical position to initial value (pre-game start)
                        ballPY <= BALL_INIT_Y;
                    end
                    
                    // Post-game start: Active ball/paddle movement & collision response (non-win/loss)
                    else if(game_started && !winGame && !endGame) begin
                        // Ball horizontal position & direction update (border collision response)
                        if(collisionX1) begin // Left border collision: Reverse to right direction
                            ball_dirX <= 1'b0;
                            ballPX <= LEFT_BORDER + BALL_HALF_WIDTH + BALL_SPEED_X; // Correct position to avoid sticking
                        end else if(collisionX2) begin // Right border collision: Reverse to left direction
                            ball_dirX <= 1'b1;
                            ballPX <= RIGHT_BORDER - BALL_HALF_WIDTH - BALL_SPEED_X; // Correct position to avoid sticking
                        end else begin // No horizontal collision: Move ball in current direction
                            ballPX <= ballPX + (ball_dirX ? -BALL_SPEED_X : BALL_SPEED_X);
                        end
                        
                        // Ball vertical position & direction update (paddle/top/bottom border collision response)
                        if(collisionPaddle) begin // Paddle collision: Reverse to up direction
                            ball_dirY <= 1'b1;
                            ballPY <= paddlePY - PADDLE_HEIGHT/2 - BALL_HALF_HEIGHT - 1; // Correct position to avoid sticking
                        end 
                        else if(collisionY1) begin // Top border collision: Reverse to down direction
                            ball_dirY <= 1'b0;
                            ballPY <= TOP_BORDER + BALL_HALF_HEIGHT + BALL_SPEED_Y; // Correct position to avoid sticking
                        end 
                        else if(collisionBottom) begin // Bottom border collision: Trigger game over
                            endGame <= 1'b1; // Set endGame flag high (persistent until reset)
                        end 
                        else begin // No vertical collision: Move ball in current direction
                            ballPY <= ballPY + (ball_dirY ? -BALL_SPEED_Y : BALL_SPEED_Y);
                        end
                        
                        // Paddle movement (user input, boundary-constrained) - post game start
                        // Same logic as pre-game start, but ball is not locked to paddle
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
    
    // ------------------------------ Graphics Signal Assignments (Combinational Logic) ------------------------------
    // Ball horizontal pixel flag: 1 when cX is within ball's horizontal range, 0 otherwise (edge-based)
    assign ballX = (cX == ballPX - BALL_HALF_WIDTH) ? 1'b1 : (cX == ballPX + BALL_HALF_WIDTH) ? 1'b0 : ballX;
    // Brick collision detection: Active high when any brick is active and ball is present (composite flag)
    assign brickCollision = |bricks & ball;
    // Bounceable object flag: Active high when current pixel is border, paddle, or brick (valid collision targets)
    assign bouncingObject = border | paddle | bricks;
    // Frame reset flag: Active high at the last pixel of VGA 640x480 frame (cX=639, cY=479)
    assign resetFrame = (cX==639) & (cY==479);
    // Game border flag: Active high when current pixel is part of the game's visible boundaries
    assign border = (cX==LEFT_BORDER) | (cX==RIGHT_BORDER) | 
                    (cY==TOP_BORDER) | (cY==BOTTOM_BORDER);
    // Graphics coordinate aliases: Simplify downstream graphics logic (cX/cY → gX/gY)
    assign gX = cX; assign gY = cY;
    // Ball vertical pixel flag: 1 when cY is within ball's vertical range, 0 otherwise (edge-based)
    assign ballY = (cY == ballPY - BALL_HALF_HEIGHT) ? 1'b1 : (cY == ballPY + BALL_HALF_HEIGHT) ? 1'b0 : ballY;
    // Composite ball flag: Active high when current pixel is part of the ball (ballX & ballY)
    assign ball = ballX & ballY;
    // Paddle horizontal pixel flag: 1 when cX is within paddle's horizontal range, 0 otherwise (edge-based)
    assign paddleX = (cX == paddlePX - PADDLE_WIDTH/2) ? 1'b1 : (cX == paddlePX + PADDLE_WIDTH/2 - 1) ? 1'b0 : paddleX;
    // Paddle vertical pixel flag: 1 when cY is within paddle's vertical range, 0 otherwise (edge-based)
    assign paddleY = (cY == paddlePY - PADDLE_HEIGHT/2) ? 1'b1 : (cY == paddlePY + PADDLE_HEIGHT/2 - 1) ? 1'b0 : paddleY;
    // Composite paddle flag: Active high when current pixel is part of the paddle (paddleX & paddleY)
    assign paddle = paddleX & paddleY;
    
    // Win screen graphics assignments (combinational logic for victory visual feedback)
    wire win_border;                    // Win screen flashing border flag (active when flash_en is high)
    wire win_light;                     // Win screen moving light bar flag (animated horizontal bar)
    assign win_border = flash_en & inDispArea & ((cX == LEFT_BORDER) | (cX == RIGHT_BORDER) | (cY == TOP_BORDER) | (cY == BOTTOM_BORDER));
    assign win_light = inDispArea & (cX == light_x) & (cY >= (TOP_BORDER + BOTTOM_BORDER)/2 - 10) & (cY <= (TOP_BORDER + BOTTOM_BORDER)/2 + 10);
    
    // ------------------------------ VGA Color Channel Assignments (Combinational Logic) ------------------------------
    /**
     * Combinational Logic: VGA Red/Green/Blue Color Channel Control
     * Function:
     *  1. Selects pixel color based on current game state (start/running/win/loss)
     *  2. Assigns distinct colors to game objects (ball, paddle, bricks) for visual differentiation
     *  3. Provides visual feedback for win/loss conditions (flashing border, moving light, checkerboard)
     *  4. 1-bit color channels (0 = off, 1 = full on) for simplified VGA output
     * 
     * Game State Color Mapping:
     *  - Start State: Blue border, green background, white text/border
     *  - Win State: Flashing white/blue border, moving white light bar
     *  - Loss State: Checkerboard pattern (XOR of cX/cY bits) for game over
     *  - Run State: White border, colored bricks, white paddle, green ball
     */
    assign r = (game_state == GAME_STATE_START) ? (start_screen_border | start_screen_text) 
              : (winGame ? (win_border | win_light) : (endGame ? (cX[5] ^ cY[5]) : (border | bricks[0] | bricks[3] | paddle)));
    assign g = (game_state == GAME_STATE_START) ? start_screen_bg 
              : (winGame ? (win_light) : (endGame ? (cX[4] ^ cY[4]) : (border | bricks[1] | bricks[3] | paddle | ball)));
    assign b = (game_state == GAME_STATE_START) ? start_screen_border 
              : (winGame ? (win_border) : (endGame ? (cX[3] ^ cY[3]) : (border | bricks[2] | paddle | ball)));
endmodule
