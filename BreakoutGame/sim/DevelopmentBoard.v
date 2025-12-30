`timescale 1ns / 1ps
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

wire rst_n;
wire r_1bit, g_1bit, b_1bit;
wire game_end;
wire game_win;

assign rst_n = reset; 

breakout u_breakout(
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

wire [4:0] r_5, g_5, b_5;
assign r_5 = {5{r_1bit}};
assign g_5 = {5{g_1bit}};
assign b_5 = {5{b_1bit}};
assign rgb = {1'b0, r_5, g_5, b_5};

assign led1 = ~rst_n;
assign led2 = ~B2;
assign led3 = ~B3;
assign led4 = ~B4;
assign led5 = ~B5;

endmodule

