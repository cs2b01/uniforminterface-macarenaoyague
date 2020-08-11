`include "demux_1_4.v"
module demux1_8 (  input [15:0]input1,
                   input [2:0]selector,
                   output [15:0]output1,
                   output [15:0]output2,
                   output [15:0]output3,
                   output [15:0]output4,
                   output [15:0]output5,
                   output [15:0]output6,
                   output [15:0]output7,
                   output [15:0]output8);
    wire [15:0]submodule1_a, submodule1_b, submodule1_c, submodule1_d, submodule2_a, submodule2_b, submodule2_c, submodule2_d;
    demux1_4 mux1(input1, selector[1:0], submodule1_a, submodule1_b, submodule1_c, submodule1_d);
    demux1_4 mux2(input1, selector[1:0], submodule2_a, submodule2_b, submodule2_c, submodule2_d);
    assign output1 = selector[2] ? 0 : submodule1_a;
    assign output2 = selector[2] ? 0 : submodule1_b;
    assign output3 = selector[2] ? 0 : submodule1_c;
    assign output4 = selector[2] ? 0 : submodule1_d;
    assign output5 = selector[2] ? submodule2_a : 0;
    assign output6 = selector[2] ? submodule2_b : 0;
    assign output7 = selector[2] ? submodule2_c : 0;
    assign output8 = selector[2] ? submodule2_d : 0;
endmodule