`timescale 1ns/1ps
module vga_pic(
    input wire vga_clk,
    input wire sys_rst_n,
    input wire [9:0] pix_x,
    input wire [9:0] pix_y,
    output reg [15:0] pix_data
);

parameter CHAR_WIDTH    = 10'd64;
parameter CHAR_HEIGHT   = 10'd64;
parameter BYTE_PER_ROW  = 2;
parameter NUM_CHARS     = 3;
parameter TOTAL_WIDTH   = NUM_CHARS * CHAR_WIDTH;
parameter CHAR_TOTAL_BYTES = 16 * BYTE_PER_ROW;

parameter H_VALID = 10'd640;
parameter V_VALID = 10'd480;
parameter BASE_X  = (H_VALID - TOTAL_WIDTH) / 2;
parameter X_OFFSET = 10'd100;
parameter START_X = BASE_X + X_OFFSET;
parameter START_Y = (V_VALID - CHAR_HEIGHT) / 2;

parameter WHITE     = 16'hFFFF;
parameter BLACK     = 16'h0000;

parameter [7:0] CHAR_DATA [0:95] = {
    8'h00,8'h00, 8'h00,8'h00, 8'h00,8'h00, 8'hFC,8'h00,
    8'h42,8'h00, 8'h48,8'h00, 8'h48,8'h00, 8'h78,8'h00,
    8'h48,8'h00, 8'h48,8'h00, 8'h40,8'h00, 8'h42,8'h00,
    8'h42,8'h00, 8'hFC,8'h00, 8'h00,8'h00, 8'h00,8'h00,

    8'h00,8'h00, 8'h00,8'h00, 8'h00,8'h00, 8'hC7,8'h00,
    8'h62,8'h00, 8'h62,8'h00, 8'h52,8'h00, 8'h52,8'h00,
    8'h4A,8'h00, 8'h4A,8'h00, 8'h4A,8'h00, 8'h46,8'h00,
    8'h46,8'h00, 8'hE2,8'h00, 8'h00,8'h00, 8'h00,8'h00,

    8'h00,8'h00, 8'h00,8'h00, 8'h00,8'h00, 8'hF8,8'h00,
    8'h44,8'h00, 8'h42,8'h00, 8'h42,8'h00, 8'h42,8'h00,
    8'h42,8'h00, 8'h42,8'h00, 8'h42,8'h00, 8'h44,8'h00,
    8'hF8,8'h00, 8'h00,8'h00, 8'h00,8'h00, 8'h00,8'h00
};

reg [15:0] char_color;
reg [7:0] rel_x;
reg [6:0] rel_y;
reg [1:0] char_index;
reg [4:0] orig_x;
reg [4:0] orig_y;
reg [1:0] byte_idx;
reg [8:0] addr;
reg [7:0] char_byte;
reg [2:0] bit_sel;
reg bit_val;
reg in_char_area;

always @* begin
    rel_x = 8'd0;
    rel_y = 7'd0;
    char_index = 2'd0;
    orig_x = 5'd0;
    orig_y = 5'd0;
    byte_idx = 2'd0;
    addr = 9'd0;
    char_byte = 8'd0;
    bit_sel = 3'd0;
    bit_val = 1'b0;
    in_char_area = 1'b0;

    if ((pix_x >= START_X) && (pix_x < START_X + TOTAL_WIDTH) &&
        (pix_y >= START_Y) && (pix_y < START_Y + CHAR_HEIGHT)) begin
        in_char_area = 1'b1;
        rel_x = pix_x - START_X;
        rel_y = pix_y - START_Y;

        char_index = rel_x[7:6];
        orig_x = {1'b0, rel_x[5:2]};
        orig_y = {1'b0, rel_y[5:2]};
        byte_idx = orig_x[4:3];

        addr = $unsigned(char_index) * $unsigned(CHAR_TOTAL_BYTES) + 
               $unsigned(orig_y) * $unsigned(BYTE_PER_ROW) + 
               $unsigned(byte_idx);
        char_byte = CHAR_DATA[addr];
        bit_sel = 3'd7 - orig_x[2:0];
        bit_val = char_byte[bit_sel];
    end
end

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        char_color <= BLACK;
    end
end

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        pix_data <= WHITE;
    end else if (in_char_area) begin
        pix_data <= bit_val ? char_color : WHITE;
    end else begin
        pix_data <= WHITE;
    end
end

endmodule

