module mux2_1(  input input1,
                input input2,
                input selector,
                output output1);
  assign output1 = selector ? input2 : input1;
endmodule