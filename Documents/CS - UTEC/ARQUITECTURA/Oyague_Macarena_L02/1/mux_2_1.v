module mux2_1(  input [15:0]input1,
                input [15:0]input2,
                input selector,
                output [15:0]output1);
  assign output1 = selector ? input2 : input1;
endmodule