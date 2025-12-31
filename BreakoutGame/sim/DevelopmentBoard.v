// Time unit: 1 nanosecond, Time precision: 1 picosecond
`timescale 1ns / 1ps

/**
 * Module: DevelopmentBoard
 * Function: Top-level module for mapping the Breakout game core logic to physical development board hardware.
 *           Interfaces between the game logic (breakout module) and external hardware ports (clock, buttons, VGA, LEDs).
 *           Converts 1-bit VGA color channels to 5-bit RGB for standard development board display outputs.
 * Port List:
 *   - Input:  clk     - Development board main clock signal (hardware clock input)
 *   - Input:  reset   - Development board reset button (mapped to game rst_n)
 *   - Input:  B2-B5   - Development board user buttons (mapped to game left/right/fire1/fire2 inputs)
 *   - Output: h_sync  - VGA horizontal sync signal (passed to board VGA output)
 *   - Output: v_sync  - VGA vertical sync signal (passed to board VGA output)
 *   - Output: rgb     - 16-bit VGA RGB output (5-bit R, 5-bit G, 5-bit B, 1-bit unused)
 *   - Output: led1-led5 - Development board status LEDs (mapped to reset and button states)
 */
module DevelopmentBoard(
    input wire clk,
    input wire reset, B2, B3, B4, B5,
    output wire h_sync, v_sync,
    output wire [15:0] rgb,
    
    output wire led1,
    output wire led2,
    output wire led3,
    output wire led4,
    output wire led5
);

// ------------------------------ Internal Signal Declarations ------------------------------
wire rst_n;                                  // Active low reset signal for game logic
wire r_1bit, g_1bit, b_1bit;                 // 1-bit color channels from breakout module
wire game_end;                               // Game over flag (unused in top-level, for future expansion)
wire game_win;                               // Game win flag (unused in top-level, for future expansion)

// ------------------------------ Hardware Port Mapping ------------------------------
// Map development board reset button to game active low reset (rst_n = reset button state)
assign rst_n = reset; 

/**
 * Module Instantiation: Breakout Game Core
 * Maps development board buttons and clock to game logic inputs, and game outputs to internal signals.
 */
breakout u_breakout(
    .left(B2),                               // Map B2 button to game left movement input
    .right(B3),                              // Map B3 button to game right movement input
    .fire1(B4),                              // Map B4 button to game fire1 (right launch) input
    .fire2(B5),                              // Map B5 button to game fire2 (left launch) input
    .clock(clk),                             // Map development board clock to game logic clock
    .rst_n(rst_n),                           // Map active low reset to game logic reset
    .hsync(h_sync),                          // Map game hsync to VGA horizontal sync output
    .vsync(v_sync),                          // Map game vsync to VGA vertical sync output
    .r(r_1bit),                              // Map game 1-bit red to internal 1-bit R signal
    .g(g_1bit),                              // Map game 1-bit green to internal 1-bit G signal
    .b(b_1bit),                              // Map game 1-bit blue to internal 1-bit B signal
    .endGame(game_end),                      // Map game over flag to internal signal
    .winGame(game_win)                       // Map game win flag to internal signal
);

// ------------------------------ VGA Color Channel Conversion (1-bit to 5-bit) ------------------------------
// Convert 1-bit color channels to 5-bit wide signals for standard development board VGA RGB outputs
wire [4:0] r_5, g_5, b_5;
assign r_5 = {5{r_1bit}};                   // Repeat 1-bit R 5 times to form 5-bit R channel
assign g_5 = {5{g_1bit}};                   // Repeat 1-bit G 5 times to form 5-bit G channel
assign b_5 = {5{b_1bit}};                   // Repeat 1-bit B 5 times to form 5-bit B channel
assign rgb = {1'b0, r_5, g_5, b_5};         // Compose 16-bit RGB output (1 unused bit + 5R + 5G + 5B)

// ------------------------------ LED Status Mapping ------------------------------
// Map development board LEDs to system status signals (active low, LED on when signal is low)
assign led1 = ~rst_n;                       // LED1: On when reset is active (rst_n low)
assign led2 = ~B2;                          // LED2: On when B2 (left) button is pressed
assign led3 = ~B3;                          // LED3: On when B3 (right) button is pressed
assign led4 = ~B4;                          // LED4: On when B4 (fire1) button is pressed
assign led5 = ~B5;                          // LED5: On when B5 (fire2) button is pressed

endmodule

