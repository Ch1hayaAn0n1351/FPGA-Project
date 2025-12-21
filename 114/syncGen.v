`timescale 1ns/1ps
module syncGen(
    input clock,          // 25MHz VGA时钟
    output reg hsync, vsync, inDispArea,
    output reg [9:0] hcount, vcount
);

// VGA 640x480@60Hz标准时序参数
parameter H_TOTAL = 10'd800;  // 行总像素
parameter H_SYNC  = 10'd96;   // 行同步脉宽
parameter H_BACK  = 10'd40;   // 行后沿
parameter H_VALID = 10'd640;  // 行有效像素
parameter V_TOTAL = 10'd525;  // 场总行数
parameter V_SYNC  = 10'd2;    // 场同步脉宽
parameter V_BACK  = 10'd25;   // 场后沿
parameter V_VALID = 10'd480;  // 场有效行数

// 行计数器
always @(posedge clock) begin
    if(hcount == H_TOTAL - 1'd1) begin
        hcount <= 10'd0;
    end else begin
        hcount <= hcount + 1'd1;
    end
end

// 场计数器（行计数清零时更新）
always @(posedge clock) begin
    if(hcount == H_TOTAL - 1'd1) begin
        if(vcount == V_TOTAL - 1'd1) begin
            vcount <= 10'd0;
        end else begin
            vcount <= vcount + 1'd1;
        end
    end
end

// 行同步信号（低有效）
always @(posedge clock) begin
    hsync <= (hcount < H_SYNC) ? 1'b0 : 1'b1;
end

// 场同步信号（低有效）
always @(posedge clock) begin
    vsync <= (vcount < V_SYNC) ? 1'b0 : 1'b1;
end

// 有效显示区标识
always @(posedge clock) begin
    inDispArea <= (hcount >= H_SYNC + H_BACK) && (hcount < H_SYNC + H_BACK + H_VALID) &&
                  (vcount >= V_SYNC + V_BACK) && (vcount < V_SYNC + V_BACK + V_VALID);
end

endmodule