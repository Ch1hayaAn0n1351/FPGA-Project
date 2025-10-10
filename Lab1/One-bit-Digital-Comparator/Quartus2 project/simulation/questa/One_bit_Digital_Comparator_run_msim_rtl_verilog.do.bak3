transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/FPGA\ Project/One_bit_Digital_Comparator/RTL {D:/FPGA Project/One_bit_Digital_Comparator/RTL/One_bit_Digital_Comparator.v}

vlog -vlog01compat -work work +incdir+D:/FPGA\ Project/One_bit_Digital_Comparator/Quartus2\ project/../Sim {D:/FPGA Project/One_bit_Digital_Comparator/Quartus2 project/../Sim/tb_One_bit_Digital_Comparator.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_One_bit_Digital_Comparator

add wave *
view structure
view signals
run 1 ms
