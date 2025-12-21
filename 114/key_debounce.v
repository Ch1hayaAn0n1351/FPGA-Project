`timescale 1ns/1ps
module key_debounce(
    input wire sys_clk,  // 系统时钟（如50MHz）
    input wire sys_rst_n,// 系统复位（低有效）
    input wire key_in,   // 按键输入（开发板物理按键）
    output reg key_out   // 消抖后输出
);

// 消抖参数：50MHz时钟下，20ms消抖需要计数1_000_000次
parameter CNT_MAX = 20'd999_999;

reg [19:0] cnt;       // 消抖计数器
reg key_in_d1, key_in_d2; // 按键输入打拍

// 步骤1：按键输入打拍（同步+消亚稳态）
always @(posedge sys_clk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        key_in_d1 <= 1'b1;
        key_in_d2 <= 1'b1;
    end else begin
        key_in_d1 <= key_in;
        key_in_d2 <= key_in_d1;
    end
end

// 步骤2：消抖计数器
always @(posedge sys_clk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        cnt <= 20'd0;
    end else if(key_in_d1 != key_in_d2) begin // 按键状态变化，清零计数器
        cnt <= 20'd0;
    end else if(cnt < CNT_MAX) begin // 未到消抖时间，继续计数
        cnt <= cnt + 1'b1;
    end else begin // 消抖完成，保持计数
        cnt <= CNT_MAX;
    end
end

// 步骤3：消抖后输出（计数器满时锁存按键状态）
always @(posedge sys_clk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        key_out <= 1'b1; // 按键默认高电平（开发板按键通常低有效）
    end else if(cnt == CNT_MAX) begin
        key_out <= key_in_d2;
    end
end

endmodule