`timescale 1ns/1ns
module demux1_16_tb;
    reg [15:0]input1;
    reg [3:0]selector;
    wire [15:0]output1, output2, output3, output4, output5, output6, output7, output8, output9, output10, output11, output12, output13, output14, output15, output16;
    demux1_16 mux(input1, selector, output1, output2, output3, output4, output5, output6, output7, output8, output9, output10, output11, output12, output13, output14, output15, output16);
    initial begin
        selector[0] = 0;
        selector[1] = 0;
        selector[2] = 0;
        selector[3] = 0;
        input1=$random;
        $monitor("%d ns:   sel[0]=%b sel[1]=%b sel[2]=%b in1=%h   out1=%h out2=%h out3=%h out4=%h out5=%h out6=%h out7=%h out8=%h out9=%h out10=%h out11=%h out12=%h out13=%h out14=%h out15=%h out16=%h", 
                $time, selector[0], selector[1], selector[2], input1, output1, output2, output3, output4, output5, output6, output7, output8, output9, output10, output11, output12, output13, output14, output15, output16);
        #16 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    always #4 selector[2]=!selector[2];
    always #8 selector[3]=!selector[3];
    initial begin
        $dumpfile("demux1_16.vcd");
        $dumpvars;
    end
endmodule