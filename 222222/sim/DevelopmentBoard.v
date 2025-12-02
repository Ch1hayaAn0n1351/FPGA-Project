`timescale 1ns / 1ps

module DevelopmentBoard(
    input wire clk, //50MHz
    input wire reset, B2, B3, B4, B5,
    output wire h_sync, v_sync,
    output wire [15:0] rgb,
    
    output wire led1,
    output wire led2,
    output wire led3,
    output wire led4,
    output wire led5
);

// 中间信号定义
wire rst_n;          // 复位信号（高电平正常，低电平复位）
wire r_1bit, g_1bit, b_1bit;  // breakout输出的1bit RGB
wire game_end;       // 游戏结束信号

// 复位极性调整：a键按下为低 → 复位
assign rst_n = reset; 

// 例化打砖块主模块
breakout u_breakout(
    .disp(1'b0),       // disp无用，接地
    .left(B2),         // B2（S键）→ 左移（低电平有效）
    .right(B3),        // B3（D键）→ 右移（低电平有效）
    .clock(clk),       // 50MHz时钟输入
    .hsync(h_sync),    // 行同步输出
    .vsync(v_sync),    // 场同步输出
    .r(r_1bit),        // 1bit红色输出
    .g(g_1bit),        // 1bit绿色输出
    .b(b_1bit),        // 1bit蓝色输出
    .endGame(game_end) // 游戏结束信号输出
);

// RGB位宽扩展（1bit→16bit）：将1bit信号复制到对应位宽
wire [4:0] r_5, g_5, b_5;
assign r_5 = {5{r_1bit}};  // 1bit→5bit红色
assign g_5 = {5{g_1bit}};  // 1bit→5bit绿色
assign b_5 = {5{b_1bit}};  // 1bit→5bit蓝色
assign rgb = {1'b0, r_5, g_5, b_5}; // 16bit RGB（格式：0 + R5 + G5 + B5）

// LED反馈：按键按下时亮，游戏结束时LED5亮
assign led1 = ~B2;         // S键→LED1
assign led2 = ~B3;         // D键→LED2
assign led3 = ~rst_n;      // 复位→LED3
assign led4 = ~B4;         // F键→LED4（发射键提示，原游戏未用发射键可保留）
assign led5 = game_end;    // 游戏结束→LED5

endmodule
