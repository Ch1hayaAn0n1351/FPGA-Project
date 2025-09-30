`timescale 1ns/1ns

module tb_FULLADDER;
    reg A, B, Cin;
    wire Sum, Cout;
    
    FULLADDER adder (
        .A(A),
        .B(B), 
        .Cin(Cin),
        .Sum(Sum),
        .Cout(Cout)
    );
    
    initial begin
     
        A = 0; B = 0; Cin = 0;
        
        $display("=== Full Adder Simulation Started ===");
        

        #100 A=0; B=0; Cin=0;
        #100 A=0; B=0; Cin=1;
        #100 A=0; B=1; Cin=0;
        #100 A=0; B=1; Cin=1;
        #100 A=1; B=0; Cin=0;
        #100 A=1; B=0; Cin=1;
        #100 A=1; B=1; Cin=0;
        #100 A=1; B=1; Cin=1;
        
        #100 $display("=== Simulation Finished ===");
        $finish;
    end
    
    initial begin
        $monitor("Time=%0t: A=%b B=%b Cin=%b -> Sum=%b Cout=%b", 
                 $time, A, B, Cin, Sum, Cout);
    end
endmodule