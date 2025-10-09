module Running_light
(
 input wire sys_clk, 
 input wire reset,
 output reg [3:0] led
 );
 reg [24:0] cnt;
 
always @(posedge sys_clk or negedge reset) begin
   if (reset == 1'b0)
	   cnt <= 0;
   else if (cnt == 25'd24_999_999)
	   cnt <= 0;
	else
	   cnt = cnt + 1'b1;
end

always @(posedge sys_clk or negedge reset) begin
   if (reset == 1'b0) begin
	   led[0] <= 1'b0;
		led[1] <= 1'b1;
		led[2] <= 1'b1;
		led[3] <= 1'b1;
	end
	else if(cnt == 25_000_000 - 1)
	   led <= {led[2:0], led[3]};
end

endmodule
