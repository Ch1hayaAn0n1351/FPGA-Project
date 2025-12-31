// Time unit: 1 nanosecond, Time precision: 1 picosecond
`timescale 1ns/1ps

/**
 * Module: syncGen
 * Function: Generates VGA (Video Graphics Array) timing signals including horizontal sync (hsync),
 *           vertical sync (vsync), pixel counters (hcount/vcount), and a display area flag (inDispArea).
 *           Implements standard VGA timing parameters to control video output rendering.
 * Port List:
 *   - Input:  clock   - Pixel clock signal for VGA timing synchronization
 *   - Output: hsync   - Horizontal sync signal (low-active for VGA standard timing)
 *   - Output: vsync   - Vertical sync signal (low-active for VGA standard timing)
 *   - Output: inDispArea - High when current pixel is within the visible display area
 *   - Output: hcount  - 10-bit horizontal pixel counter (tracks column position of current pixel)
 *   - Output: vcount  - 10-bit vertical pixel counter (tracks row position of current pixel)
 */
module syncGen(clock, hsync, vsync, hcount, vcount, inDispArea);
    // Input port: VGA pixel clock
    input clock;
    
    // Output ports: VGA control signals and pixel counters
    output hsync, vsync, inDispArea;
    output [9:0] hcount, vcount;
    
    // Internal register declarations for sequential logic state
    // Sync signals, blanking signals, display area flags, and pixel counters
    reg hsync, vsync, hblank, vblank, inDispArea, inDispAreaX, inDispAreaY;
    reg[9:0] hcount, vcount;
    
    // Internal wire declarations for timing threshold trigger conditions
    // Horizontal timing thresholds (pixel column triggers)
    wire hson, hsoff, hreset, hblankon;
    // Vertical timing thresholds (pixel row triggers, synchronized with horizontal reset)
    wire vson, vsoff, vreset, vblankon;
    
    /**
     * Horizontal Timing Assignment (VGA Column Control):
     * - hblankon: Trigger to start horizontal blanking (end of visible horizontal pixels)
     * - hson:     Trigger to assert horizontal sync (start of hsync pulse)
     * - hsoff:    Trigger to deassert horizontal sync (end of hsync pulse)
     * - hreset:   Trigger to reset horizontal counter (end of horizontal line, wrap to next column)
     */
    assign hblankon = hcount == 639;
    assign hson = hcount == 652;
    assign hsoff = hcount == 746;
    assign hreset = hcount == 793;
    
    /**
     * Vertical Timing Assignment (VGA Row Control):
     * All vertical triggers are synchronized with hreset (end of horizontal line) to ensure row alignment
     * - vblankon: Trigger to start vertical blanking (end of visible vertical pixels)
     * - vson:     Trigger to assert vertical sync (start of vsync pulse)
     * - vsoff:    Trigger to deassert vertical sync (end of vsync pulse)
     * - vreset:   Trigger to reset vertical counter (end of frame, wrap to next row)
     */
    assign vblankon = hreset & (vcount == 479);
    assign vson = hreset & (vcount == 492);
    assign vsoff = hreset & (vcount == 494);
    assign vreset = hreset & (vcount == 527);

    /**
     * Sequential Logic Block: VGA Timing State Machine
     * Triggered on the positive edge of the pixel clock.
     * Updates pixel counters, sync signals, blanking signals, and display area flags per VGA timing standards.
     */
    always @(posedge clock) begin
        // Update horizontal/vertical display area flags and composite display area flag
        inDispAreaX <= hreset ? 1 : hblankon ? 0 : inDispAreaX;
        inDispAreaY <= vreset ? 1 : vblankon ? 0 : inDispAreaY;
        inDispArea <= inDispAreaX & inDispAreaY;
    
        // Update horizontal counter and horizontal control signals (blanking, sync)
        hcount <= hreset ? 0 : hcount + 1;
        hblank <= hreset ? 0 : hblankon ? 1 : hblank;
        hsync <= hson ? 0 : hsoff ? 1 : hsync;
        
        // Update vertical counter and vertical control signals (blanking, sync)
        // Vertical counter only increments when horizontal counter resets (end of line)
        vcount <= hreset ? (vreset ? 0: vcount + 1): vcount;
        vblank <= vreset ? 0 : vblankon ? 1 : vblank;
        vsync <= vson ? 0 : vsoff ? 1 : vsync;
    end
endmodule
