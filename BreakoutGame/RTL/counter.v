// Time unit: 1 nanosecond, Time precision: 1 picosecond
`timescale 1ns/1ps

/**
 * Module: counter
 * Function: A simple 24-bit unsigned up-counter triggered by the positive edge of the input clock.
 *           The counter increments its output value by 1 on each rising edge of the clock signal.
 * Port List:
 *   - Input:  clock  - Clock signal for triggering counter increment (rising edge sensitive)
 *   - Output: out    - 24-bit wide counter output value (updated on clock positive edge)
 */
module counter(clock, out);
    // Input port: Clock signal for counter synchronization
    input clock;
    
    // Output port: 24-bit counter result
    output [23:0] out;
    
    // Register to hold the counter value (sequential logic storage)
    reg[23:0] out;
    
    /**
     * Sequential Logic Block:
     * Triggered on the positive edge of the clock signal.
     * Updates the counter value by incrementing the current value by 1 (non-blocking assignment for sequential logic).
     */
    always @(posedge clock) out <= out + 1;
endmodule
