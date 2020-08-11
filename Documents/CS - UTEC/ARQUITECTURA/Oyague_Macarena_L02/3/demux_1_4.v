`include "demux_1_2.v"
module demux1_4 (  input [15:0]input1,
                   input [1:0]selector,
                   output [15:0]output1,
                   output [15:0]output2,
                   output [15:0]output3,
                   output [15:0]output4);
    wire [15:0]submodule1_a, submodule1_b, submodule2_a, submodule2_b;
    demux1_2 mux1(input1, selector[0], submodule1_a, submodule1_b);
    demux1_2 mux2(input1, selector[0], submodule2_a, submodule2_b);
    assign output1 = selector[1] ? 0 : submodule1_a;
    assign output2 = selector[1] ? 0 : submodule1_b;
    assign output3 = selector[1] ? submodule2_a : 0;
    assign output4 = selector[1] ? submodule2_b : 0;
endmodule