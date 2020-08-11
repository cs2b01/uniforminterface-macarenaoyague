`timescale 1ns/1ns
module demux_1_2_tb;
    reg [15:0]input1;
    reg selector;
    wire [15:0]output1, output2;
    demux1_2 mux(input1, selector, output1, output2);
    initial begin
        selector = 0;
        input1=$random;
        $monitor("%d ns: \t selector=%b \t input1=%h \t output1=%h \t output2=%h", $time, selector, input1, output1, output2);
        #3 $finish;
    end
    always #1 selector=!selector;
    initial begin
        $dumpfile("demux1_2.vcd");
        $dumpvars;
    end
endmodule