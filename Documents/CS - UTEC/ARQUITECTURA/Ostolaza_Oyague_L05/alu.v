module mux2_1 (logicU, arithU, sel, out);
    input [31:0] logicU, arithU;
    input sel;
    output [31:0] out;
    assign out = sel ? logicU : arithU;
endmodule

module alu (A, B, opcode, result, zero);
    input[31:0] A, B;
    input [3:0] opcode;
    output [31:0] result;
    output zero;
    wire [31:0] outLogic, outArithmetic;

    logicUnit log(A, B, opcode, outLogic);
    arithmetic ari(A, B, opcode, outArithmetic);
    mux2_1 mux(outLogic, outArithmetic, opcode[2], result);
    assign zero = (result == 31'b0) ? 1 : 0;
endmodule