module decoder3_8 (  input [2:0]input1,
                      input enable,
                      output [7:0]output1);
    assign output1[0] = enable == 1 ? (input1 == 3'b000 ? 1 : 0) : 0;
    assign output1[1] = enable == 1 ? (input1 == 3'b001 ? 1 : 0) : 0;
    assign output1[2] = enable == 1 ? (input1 == 3'b010 ? 1 : 0) : 0;
    assign output1[3] = enable == 1 ? (input1 == 3'b011 ? 1 : 0) : 0;
    assign output1[4] = enable == 1 ? (input1 == 3'b100 ? 1 : 0) : 0;
    assign output1[5] = enable == 1 ? (input1 == 3'b101 ? 1 : 0) : 0;
    assign output1[6] = enable == 1 ? (input1 == 3'b110 ? 1 : 0) : 0;
    assign output1[7] = enable == 1 ? (input1 == 3'b111 ? 1 : 0) : 0;
endmodule