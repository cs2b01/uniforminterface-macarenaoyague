`timescale 1ns/1ns
module Register_tb;
    reg clk;
    reg [3:0]d;
    wire [3:0]q;
    Register rgstr(d, clk, q);
    initial begin
        clk = 0;
        d = $random;
        $monitor("%d ns:\td=%b\tclk=%h\tq=%b", 
                 $time, d, clk, q);
        #4 $finish;
    end
    always #1 clk =! clk;
     always #2 d = $random;
    initial begin
        $dumpfile("DFF.vcd");
        $dumpvars;
    end
endmodule