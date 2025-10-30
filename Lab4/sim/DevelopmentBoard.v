`timescale 1ns/1ps
module DevelopmentBoard(
    input wire clk,      
    input wire reset,    
    input wire B2,       
    input wire B3,       
    input wire B4,       
    input wire B5,       
    output wire h_sync,  
    output wire v_sync, 
    output wire [15:0] rgb,  
    output wire led1,    
    output wire led2,   
    output wire led3,    
    output wire led4,    
    output wire led5     
);


assign led1 = reset;       
assign led2 = B2;          
assign led3 = B3;         
assign led4 = B4;          
assign led5 = B5;          


ColorBar ColorBar_inst(
    .sys_clk(clk),
    .sys_rst_n(reset),      
    .key_s(!B2),            
    .key_d(!B3),            
    .key_f(!B4),
    .key_g(!B5),
    .hsync(h_sync),
    .vsync(v_sync),
    .rgb(rgb)
);

endmodule

