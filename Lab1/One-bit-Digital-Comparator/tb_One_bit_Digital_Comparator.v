`timescale 1ns/1ns

module tb_One_bit_Digital_Comparator;

    // 输入信号
    reg a;
    reg b;

    // 输出信号
    wire a_gt_b;
    wire a_eq_b;
    wire a_lt_b;


    // 实例化DUT
    One_bit_Digital_Comparator uut (
        .a(a),
        .b(b),
        .a_gt_b(a_gt_b),
        .a_eq_b(a_eq_b),
        .a_lt_b(a_lt_b)
    );

    // 产生测试激励
    initial begin
        // 初始化输入
        a = 0;
        b = 0;
        #10;

        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;

        // 结束仿真
        $stop;
    end

    // 监控输出
    initial begin
        $monitor("Time = %0t, a = %b, b = %b, a_gt_b = %b, a_eq_b = %b, a_lt_b = %b",
                  $time, a, b, a_gt_b, a_eq_b, a_lt_b);
    end

endmodule