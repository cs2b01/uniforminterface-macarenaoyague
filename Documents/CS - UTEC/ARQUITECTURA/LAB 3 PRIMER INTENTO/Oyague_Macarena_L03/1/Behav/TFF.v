`include "DLatch.v"
module TFF(   input prn,
              input t,
              input clk,
              input clrn,
              output q,
              output qn);
    wire o1, o2;
    TLatch tl(prn, t, ~clk, clrn, q, qn, o1, o2);
    DLatch dl(o1, clrn, clk, o2, prn, q, qn);
endmodule

module TLatch(     input prn,
                   input t,
                   input clkn,
                   input clrn,
                   input q,
                   input qn,
                   output o1,
                   output o2);
    assign o1 = (qn & t & clkn & clrn) & prn & o2;
    assign o2 = o1 & clrn & (prn & clkn & t & q);
endmodule