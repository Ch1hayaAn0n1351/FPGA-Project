`timescale 1ns/1ps
module state_machine_final(
    input wire sys_clk,
    input wire sys_rst_n,
    input wire chan,
    output reg [1:0] state_out
);

// 状态定义 - 统一使用新名称
parameter STATE_BAR     = 2'd1;   // 对应原来的IDLE/P01
parameter STATE_CHAR    = 2'd2;   // 对应原来的P02  
parameter STATE_CUSTOM  = 2'd3;   // 对应原来的P03
// 注：可以根据需要调整状态值

reg [1:0] st_current;
reg [1:0] st_next_state;

// 完整的防抖动逻辑
reg [19:0] debounce_cnt;    // 防抖计数器（20ms @ 10MHz）
reg chan_sync;              // 同步后的按钮信号
reg chan_d1;                // 延迟一拍的信号
wire chan_trig;             // 防抖后的触发信号

// 按钮同步和防抖逻辑
always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        chan_sync <= 1'b0;
        debounce_cnt <= 20'd0;
        chan_d1 <= 1'b0;
    end else begin
        // 延迟一拍用于边沿检测
        chan_d1 <= chan_sync;
        
        // 防抖逻辑：当按钮状态变化时开始计时
        if (chan != chan_sync) begin
            if (debounce_cnt == 20'd199999) begin  // 20ms防抖
                chan_sync <= chan;                // 稳定后更新同步信号
                debounce_cnt <= 20'd0;
            end else begin
                debounce_cnt <= debounce_cnt + 1'b1;
            end
        end else begin
            debounce_cnt <= 20'd0;  // 状态稳定时清零计数器
        end
    end
end

// 使用防抖后的信号进行边沿检测
assign chan_trig = chan_sync & ~chan_d1;

// 状态寄存器
always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        st_current <= STATE_BAR;
    else
        st_current <= st_next_state;
end

// 状态转移逻辑
always @(*) begin
    case (st_current)
        STATE_BAR: begin
            if (chan_trig) 
                st_next_state = STATE_CHAR;
            else 
                st_next_state = STATE_BAR;
        end
        STATE_CHAR: begin
            if (chan_trig) 
                st_next_state = STATE_CUSTOM;
            else 
                st_next_state = STATE_CHAR;
        end
        STATE_CUSTOM: begin
            if (chan_trig) 
                st_next_state = STATE_BAR;
            else 
                st_next_state = STATE_CUSTOM;
        end
        default: 
            st_next_state = STATE_BAR;
    endcase
end

// 输出逻辑
always @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        state_out <= STATE_BAR;
    else
        state_out <= st_current;
end

endmodule
