`timescale 1ns/1ns
module mux2_1_tb;
    reg input1, input2;
    reg selector;
    wire output1;
    mux2_1 mux(input1, input2, selector, output1);
    initial begin
        selector = 0;
        input1=$random; 
        input2=$random;
        $monitor("%d ns:\tselector=%b\t input1=%h  input2=%h \t output1=%h", $time, selector, input1, input2, output1);
        #3 $finish;
    end
    always #1 selector=!selector;
    initial begin
        $dumpfile("mux2_1.vcd");
        $dumpvars;
    end
endmodule