module demux1_2(  input [15:0]input1,
                   input selector,
                   output [15:0]output1,
                   output [15:0]output2);
    assign output1 = selector ? 0 : input1;
    assign output2 = selector ? input1 : 0;
endmodule