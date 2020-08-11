`timescale 1ns/1ns
module DFF_tb;
    reg d, clk, clrn;
    wire q;
    DFF dff(d, clk, clrn, q);
    initial begin
        clk = 0;
        d = 0;
        clrn = 1;
        $monitor("%d ns:\td=%h\tclk=%h\tclrn=%h\tq=%h", 
                 $time, d, clk, clrn, q);
        #15 $finish;
    end
    always #1 clk =! clk;
    always #2 d =! d;
    always #4 clrn =! clrn;
    initial begin
        $dumpfile("DFF.vcd");
        $dumpvars;
    end
endmodule