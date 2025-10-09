module counter( 
input wire sys_clk,
input wire reset,
output reg led1
);
reg [24:0] cnt;

always @(posedge sys_clk or negedge reset) begin
   if (reset == 1'b0)
      cnt <= 0;
	else if (cnt == 25'd24_999_999)
	   cnt <= 0;
   else
      cnt <= cnt + 1'b1;
end

always @(posedge sys_clk or negedge reset) begin
	if (reset == 1'b0)
      led1 <= 1'b1;	
   else if(cnt == 25_000_000 - 1)
      led1 <= ~led1;
end
	
endmodule
