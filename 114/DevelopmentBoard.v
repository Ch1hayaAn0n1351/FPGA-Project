`timescale 1ns / 1ns

module DevelopmentBoard(
    input wire clk, // 50MHz系统时钟（对应top_breakout的sys_clk）
    input wire reset, // 复位按键（高有效）→ 按下时led1亮
    input wire B2, B3, B4, B5, // 开发板物理按键
    // 按键映射最终版：
    // reset → 复位键（按下时led1亮）
    // B2    → 左移按键（按下时led2亮）
    // B3    → 右移按键（按下时led3亮）
    // B4/B5 → 暂未使用
    output wire h_sync, // VGA行同步
    output wire v_sync, // VGA场同步
    output wire [15:0] rgb, // VGA RGB565输出
    output wire led1, // 复位键按下亮
    output wire led2, // 左移按键（B2）按下亮
    output wire led3, // 右移按键（B3）按下亮
    output wire led4, // 游戏结束亮
    output wire led5  // 备用LED（常灭）
);

// -------------------------- 内部线网定义 --------------------------
// 复位信号转换：将高有效reset转为低有效sys_rst_n（匹配子模块复位极性）
wire sys_rst_n;
assign sys_rst_n = ~reset;

// 25MHz VGA时钟（由50MHz分频得到）
wire vga_clk;

// 消抖后的按键信号（开发板按键通常按下为低电平，消抖后保持该特性）
wire key_left_deb;   // B2消抖后（左移）
wire key_right_deb;  // B3消抖后（右移）

// 游戏结束信号（来自breakout模块）
wire end_game;

// 显示使能（默认开启）
wire disp = 1'b1;

// -------------------------- 模块实例化 --------------------------
// 1. 时钟分频模块：50MHz → 25MHz VGA时钟
clk_div u_clk_div(
    .sys_clk    (clk),
    .sys_rst_n  (sys_rst_n),
    .vga_clk    (vga_clk)
);

// 2. 左移按键（B2）消抖模块
key_debounce u_key_left(
    .sys_clk    (clk),
    .sys_rst_n  (sys_rst_n),
    .key_in     (B2),       // B2作为左移输入
    .key_out    (key_left_deb)
);

// 3. 右移按键（B3）消抖模块
key_debounce u_key_right(
    .sys_clk    (clk),
    .sys_rst_n  (sys_rst_n),
    .key_in     (B3),       // B3作为右移输入
    .key_out    (key_right_deb)
);

// 4. 打砖块游戏核心模块
breakout u_breakout(
    .disp       (disp),
    .left       (key_left_deb),  // 消抖后的左移信号
    .right      (key_right_deb), // 消抖后的右移信号
    .vga_clk    (vga_clk),
    .hsync      (h_sync),        // 对接VGA行同步输出
    .vsync      (v_sync),        // 对接VGA场同步输出
    .rgb        (rgb),           // 对接VGA RGB输出
    .endGame    (end_game)       // 游戏结束信号
);

// -------------------------- LED逻辑映射 --------------------------
assign led1 = reset;            // 复位键（reset）按下（高电平）→ led1亮
assign led2 = ~key_left_deb;    // 左移按键（B2）按下（消抖后低电平）→ 取反后led2亮
assign led3 = ~key_right_deb;   // 右移按键（B3）按下（消抖后低电平）→ 取反后led3亮
assign led4 = end_game;         // 游戏结束（end_game=1）→ led4亮
assign led5 = 1'b0;             // 备用LED常灭

endmodule
