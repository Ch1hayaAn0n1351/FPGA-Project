`timescale 1ns/1ps
module counter(clock, out);
    input clock;
    output [23:0] out;
    reg[23:0] out;
    always @(posedge clock) out <= out + 1;
endmodule
