module logicUnit (A, B, opcode, out);
    input[31:0] A, B;
    input [3:0] opcode;
    output [31:0] out;
    reg [31:0] out;

    parameter and_ = 4'b0100, or_ = 4'b0101, xor_ = 4'b0110, nor_ = 4'b0111;

    always @ (A or B or opcode) begin
        casex (opcode)
            and_: out = A & B;
            or_: out = A | B;
            xor_: out = A ^ B;
            nor_: out = ~(A | B);
            default: out = 31'b0;
        endcase
    end

endmodule