module DFF(   input d,
              input clk,
              input clr,
              output q);
    assign q = clr ? 0 : (clk == 0 ? q : (d == 0 ? 0 : 1));
endmodule