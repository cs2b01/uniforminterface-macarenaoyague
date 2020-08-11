`include "mux_8_1.v"
module mux16_1 (   input [15:0]input1,
                   input [15:0]input2,
                   input [15:0]input3,
                   input [15:0]input4,
                   input [15:0]input5,
                   input [15:0]input6,
                   input [15:0]input7,
                   input [15:0]input8,
                   input [15:0]input9,
                   input [15:0]input10,
                   input [15:0]input11,
                   input [15:0]input12,
                   input [15:0]input13,
                   input [15:0]input14,
                   input [15:0]input15,
                   input [15:0]input16,
                   input [3:0]selector,
                   output [15:0]output1);
    wire [15:0]submodule1, submodule2;
    mux8_1 mux1(input1, input2, input3, input4, input5, input6, input7, input8, selector[2:0], submodule1);
    mux8_1 mux2(input9, input10, input11, input12, input13, input14, input15, input16, selector[2:0], submodule2);
    assign output1 = selector[3] ? submodule2 : submodule1;
endmodule
