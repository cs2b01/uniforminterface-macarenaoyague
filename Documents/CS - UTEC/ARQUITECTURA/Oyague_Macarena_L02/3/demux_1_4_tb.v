`timescale 1ns/1ns
module demux1_4_tb;
    reg [15:0]input1;
    reg [1:0]selector;
    wire [15:0]output1, output2, output3, output4;
    demux1_4 mux(input1, selector, output1, output2, output3, output4);
    initial begin
        selector[0] = 0;
        selector[1] = 0;
        input1=$random;
        $monitor("%d ns:\tselector[0]=%b  selector[1]=%b  input1=%h\toutput1=%h  output2=%h  output3=%h  output4=%h", 
                $time, selector[0], selector[1], input1, output1, output2, output3, output4);
        #4 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    initial begin
        $dumpfile("demux1_4.vcd");
        $dumpvars;
    end
endmodule