`timescale 1ns/1ns
module DFF_tb;
    reg d, we, clr;
    wire q;
    DFF dff(d, we, clr, q);
    initial begin
        we = 0;
        d = 1;
        clr = 1;
        $monitor("%d ns:\td=%h\tclk=%h\tclr=%h\tq=%h", 
                 $time, d, we, clr, q);
        #5 $finish;
    end
    always #1 we =! we;
    always #2 clr = 0;
    initial begin
        $dumpfile("DFF.vcd");
        $dumpvars;
    end
endmodule