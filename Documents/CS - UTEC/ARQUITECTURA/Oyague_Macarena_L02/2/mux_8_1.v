`include "mux_4_1.v"
module mux8_1 (   input [15:0]input1,
                  input [15:0]input2,
                  input [15:0]input3,
                  input [15:0]input4,
                  input [15:0]input5,
                  input [15:0]input6,
                  input [15:0]input7,
                  input [15:0]input8,
                  input [2:0]selector,
                  output [15:0]output1);
    wire [15:0]submodule1, submodule2;
    mux4_1 mux1(input1, input2, input3, input4, selector[1:0], submodule1);
    mux4_1 mux2(input5, input6, input7, input8, selector[1:0], submodule2);
    assign output1 = selector [2] ? submodule2 : submodule1;
endmodule