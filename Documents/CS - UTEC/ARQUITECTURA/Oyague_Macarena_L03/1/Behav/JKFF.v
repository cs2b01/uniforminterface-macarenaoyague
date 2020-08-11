`include "DLatch.v"
module JKFF(  input prn,
              input j,
              input k,
              input clk,
              input clrn,
              output q,
              output qn);
    wire o1, o2;
    JKLatch jkl(prn, j, k, ~clk, clrn, q, qn, o1, o2);
    DLatch dl(o1, clrn, clk, o2, prn, q, qn);
endmodule

module JKLatch(    input prn,
                   input j,
                   input k,
                   input clkn,
                   input clrn,
                   input q,
                   input qn,
                   output o1,
                   output o2);
    assign o1 = (qn & j & clkn & clrn) & prn & o2;
    assign o2 = o1 & clrn & (prn & clkn & k & q);
endmodule
