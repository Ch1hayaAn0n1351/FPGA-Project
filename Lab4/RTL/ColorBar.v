`timescale 1ns/1ps
module ColorBar(
    input wire sys_clk,        // 系统时钟（50MHz）
    input wire sys_rst_n,      // 复位信号（低电平有效）
    input wire key_s, 
    input wire key_d,
    input wire key_f,
    input wire key_g,
    output wire hsync,         // VGA行同步信号
    output wire vsync,         // VGA场同步信号
    output wire [15:0] rgb     // VGA输出颜色信号（16位RGB565）
);

// 内部信号定义
wire vga_clk;                 // VGA工作时钟（25MHz，由PLL模块生成）
wire [9:0] pix_x, pix_y;      // 当前像素坐标（由VGA时序模块输出）
wire [15:0] pic_bar_data;     // 色条图像数据（来自vga_pic模块）
wire [15:0] pic_char1_data;   // 32x32字符图像数据（来自vga_pic1模块）
wire [15:0] pic_char2_data;   // 64x64字符图像数据（来自vga_pic2模块）
wire [15:0] pix_data_sel;     // 选择后的图像数据（根据状态机切换）
wire [1:0] state;             // 状态机当前状态（用于选择图像）

// 1. PLL模块：生成25MHz VGA时钟
pll pll_inst(
    .sys_clk(sys_clk),         // 输入系统时钟（50MHz）
    .sys_rst_n(sys_rst_n),     // 输入复位信号
    .vga_clk(vga_clk)          // 输出VGA工作时钟（25MHz）
);

// 2. 色条图像模块：生成10色竖条
vga_pic vga_pic_inst(
    .vga_clk(vga_clk),         // VGA时钟
    .sys_rst_n(sys_rst_n),     // 复位信号
    .pix_x(pix_x),             // 当前像素X坐标
    .pix_y(pix_y),             // 当前像素Y坐标
    .pix_data(pic_bar_data)    // 输出色条图像数据
);

// 3. 64x64字符图像模块：生成MUST图像
vga_pic1 vga_pic1_inst(
    .vga_clk(vga_clk),
    .sys_rst_n(sys_rst_n),
    .pix_x(pix_x),
    .pix_y(pix_y),
    .pix_data(pic_char1_data)  // 输出64x64字符数据
);

// 4. 64x64字符图像模块：生成END图像
vga_pic2 vga_pic2_inst(
    .vga_clk(vga_clk),
    .sys_rst_n(sys_rst_n),
    .pix_x(pix_x),
    .pix_y(pix_y),
    .pix_data(pic_char2_data)  // 输出64x64字符数据
);

// 5. 状态机模块：控制图像切换（4种状态循环）
state_machine_final state_machine_final_inst(
    .sys_clk(sys_clk),         // 系统时钟（状态机驱动时钟）
    .sys_rst_n(sys_rst_n),     // 复位信号
    .chan(key_s),              // 状态切换触发（按键key_s）
    .state_out(state)          // 输出当前状态（0~3）
);

// 6. 图像选择逻辑：根据状态机选择当前显示的图像
// 状态定义：0-IDLE（黑屏）、1-BAR（色条）、2-CHAR（32x32字符）、3-CUSTOM（64x64字符）
assign pix_data_sel = (state == 2'd0) ? 16'h0000 :         // 状态0：黑屏
                      (state == 2'd1) ? pic_bar_data :     // 状态1：显示色条
                      (state == 2'd2) ? pic_char1_data :   // 状态2：显示32x32字符
                      (state == 2'd3) ? pic_char2_data :   // 状态3：显示64x64字符
                                        16'h0000;          // 默认：黑屏

// 7. VGA时序控制模块：生成同步信号和像素坐标，输出最终颜色
vga_ctrl vga_ctrl_inst(
    .vga_clk(vga_clk),         // VGA工作时钟
    .sys_rst_n(sys_rst_n),     // 复位信号
    .pix_data(pix_data_sel),   // 输入选择后的图像数据
    .pix_x(pix_x),             // 输出当前像素X坐标
    .pix_y(pix_y),             // 输出当前像素Y坐标
    .hsync(hsync),             // 输出行同步信号
    .vsync(vsync),             // 输出场同步信号
    .rgb(rgb)                  // 输出最终VGA颜色信号
);

endmodule
