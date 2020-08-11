`include "demux_1_8.v"
module demux1_16(  input [15:0]input1,
                   input [3:0]selector,
                   output [15:0]output1,
                   output [15:0]output2,
                   output [15:0]output3,
                   output [15:0]output4,
                   output [15:0]output5,
                   output [15:0]output6,
                   output [15:0]output7,
                   output [15:0]output8,
                   output [15:0]output9,
                   output [15:0]output10,
                   output [15:0]output11,
                   output [15:0]output12,
                   output [15:0]output13,
                   output [15:0]output14,
                   output [15:0]output15,
                   output [15:0]output16);
    wire [15:0]submodule1_a, submodule1_b, submodule1_c, submodule1_d, submodule1_e, submodule1_f, submodule1_g, submodule1_h;
    wire [15:0]submodule2_a, submodule2_b, submodule2_c, submodule2_d, submodule2_e, submodule2_f, submodule2_g, submodule2_h;
    demux1_8 mux1(input1, selector[2:0], submodule1_a, submodule1_b, submodule1_c, submodule1_d, submodule1_e, submodule1_f, submodule1_g, submodule1_h);
    demux1_8 mux2(input1, selector[2:0], submodule2_a, submodule2_b, submodule2_c, submodule2_d, submodule2_e, submodule2_f, submodule2_g, submodule2_h);
    assign output1 = selector[3] ? 0 : submodule1_a;
    assign output2 = selector[3] ? 0 : submodule1_b;
    assign output3 = selector[3] ? 0 : submodule1_c;
    assign output4 = selector[3] ? 0 : submodule1_d;
    assign output5 = selector[3] ? 0 : submodule1_e;
    assign output6 = selector[3] ? 0 : submodule1_f;
    assign output7 = selector[3] ? 0 : submodule1_g;
    assign output8 = selector[3] ? 0 : submodule1_h;
    assign output9 = selector[3] ? submodule2_a : 0;
    assign output10 = selector[3] ? submodule2_b : 0;
    assign output11 = selector[3] ? submodule2_c : 0;
    assign output12 = selector[3] ? submodule2_d : 0;
    assign output13 = selector[3] ? submodule2_e : 0;
    assign output14 = selector[3] ? submodule2_f : 0;
    assign output15 = selector[3] ? submodule2_g : 0;
    assign output16 = selector[3] ? submodule2_h : 0;
endmodule