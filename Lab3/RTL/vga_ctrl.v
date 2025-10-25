`timescale 1ns/1ps
module vga_ctrl(
    input wire vga_clk,      
    input wire sys_rst_n,    
    input wire [15:0] pix_data, 
    output wire [9:0] pix_x,     
    output wire [9:0] pix_y,     
    output wire hsync,       
    output wire vsync,       
    output wire [15:0] rgb    
);


parameter H_SYNC    = 10'd96;   
parameter H_BACK    = 10'd48;    
parameter H_VALID   = 10'd640;   
parameter H_FRONT   = 10'd16;    
parameter H_TOTAL   = H_SYNC + H_BACK + H_VALID + H_FRONT;  

parameter V_SYNC    = 10'd2;     
parameter V_BACK    = 10'd33;   
parameter V_VALID   = 10'd480;   
parameter V_FRONT   = 10'd10;    
parameter V_TOTAL   = V_SYNC + V_BACK + V_VALID + V_FRONT;  


reg [9:0] cnt_h;  
reg [9:0] cnt_v;  
wire pixel_valid; 
wire pix_pre_req; 


always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) cnt_h <= 10'd0;
    else cnt_h <= (cnt_h == H_TOTAL - 1'd1) ? 10'd0 : cnt_h + 1'd1;
end


always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) cnt_v <= 10'd0;
    else if (cnt_h == H_TOTAL - 1'd1) begin
        cnt_v <= (cnt_v == V_TOTAL - 1'd1) ? 10'd0 : cnt_v + 1'd1;
    end
end


assign hsync = (cnt_h < H_SYNC) ? 1'b0 : 1'b1;
assign vsync = (cnt_v < V_SYNC) ? 1'b0 : 1'b1;


assign pixel_valid = (cnt_h >= H_SYNC + H_BACK) && (cnt_h < H_SYNC + H_BACK + H_VALID)
                  && (cnt_v >= V_SYNC + V_BACK) && (cnt_v < V_SYNC + V_BACK + V_VALID);


assign pix_pre_req = (cnt_h >= H_SYNC + H_BACK - 1'd1) && (cnt_h < H_SYNC + H_BACK + H_VALID - 1'd1)
                  && (cnt_v >= V_SYNC + V_BACK) && (cnt_v < V_SYNC + V_BACK + V_VALID);


assign pix_x = pix_pre_req ? (cnt_h - (H_SYNC + H_BACK - 1'd1)) : 10'd0;
assign pix_y = pix_pre_req ? (cnt_v - (V_SYNC + V_BACK)) : 10'd0;


assign rgb = pixel_valid ? pix_data : 16'h0000;

endmodule

