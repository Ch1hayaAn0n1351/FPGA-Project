`timescale 1ns/1ps
module syncGen(
    input wire vga_clk,
	 input wire sys_rst_n,
	 input wire [15:0] pix_data,
	 output wire [9:0] pix_x,
	 output wire [9:0] pix_y,
	 output wire hsync,
	 output wire vsync,
	 output wire [15:0] rgb
);

parameter H_SYNC    = 10'd96;
parameter H_BACK    = 10'd40;
parameter H_LEFT    = 10'd8;
parameter H_VALID   = 10'd640;
parameter H_RIGHT   = 10'd8;
parameter H_FRONT   = 10'd8;
parameter H_TOTAL   = 10'd800;
parameter V_SYNC    = 10'd2;
parameter V_BACK    = 10'd25;
parameter V_TOP     = 10'd8;
parameter V_VALID   = 10'd480;
parameter V_BOTTOM  = 10'd8;
parameter V_FRONT   = 10'd2;
parameter V_TOTAL   = 10'd525;

wire rgb_valid;
wire pix_data_req;
reg [9:0] cnt_h;
reg [9:0] cnt_v;

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) cnt_h <= 10'd0;
    else if (cnt_h == H_TOTAL - 1'd1) cnt_h <= 10'd0;
    else cnt_h <= cnt_h + 1'd1;
end

assign hsync = (cnt_h <= H_SYNC - 1'd1) ? 1'b1 : 1'b0;

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) cnt_v <= 10'd0;
    else if ((cnt_v == V_TOTAL - 1'd1) && (cnt_h == H_TOTAL - 1'd1)) cnt_v <= 10'd0;
    else if (cnt_h == H_TOTAL - 1'd1) cnt_v <= cnt_v + 1'd1;
    else cnt_v <= cnt_v;
end

assign vsync = (cnt_v <= V_SYNC - 1'd1) ? 1'b1 : 1'b0;

assign rgb_valid = (cnt_h >= H_SYNC + H_BACK + H_LEFT) && 
                   (cnt_h < H_SYNC + H_BACK + H_LEFT + H_VALID) &&
                   (cnt_v >= V_SYNC + V_BACK + V_TOP) && 
                   (cnt_v < V_SYNC + V_BACK + V_TOP + V_VALID);

assign pix_data_req = (cnt_h >= H_SYNC + H_BACK + H_LEFT - 1'd1) && 
                      (cnt_h < H_SYNC + H_BACK + H_LEFT + H_VALID - 1'd1) &&
                      (cnt_v >= V_SYNC + V_BACK + V_TOP) && 
                      (cnt_v < V_SYNC + V_BACK + V_TOP + V_VALID);

assign pix_x = pix_data_req ? (cnt_h - (H_SYNC + H_BACK + H_LEFT - 1'd1)) : 10'h3ff;
assign pix_y = pix_data_req ? (cnt_v - (V_SYNC + V_BACK + V_TOP)) : 10'h3ff;

assign rgb = rgb_valid ? pix_data : 16'b0;

endmodule
    //output hsync, vsync, inDispArea,
    //output [9:0] hcount, vcount
    //);
    //reg hsync, vsync, hblank, vblank, inDispArea, inDispAreaX, inDispAreaY;
    //reg[9:0] hcount, vcount;
    //
    //wire hson, hsoff, hreset, hblankon;
    //wire vson, vsoff, vreset, vblankon;
    
    //assign hblankon = hcount == 639;
    //assign hson = hcount == 652;
    //assign hsoff = hcount == 746;
    //assign hreset = hcount == 793;
    
    //assign vblankon = hreset & (vcount == 479);
    //assign vson = hreset & (vcount == 492);
    //assign vsoff = hreset & (vcount == 494);
    //assign vreset = hreset & (vcount == 527);

    //always @(posedge clock) begin
        //inDispAreaX <= hreset ? 1 : hblankon ? 0 : inDispAreaX;
        //inDispAreaY <= vreset ? 1 : vblankon ? 0 : inDispAreaY;
        //inDispArea <= inDispAreaX & inDispAreaY;
    
        //hcount <= hreset ? 0 : hcount + 1;
        //hblank <= hreset ? 0 : hblankon ? 1 : hblank;
       // hsync <= hson ? 0 : hsoff ? 1 : hsync;
        
        //vcount <= hreset ? (vreset ? 0: vcount + 1): vcount;
        //vblank <= vreset ? 0 : vblankon ? 1 : vblank;
        //vsync <= vson ? 0 : vsoff ? 1 : vsync;

