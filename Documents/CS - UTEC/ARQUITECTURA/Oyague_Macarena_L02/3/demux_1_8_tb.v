`timescale 1ns/1ns
module demux1_8_tb;
    reg [15:0]input1;
    reg [2:0]selector;
    wire [15:0]output1, output2, output3, output4, output5, output6, output7, output8;
    demux1_8 mux(input1, selector, output1, output2, output3, output4, output5, output6, output7, output8);
    initial begin
        selector[0] = 0;
        selector[1] = 0;
        selector[2] = 0;
        input1=$random;
        $monitor("%d ns:\tsel[0]=%b sel[1]=%b sel[2]=%b in1=%h\tout1=%h  out2=%h  out3=%h  out4=%h  out5=%h  out6=%h  out7=%h  out8=%h", 
                $time, selector[0], selector[1], selector[2], input1, output1, output2, output3, output4,  output5, output6, output7, output8);
        #8 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    always #4 selector[2]=!selector[2];
    initial begin
        $dumpfile("demux1_8.vcd");
        $dumpvars;
    end
endmodule