module One_bit_Digital_Comparator(
input a, b,
output a_lt_b, a_eq_b, a_gt_b
);

assign a_lt_b =  ~a & b;

assign a_eq_b =  ~(a ^ b);

assign a_gt_b =  a & ~b;

endmodule
