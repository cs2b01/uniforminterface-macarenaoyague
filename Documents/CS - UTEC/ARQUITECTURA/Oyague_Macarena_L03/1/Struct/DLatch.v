module DLatch(     input o1,
                   input clrn,
                   input clk,
                   input o2,
                   input prn,
                   output q,
                   output qn);
    wire o_nand1, o_nand2;
    nand_3 nand1(o1, clrn, clk, o_nand1);
    nand_3 nand2(o2, prn, clk, o_nand2);
    nand_3 nand3(o_nand1, prn, qn, q);
    nand_3 nand4(q, clrn, o_nand2, qn);
endmodule