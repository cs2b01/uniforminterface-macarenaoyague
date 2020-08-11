`timescale 1ns/1ns
module DFF_tb;
    reg d, clk, clrn;
    wire q;
    DFF_behavioral dff(d, clk, clrn, q);
    initial begin
        clk = 1;
        d = 0;
        clrn = 1;
        $monitor("%d ns:\td=%h\tclk=%h\tclrn=%h\tq=%h", 
                 $time, d, clk, clrn, q);
        #20 $finish;
    end
    always #1 d =! d;
    always #2 clk =! clk;
    always #4 clrn =! clrn;
    initial begin
        $dumpfile("DFF_behavioral.vcd");
        $dumpvars;
    end
endmodule