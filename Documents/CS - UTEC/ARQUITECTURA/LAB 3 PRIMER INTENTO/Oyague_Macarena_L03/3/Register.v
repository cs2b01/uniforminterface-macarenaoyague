module Register(   input [3:0]d,
                   input clk,
                   output [3:0]q);
    assign q = clk ? d : q;
endmodule