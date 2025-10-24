`timescale 1ns/1ps
module pll(
    input wire sys_clk,      
    input wire sys_rst_n,    
    output reg vga_clk       
);


reg [0:0] cnt;  
always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        cnt <= 1'b0;
        vga_clk <= 1'b0;
    end else begin
        cnt <= cnt + 1'b1;
        vga_clk <= cnt[0];  
    end
end

endmodule

