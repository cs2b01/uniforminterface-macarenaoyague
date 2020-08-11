module DLatch(     input o1,
                   input clrn,
                   input clk,
                   input o2,
                   input prn,
                   output q,
                   output qn);
    assign q = (o1 & clrn & clk) & prn & qn;
    assign qn = (o2 & prn & clk) & q & clrn;
endmodule