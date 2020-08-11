`timescale 1ns/1ns
module Register_tb;
    reg clk;
    reg [3:0]d;
    wire [3:0]q;
    Register rgstr(d, clk, q);
    initial begin
        clk = 1;
        d = $random;
        $monitor("%d ns:\td=%b\tclk=%h\tq=%b", 
                 $time, d, clk, q);
        #20 $finish;
    end
    always #1 d = $random;
    always #2 clk =! clk;
    initial begin
        $dumpfile("DFF.vcd");
        $dumpvars;
    end
endmodule