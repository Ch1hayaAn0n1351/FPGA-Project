`timescale 1ns/1ps
module DevelopmentBoard(
    input wire clk,      // 50MHz系统时钟
    input wire reset,    // 复位按键（A，低有效）
    input wire B2,       // 按键S
    input wire B3,       // 按键D
    input wire B4,       // 按键F（预留）
    input wire B5,       // 按键G（预留）
    output wire h_sync,  // VGA行同步
    output wire v_sync,  // VGA场同步
    output wire [15:0] rgb,  // VGA RGB数据
    output wire led1,    // LED1：复位状态指示
    output wire led2,    // LED2：B2按键指示
    output wire led3,    // LED3：B3按键指示
    output wire led4,    // LED4：B4按键指示
    output wire led5     // LED5：B5按键指示
);

// LED指示逻辑：按键按下时LED亮（假设按键按下为低电平，LED低电平亮）
assign led1 = reset;       // 复位按下（reset=0）时led1亮
assign led2 = B2;          // B2按下（B2=0）时led2亮
assign led3 = B3;          // B3按下（B3=0）时led3亮
assign led4 = B4;          // B4按下（B4=0）时led4亮
assign led5 = B5;          // B5按下（B5=0）时led5亮

// 例化VGA顶层模块（注意：按键信号取反，适配低电平有效按键）
ColorBar ColorBar_inst(
    .sys_clk(clk),
    .sys_rst_n(reset),      // 复位低有效
    .key_s(!B2),            // B2按下时key_s=1（高电平触发）
    .key_d(!B3),            // B3按下时key_d=1
    .key_f(!B4),
    .key_g(!B5),
    .hsync(h_sync),
    .vsync(v_sync),
    .rgb(rgb)
);

endmodule

