`timescale 1ns/1ps
module vga_pic(
    input wire vga_clk,
    input wire sys_rst_n,
    input wire key_s,
    input wire key_d,
    input wire [9:0] pix_x,
    input wire [9:0] pix_y,
    output reg [15:0] pix_data
);

parameter CHAR_WIDTH    = 10'd32;
parameter CHAR_HEIGHT   = 10'd32;
parameter BYTE_PER_ROW  = 4;
parameter NUM_CHARS     = 4;
parameter TOTAL_WIDTH   = NUM_CHARS * CHAR_WIDTH;
parameter CHAR_TOTAL_BYTES = CHAR_HEIGHT * BYTE_PER_ROW;

parameter H_VALID = 10'd640;
parameter V_VALID = 10'd480;
parameter START_X = (H_VALID - TOTAL_WIDTH) / 2;
parameter START_Y = (V_VALID - CHAR_HEIGHT) / 2;

parameter RED     = 16'hF800;
parameter GREEN   = 16'h07E0;
parameter BLUE    = 16'h001F;
parameter BLACK   = 16'h0000;

parameter [7:0] CHAR_DATA [0:511] = {
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'hF8,8'h1F,8'h00,8'h00, 8'h78,8'h3E,8'h00,8'h00,
    8'h78,8'h3E,8'h00,8'h00, 8'h78,8'h3E,8'h00,8'h00, 8'h7C,8'h3E,8'h00,8'h00, 8'h7C,8'h7E,8'h00,8'h00,
    8'h7C,8'h7E,8'h00,8'h00, 8'h7C,8'h7E,8'h00,8'h00, 8'h7E,8'h7E,8'h00,8'h00, 8'h7E,8'h7E,8'h00,8'h00,
    8'h7E,8'hFE,8'h00,8'h00, 8'h6E,8'hFE,8'h00,8'h00, 8'h6E,8'hFE,8'h00,8'h00, 8'h6F,8'hDE,8'h00,8'h00,
    8'h6F,8'hDE,8'h00,8'h00, 8'h6F,8'hDE,8'h00,8'h00, 8'h67,8'hDE,8'h00,8'h00, 8'h67,8'h9E,8'h00,8'h00,
    8'h67,8'h9E,8'h00,8'h00, 8'h67,8'h9E,8'h00,8'h00, 8'h73,8'h9E,8'h00,8'h00, 8'hFB,8'h7F,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,

    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'hFE,8'h3F,8'h00,8'h00, 8'h7C,8'h1E,8'h00,8'h00,
    8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 
    8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00,
    8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 
    8'h78,8'h0C,8'h00,8'h00, 8'h78,8'h0C,8'h00,8'h00, 8'h38,8'h0C,8'h00,8'h00, 8'h38,8'h0C,8'h00,8'h00,
    8'h3C,8'h1C,8'h00,8'h00, 8'h1F,8'h3C,8'h00,8'h00, 8'h0F,8'hF8,8'h00,8'h00, 8'h00,8'hF0,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,

    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h1F,8'hFC,8'h00,8'h00, 8'h3E,8'hFC,8'h00,8'h00,
    8'h38,8'h3C,8'h00,8'h00, 8'h70,8'h1C,8'h00,8'h00, 8'h70,8'h1C,8'h00,8'h00, 8'h70,8'h0C,8'h00,8'h00,
    8'h78,8'h00,8'h00,8'h00, 8'h7C,8'h00,8'h00,8'h00, 8'h3F,8'h00,8'h00,8'h00, 8'h3F,8'hC0,8'h00,8'h00,
    8'h0F,8'hF0,8'h00,8'h00, 8'h03,8'hF8,8'h00,8'h00, 8'h00,8'hFC,8'h00,8'h00, 8'h00,8'h3C,8'h00,8'h00,
    8'h00,8'h1E,8'h00,8'h00, 8'h60,8'h1E,8'h00,8'h00, 8'h60,8'h0E,8'h00,8'h00, 8'h70,8'h1E,8'h00,8'h00,
    8'h70,8'h1E,8'h00,8'h00, 8'h78,8'h3C,8'h00,8'h00, 8'h7F,8'hF8,8'h00,8'h00, 8'h7F,8'hF0,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,

    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h7F,8'hFE,8'h00,8'h00, 8'h7B,8'hDE,8'h00,8'h00,
    8'h73,8'hCE,8'h00,8'h00, 8'hE3,8'hC6,8'h00,8'h00, 8'hE3,8'hC7,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00,
    8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00,
    8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00,
    8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00,
    8'h03,8'hC0,8'h00,8'h00, 8'h03,8'hC0,8'h00,8'h00, 8'h0F,8'hF0,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00,
    8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00, 8'h00,8'h00,8'h00,8'h00
};

reg [15:0] char_color;
reg [6:0] rel_x;
reg [4:0] rel_y;
reg [1:0] char_index;
reg [4:0] pix_x_in;
reg [4:0] pix_y_rel;
reg [1:0] byte_idx;
reg [8:0] addr;
reg [7:0] char_byte;
reg [2:0] bit_sel;
reg bit_val;
reg in_char_area;

always @* begin
    rel_x = 7'd0;
    rel_y = 5'd0;
    char_index = 2'd0;
    pix_x_in = 5'd0;
    pix_y_rel = 5'd0;
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
        char_index = rel_x[6:5];
        pix_x_in = rel_x[4:0];
        pix_y_rel = rel_y[4:0];
        byte_idx = pix_x_in[4:3];
        addr = $unsigned(char_index) * $unsigned(CHAR_TOTAL_BYTES) + 
               $unsigned(pix_y_rel) * $unsigned(BYTE_PER_ROW) + 
               $unsigned(byte_idx);
        char_byte = CHAR_DATA[addr];
        bit_sel = 3'd7 - pix_x_in[2:0];
        bit_val = char_byte[bit_sel];
    end
end

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        char_color <= RED;
    end else if (key_s) begin
        char_color <= (char_color == RED) ? GREEN : 
                      (char_color == GREEN) ? BLUE : RED;
    end
end

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        pix_data <= BLACK;
    end else if (in_char_area) begin
        pix_data <= bit_val ? char_color : BLACK;
    end else begin
        pix_data <= BLACK;
    end
end

endmodule
