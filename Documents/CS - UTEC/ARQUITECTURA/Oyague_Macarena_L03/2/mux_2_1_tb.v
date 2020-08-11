`timescale 1ns/1ns
module mux2_1_tb;
    reg d_0, d_1;
    reg selector;
    wire out;
    mux2_1 mux(d_0, d_1, selector, out);
    initial begin
        selector <= 0;
        d_0 <= 0; 
        d_1 <= 0;
        $monitor("%d ns:\tselector=%b\t d_0=%h  d_1=%h \t out=%h", $time, selector, d_0, d_1, out);
        #8 $finish;
    end
    always #4 selector=!selector;
    always #1 d_0=!d_0;
    always #2 d_1=!d_1;
    initial begin
        $dumpfile("mux2_1.vcd");
        $dumpvars;
    end
endmodule