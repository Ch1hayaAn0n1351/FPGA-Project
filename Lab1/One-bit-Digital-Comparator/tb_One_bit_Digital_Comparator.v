`timescale 1ns/1ns

module tb_One_bit_Digital_Comparator;

    reg a, b;

    wire a_gt_b, a_eq_b, a_lt_b;

    One_bit_Digital_Comparator uut (
        .a(a),
        .b(b),
        .a_gt_b(a_gt_b),
        .a_eq_b(a_eq_b),
        .a_lt_b(a_lt_b)
    );

    initial begin
        a = 0; b = 0; #10;
        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;

        $stop;
    end

    initial begin
        $monitor("Time = %0t, a = %b, b = %b, a_gt_b = %b, a_eq_b = %b, a_lt_b = %b", $time, a, b, a_gt_b, a_eq_b, a_lt_b);
    end


endmodule
