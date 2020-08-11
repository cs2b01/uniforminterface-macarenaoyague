`timescale 1ns/1ns
module JKFF_tb;
    reg prn, j, k, clk, clrn;
    wire q, qn;
    JKFF jkflipflop(prn, j, k, clk, clrn, q, qn);
    initial begin
        clk = 1;
        clrn = 0;
        prn = 0;
        j = 1;
        k = 1;
        $monitor("%d ns:\tprn=%b  j=%b  k=%b  clk=%b  clrn=%b  q=%b  qn=%b", 
                 $time, prn, j, k, clk, clrn, q, qn);
        #20 $finish;
    end
    always #1 clk = !clk;
    always #1 clrn = 1;
    always #1 prn = 1;
    always #2 j = !j;
    always #4 k = !k;
    initial begin
        $dumpfile("JKFF.vcd");
        $dumpvars;
    end
endmodule