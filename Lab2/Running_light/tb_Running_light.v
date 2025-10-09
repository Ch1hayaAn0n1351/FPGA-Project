`timescale 1ns/1ns

module tb_Running_light;

reg sys_clk, reset;

wire [3:0] led;

Running_light Running_light_inst(
.sys_clk(sys_clk),
.reset(reset),
.led(led)
);

initial begin 
sys_clk = 1'b0;

forever #10 sys_clk = ~sys_clk;

reset = 1'b1;

#100_000_000;

$stop;

end

endmodule
