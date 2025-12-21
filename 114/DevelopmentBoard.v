`timescale 1ns / 1ns

module DevelopmentBoard(
    input wire clk,          // 50MHz系统时钟（开发板时钟）
    input wire reset,        // a键：全局复位（开发板按键，按下为低电平）
    input wire B2,           // s键：left控制（开发板按键，按下为低电平）
    input wire B3,           // d键：right控制（开发板按键，按下为低电平）
    input wire B4,           // 预留：f键（未使用）
    input wire B5,           // 预留：g键（未使用）
    output wire h_sync,      // VGA行同步输出
    output wire v_sync,      // VGA场同步输出
    output wire [15:0] rgb,  // VGA显示数据输出
    
    output wire led1,        // a键按下时亮
    output wire led2,        // s键按下时亮
    output wire led3,        // d键按下时亮
    output wire led4,        // 游戏结束时亮
    output wire led5         // 预留：常灭
);

// ====================== 内部信号定义 ======================
// 适配模块的电平逻辑（开发板按键按下为低，模块需要高有效控制）
wire sys_rst_n;    // 全局复位（低有效）
wire left;         // breakout的左移控制（高有效）
wire right;        // breakout的右移控制（高有效）
wire endGame;      // breakout的游戏结束标志（高有效）

// ====================== 按键电平转换 ======================
// 1. 复位：a键（reset）按下→低电平→sys_rst_n=低（触发复位）
assign sys_rst_n = reset;

// 2. left：s键（B2）按下→低电平→取反后left=高（触发左移）
assign left = ~B2;

// 3. right：d键（B3）按下→低电平→取反后right=高（触发右移）
assign right = ~B3;

// ====================== LED逻辑 ======================
// led1：a键按下时亮（reset=低→led1=高）
assign led1 = ~reset;

// led2：s键按下时亮（B2=低→led2=高）
assign led2 = ~B2;

// led3：d键按下时亮（B3=低→led3=高）
assign led3 = ~B3;

// led4：游戏结束时亮（endGame=高→led4=高）
assign led4 = endGame;

// led5：预留，常灭
assign led5 = 1'b0;

// ====================== 实例化breakout模块（核心） ======================
// breakout内部已实例化counter和syncGen，顶层无需重复实例化
breakout u_breakout(
    .sys_clk    (clk),          // 50MHz时钟输入
    .sys_rst_n  (sys_rst_n),    // 全局复位（低有效）
    .left       (left),         // 左移控制（s键）
    .right      (right),        // 右移控制（d键）
    .hsync      (h_sync),       // VGA行同步输出
    .vsync      (v_sync),       // VGA场同步输出
    .rgb        (rgb),          // VGA显示数据输出
    .endGame    (endGame)       // 游戏结束标志（接led4）
);

endmodule