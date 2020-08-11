module mux2_1(  input d_0,
                input d_1,
                input selector,
                output out);
  assign out = selector ? d_1 : d_0;
endmodule