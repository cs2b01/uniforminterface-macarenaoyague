`timescale 1ns/1ns
module mux4_1_tb;
    reg [15:0] input1, input2, input3, input4;
    reg [1:0] selector;
    wire [15:0] output1;
    mux4_1 mux(input1, input2, input3, input4, selector, output1);
    initial begin
        selector[0] = 0;
        selector[1] = 0;
        input1=$random;
        input2=$random;
        input3=$random;
        input4=$random;
        $monitor("%d ns:\tselector[0]=%d  selector[1]=%b\tinput1=%h  input2=%h  input3=%h  input4=%h\toutput1=%h", 
                $time, selector[0], selector[1], input1, input2, input3, input4, output1);
        #4 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    initial begin
        $dumpfile("mux4_1.vcd");
        $dumpvars;
    end
endmodule