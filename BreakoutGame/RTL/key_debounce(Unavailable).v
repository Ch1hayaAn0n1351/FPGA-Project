//Unfortunately，Our program cannot running if we add these key_debounce codes.
//However, In virtualBox, Our Program has key_debounce without these codes.
//And without key_debounce codes, Our Program could works very stable.


//Key Debounce Module Definition
`timescale 1ns/1ps
module key_debounce(
    input wire clk,              // System clock (50MHz, from counter module)
    input wire rst_n,            // Active-low reset signal (from top-level module)
    input wire key_raw,          // Raw key signal (from top-level key mapping)
    output reg key_stable,       // Debounced stable key state (1=not pressed, 0=pressed)
    output wire key_falling_edge // Key falling edge trigger signal (1-cycle high)
);
    // Parameter definition: 20ms count value under 50MHz clock (50MHz * 20ms = 1,000,000)
    localparam CNT_20MS_MAX = 20'd1000000;
    
    reg [19:0] cnt_press_20ms;   // Counter for key press stable state (20ms)
    reg [19:0] cnt_release_20ms; // Counter for key release stable state (20ms)
    reg key_stable_prev;         // Previous state of key_stable (for falling edge detection)
    
    // Press stable state counting: reset when key is released, count when key is pressed
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt_press_20ms <= 20'b0;
        end else if (key_raw) begin // Key is released (raw signal is high), reset counter
            cnt_press_20ms <= 20'b0;
        end else if (cnt_press_20ms == CNT_20MS_MAX && !key_raw) begin // Stable press for 20ms, reset counter
            cnt_press_20ms <= 20'b0;
        end else begin // Key is pressed (raw signal is low), count up
            cnt_press_20ms <= cnt_press_20ms + 1'b1;
        end
    end
    
    // Release stable state counting: reset when key is pressed, count when key is released
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt_release_20ms <= 20'b0;
        end else if (!key_raw) begin // Key is pressed (raw signal is low), reset counter
            cnt_release_20ms <= 20'b0;
        end else if (cnt_release_20ms == CNT_20MS_MAX && key_raw) begin // Stable release for 20ms, reset counter
            cnt_release_20ms <= 20'b0;
        end else begin // Key is released (raw signal is high), count up
            cnt_release_20ms <= cnt_release_20ms + 1'b1;
        end
    end
    
    // Generate stable key state: update when stable press/release is detected
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            key_stable <= 1'b1; // Initial state: key not pressed
        end else if (cnt_press_20ms >= CNT_20MS_MAX - 1'd1) begin // Stable press for 20ms, set to pressed state
            key_stable <= 1'b0;
        end else if (cnt_release_20ms >= CNT_20MS_MAX - 1'd1) begin // Stable release for 20ms, set to released state
            key_stable <= 1'b1;
        end else begin // No stable state change, keep current state
            key_stable <= key_stable;
        end
    end
    
    // Latch previous state of key_stable for falling edge detection
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            key_stable_prev <= 1'b1; // Initial state: key not pressed
        end else begin
            key_stable_prev <= key_stable;
        end
    end
    
    // Detect falling edge of key_stable (key pressed event): high when prev is 1 and current is 0
    assign key_falling_edge = key_stable_prev & (~key_stable);
    
endmodule

//Module Instantiation in Main Game Logic (breakout)
// Signal definition: debounced key signals and falling edge signals
reg left_stable;       // Stable state of left movement key (B2)
reg right_stable;      // Stable state of right movement key (B3)
reg fire1_stable;      // Stable state of fire1 key (B4, ball launch direction 1)
reg fire2_stable;      // Stable state of fire2 key (B5, ball launch direction 2)
wire left_falling;     // Falling edge of left key (trigger game start)
wire right_falling;    // Falling edge of right key (reserved)
wire fire1_falling;    // Falling edge of fire1 key (trigger ball launch)
wire fire2_falling;    // Falling edge of fire2 key (trigger ball launch)

// Instantiate left movement key debounce module (map to B2)
key_debounce u_debounce_left(
    .clk(clk),                // Input: system clock (50MHz)
    .rst_n(rst_n),            // Input: active-low reset
    .key_raw(left),           // Input: raw left key signal (from top-level mapping)
    .key_stable(left_stable), // Output: debounced left key stable state
    .key_falling_edge(left_falling) // Output: left key falling edge trigger
);

// Instantiate right movement key debounce module (map to B3)
key_debounce u_debounce_right(
    .clk(clk),
    .rst_n(rst_n),
    .key_raw(right),
    .key_stable(right_stable),
    .key_falling_edge(right_falling)
);

// Instantiate fire1 key debounce module (map to B4)
key_debounce u_debounce_fire1(
    .clk(clk),
    .rst_n(rst_n),
    .key_raw(fire1),
    .key_stable(fire1_stable),
    .key_falling_edge(fire1_falling)
);

// Instantiate fire2 key debounce module (map to B5)
key_debounce u_debounce_fire2(
    .clk(clk),
    .rst_n(rst_n),
    .key_raw(fire2),
    .key_stable(fire2_stable),
    .key_falling_edge(fire2_falling)
);

//Application in Game Logic
// 1. Game state switching (start page → run page) triggered by left key falling edge
if(game_state == GAME_STATE_START) begin
    if(left_falling) begin
        game_state <= GAME_STATE_RUN;
    end
end

// 2. Ball launch triggered by fire1/fire2 key falling edge (before game starts)
if(!game_started && !winGame && !endGame) begin
    if(fire1_falling) begin
        game_started <= 1'b1;
        ball_dirX <= 1'b1; // Set ball X direction (right)
        ball_dirY <= 1'b1; // Set ball Y direction (up)
    end
    else if(fire2_falling) begin
        game_started <= 1'b1;
        ball_dirX <= 1'b0; // Set ball X direction (left)
        ball_dirY <= 1'b1; // Set ball Y direction (up)
    end
end

// 3. Paddle movement control (before game starts: ball moves with paddle)
if(!game_started && !winGame && !endGame) begin
    if(!left_stable && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin // Left key pressed (stable)
        paddlePX <= paddlePX - PADDLE_SPEED;
        ballPX <= paddlePX - PADDLE_SPEED; // Ball follows paddle movement
    end
    else if(!right_stable && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin // Right key pressed (stable)
        paddlePX <= paddlePX + PADDLE_SPEED;
        ballPX <= paddlePX + PADDLE_SPEED; // Ball follows paddle movement
    end
    ballPY <= BALL_INIT_Y; // Fix ball Y position before launch
end

// 4. Paddle movement control (after game starts: independent movement)
else if(game_started && !winGame && !endGame) begin
    if(!left_stable && (paddlePX - PADDLE_WIDTH/2 > LEFT_BORDER)) begin // Left key pressed (stable)
        paddlePX <= paddlePX - PADDLE_SPEED;
    end else if(!right_stable && (paddlePX + PADDLE_WIDTH/2 < RIGHT_BORDER)) begin // Right key pressed (stable)
        paddlePX <= paddlePX + PADDLE_SPEED;
    end
end
