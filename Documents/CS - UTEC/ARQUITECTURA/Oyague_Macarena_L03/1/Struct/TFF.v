`include "nand.v"
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
    wire o_nand1, o_nand2;
    nand_4 nand1(qn, t, clkn, clrn, o_nand1);
    nand_4 nand2(prn, clkn, t, q, o_nand2);
    nand_3 nand3(o_nand1, prn, o2, o1);
    nand_3 nand4(o1, clrn, o_nand2, o2);
endmodule
