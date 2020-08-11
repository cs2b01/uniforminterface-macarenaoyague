`timescale 1ns/1ns
module TFF_tb;
    reg prn, t, clk, clrn;
    wire q, qn;
    TFF tflipflop(prn, t, clk, clrn, q, qn);
    initial begin
        clk = 1;
        clrn = 0;
        prn = 0;
        t = 1;
        $monitor("%d ns:\tprn=%b  t=%b  clk=%b  clrn=%b  q=%b  qn=%b", 
                 $time, prn, t, clk, clrn, q, qn);
        #20 $finish;
    end
    always #1 clk = !clk;
    always #1 clrn = 1;
    always #1 prn = 1;
    always #2 t = !t;
    initial begin
        $dumpfile("TFF.vcd");
        $dumpvars;
    end
endmodule