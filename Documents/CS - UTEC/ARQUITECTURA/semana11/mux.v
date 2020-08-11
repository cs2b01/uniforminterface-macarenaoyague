module mux2_1 (logicU, arithU, sel, out);
    input [31:0] logicU, arithU;
    input sel;
    output [31:0] out;
    assign out = sel ? logicU : arithU;
endmodule