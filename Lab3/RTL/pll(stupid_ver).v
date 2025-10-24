`timescale 1ns/1ps
module pll(
    input wire sys_clk ,
    input wire sys_rst_n ,
    output wire vga_clk
);

reg clk_25;
always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) clk_25 <= 0;
    else clk_25 <= ~clk_25;
end

assign vga_clk = clk_25;
endmodule
