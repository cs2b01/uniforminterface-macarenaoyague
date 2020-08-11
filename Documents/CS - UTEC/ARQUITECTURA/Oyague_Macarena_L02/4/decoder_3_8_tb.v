`timescale 1ns/1ns
module decoder3_8_tb;
    reg [2:0]input1;
    reg enable;
    wire [7:0]output1;
    decoder3_8 decoder(input1, enable, output1);
    initial begin
        input1[0] = 0;
        input1[1] = 0;
        input1[2] = 0;
        enable = 1;
        $monitor("%d ns:\tin[0]=%b in[1]=%b in[2]=%b\tout[0]=%h  out[1]=%h  out[2]=%h  out[3]=%h  out[4]=%h  out[5]=%h  out[6]=%h  out[7]=%h", 
                $time, input1[0], input1[1], input1[2], output1[0], output1[1], output1[2], output1[3],  output1[4], output1[5], output1[6], output1[7]);
        #9 $finish;
    end
    always #1 input1[0]=!input1[0];
    always #2 input1[1]=!input1[1];
    always #4 input1[2]=!input1[2];
    always #8 enable=!enable;
    initial begin
        $dumpfile("decoder_3_8.vcd");
        $dumpvars;
    end
endmodule