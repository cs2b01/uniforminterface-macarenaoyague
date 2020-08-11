`timescale 1ns/1ns
module DFF_tb;
    reg d, clk, clr;
    wire q;
    DFF dff(d, clk, clr, q);
    initial begin
        clk = 1;
        d = 0;
        clr = 0;
        $monitor("%d ns:\td=%h\tclk=%h\tclr=%h\tq=%h", 
                 $time, d, clk, clr, q);
        #20 $finish;
    end
    always #1 d =! d;
    always #2 clk =! clk;
    always #4 clr =! clr;
    initial begin
        $dumpfile("DFF.vcd");
        $dumpvars;
    end
endmodule