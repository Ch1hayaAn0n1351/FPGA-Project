`timescale 1ns/1ns

module tb_counter;

reg sys_clk, reset;

wire led1;

counter counter_inst(
.sys_clk(sys_clk),
.reset(reset),
.led1(led1)
);

initial begin
sys_clk = 1'b0;

forever #10 sys_clk = ~sys_clk;

reset = 1'b1;

#100_000_000;

$stop;

end

endmodule
