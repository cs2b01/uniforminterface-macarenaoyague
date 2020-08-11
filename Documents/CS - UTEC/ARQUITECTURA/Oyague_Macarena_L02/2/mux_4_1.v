`include "mux_2_1.v"
module mux4_1(  input[15:0] input1,
                input[15:0] input2,
                input[15:0] input3,
                input[15:0] input4,
                input[1:0] selector,
                output[15:0] output1);
    wire [15:0] submodule1, submodule2;
    mux2_1 mux1(input1, input2, selector[0], submodule1);
    mux2_1 mux2(input3, input4, selector[0], submodule2);
    assign output1 = selector[1] ? submodule2 : submodule1;
endmodule