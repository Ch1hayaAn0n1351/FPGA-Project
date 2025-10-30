`timescale 1ns/1ps
module state_machine_vga(
    input wire sys_clk,
    input wire sys_rst_n,
    input wire chan,
    output reg [1:0] state_out
);

parameter STATE_BAR     = 2'd1;
parameter STATE_CHAR    = 2'd2;
parameter STATE_CUSTOM  = 2'd3;

reg [1:0] st_current;
reg [1:0] st_next_state;
reg chan_d1;
wire chan_trig;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        chan_d1 <= 1'b0;
    else
        chan_d1 <= chan;
end
assign chan_trig = chan & ~chan_d1;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        st_current <= STATE_BAR;
    else
        st_current <= st_next_state;
end

always @(*) begin
    case (st_current)
        STATE_BAR:
            st_next_state = chan_trig ? STATE_CHAR : STATE_BAR;
        STATE_CHAR:
            st_next_state = chan_trig ? STATE_CUSTOM : STATE_CHAR;
        STATE_CUSTOM:
            st_next_state = chan_trig ? STATE_BAR : STATE_CUSTOM;
        default:
            st_next_state = STATE_BAR;
    endcase
end

always @(*) begin
    if (!sys_rst_n) begin
        state_out = STATE_BAR;
    end else begin
        state_out = chan_trig ? st_next_state : st_current;
    end
end

endmodule

