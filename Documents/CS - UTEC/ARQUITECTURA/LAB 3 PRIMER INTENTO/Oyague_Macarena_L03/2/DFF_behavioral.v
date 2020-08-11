module DFF_behavioral(   input d,
                         input clk,
                         input clrn,
                         output q);
    assign q = (clrn == 0 ? 0 : (clk == 0 ? q : (d == 0 ? 0 : 1)));
endmodule