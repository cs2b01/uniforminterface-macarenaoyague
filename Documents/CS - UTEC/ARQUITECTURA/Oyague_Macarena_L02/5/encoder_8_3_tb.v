`timescale 1ns/1ns
module encoder8_3_tb;
    reg [7:0]input1;
    reg enable;
    wire [2:0]output1;
    wire g;
    encoder8_3 encoder(input1, enable, output1, g);
    initial begin
        input1[0] = 0;
        input1[1] = 0;
        input1[2] = 0;
        input1[3] = 0;
        input1[4] = 0;
        input1[5] = 0;
        input1[6] = 0;
        input1[7] = 0;
        enable = 1;
        $monitor("%d ns:   enable=%b    in[0]=%b in[1]=%b in[2]=%b in[3]=%h in[4]=%h in[5]=%h in[6]=%h in[7]=%h     out[0]=%h out[1]=%h out[2]=%h   g=%b", 
                $time, enable, input1[0], input1[1], input1[2], input1[3], input1[4], input1[5], input1[6], input1[7], output1[0], output1[1], output1[2], g);
        #10 $finish;
    end
    always #1 input1[0]=!input1[0];
    always #2 input1[1]=!input1[1];
    always #3 input1[2]=!input1[2];
    always #4 input1[3]=!input1[3];
    always #5 input1[4]=!input1[4];
    always #6 input1[5]=!input1[5];
    always #7 input1[6]=!input1[6];
    always #8 input1[7]=!input1[7];
    always #9 enable=!enable;
    initial begin
        $dumpfile("encoder_8_3.vcd");
        $dumpvars;
    end
endmodule