`timescale 1ns/1ps
module state_machine_vga(
    input wire sys_clk,
    input wire sys_rst_n,
    input wire chan,
    output reg [1:0] state_out
);

parameter STATE_IDLE    = 2'd0;
parameter STATE_BAR     = 2'd1;
parameter STATE_CHAR    = 2'd2;
parameter STATE_CUSTOM  = 2'd3;

reg [1:0] st_current;
reg [1:0] st_next_state;

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        st_current <= STATE_IDLE;
    end else begin
        st_current <= st_next_state;
    end
end

always @(*) begin
    case (st_current)
        STATE_IDLE: begin
            if (chan) st_next_state = STATE_BAR;
            else st_next_state = STATE_IDLE;
        end
        STATE_BAR: begin
            if (!sys_rst_n) st_next_state = STATE_IDLE;
            else if (chan) st_next_state = STATE_CHAR;
            else st_next_state = STATE_BAR;
        end
        STATE_CHAR: begin
            if (!sys_rst_n) st_next_state = STATE_IDLE;
            else if (chan) st_next_state = STATE_CUSTOM;
            else st_next_state = STATE_CHAR;
        end
        STATE_CUSTOM: begin
            if (!sys_rst_n) st_next_state = STATE_IDLE;
            else if (chan) st_next_state = STATE_BAR;
            else st_next_state = STATE_CUSTOM;
        end
        default: st_next_state = STATE_IDLE;
    endcase
end

always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        state_out <= STATE_IDLE;
    end else begin
        state_out <= st_current;
    end
end

endmodule