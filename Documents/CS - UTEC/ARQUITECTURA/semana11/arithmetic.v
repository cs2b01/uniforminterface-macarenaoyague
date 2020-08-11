module arithmetic (A, B, opcode, out);
    input[31:0] A, B;
    input [3:0] opcode;
    output [31:0] out;
    reg [31:0] out;

    parameter add = 4'b0000, sub = 4'b0010, slt = 4'b1010;

    always @ (A or B or opcode) begin
        casex (opcode)
            add: out = A + B;
            sub: out = A - B;
            slt: out = (A < B) ? 1 : 0;
            default: out = 31'b0;
        endcase
    end

endmodule