`timescale 1ns/1ps
module clk_div(
    input wire sys_clk,    // 系统时钟（如50MHz）
    input wire sys_rst_n,  // 系统复位（低有效）
    output reg vga_clk     // 输出25MHz VGA时钟
);

reg [1:0] cnt; // 分频计数器（50MHz→25MHz需2分频）

// 计数器逻辑
always @(posedge sys_clk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        cnt <= 2'd0;
    end else begin
        cnt <= cnt + 1'b1;
    end
end

// 2分频生成25MHz时钟（占空比50%）
always @(posedge sys_clk or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
        vga_clk <= 1'b0;
    end else if(cnt == 2'd1) begin // 50MHz每2个周期翻转一次→25MHz
        vga_clk <= ~vga_clk;
    end
end

endmodule