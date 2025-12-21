`timescale 1ns/1ps
module counter(
    input wire clock,    // 输入时钟（如25MHz VGA时钟）
    output reg [23:0] out // 分频输出（取最低位作为帧更新时钟）
);
// 初始化
initial begin
    out <= 24'd0;
end

// 计数器逻辑：每时钟周期自增
always @(posedge clock) begin
    out <= out + 1'b1;
end
endmodule