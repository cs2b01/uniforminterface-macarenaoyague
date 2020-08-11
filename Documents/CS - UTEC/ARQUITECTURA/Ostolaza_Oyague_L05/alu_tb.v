module alu_tb;

reg[31:0] A, B; 
reg[3:0] opcode;
wire[31:0] result; 

initial 
$monitor ("A = %b, B =%b, opcode = %b, Result = %b, Zero = %b", A, B, opcode, result, zero);

initial
begin
    A = 15;
    B = 10;

    #1 opcode = 4'b0000;
    #1 opcode = 4'b0010;
    #1 opcode = 4'b0100;
    #1 opcode = 4'b0101;
    #1 opcode = 4'b0110;
    #1 opcode = 4'b0111;
    #1 opcode = 4'b1010;
    #1 opcode = 4'bx;

	#8 $finish;

end

alu inst1 (A, B, opcode, result, zero);

initial begin
        $dumpfile("alu.vcd");
        $dumpvars;
end

endmodule