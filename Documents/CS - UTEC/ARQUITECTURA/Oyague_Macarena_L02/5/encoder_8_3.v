module encoder8_3 (   input [7:0]input1,
                      input enable,
                      output reg [2:0]output1,
                      output reg g);
    always @(input1) begin
      casex(input1)
            8'b00000000 : output1 =  enable == 1 ? 3'b000 : 0;
            8'b00000001 : output1 =  enable == 1 ? 3'b000 : 0;
            8'b0000001X : output1 =  enable == 1 ? 3'b001 : 0;
            8'b000001XX : output1 =  enable == 1 ? 3'b010 : 0;
            8'b00001XXX : output1 =  enable == 1 ? 3'b011 : 0;
            8'b0001XXXX : output1 =  enable == 1 ? 3'b100 : 0;
            8'b001XXXXX : output1 =  enable == 1 ? 3'b101 : 0;
            8'b01XXXXXX : output1 =  enable == 1 ? 3'b110 : 0;
            8'b1XXXXXXX : output1 =  enable == 1 ? 3'b111 : 0;
      endcase
    end
    always @(input1) begin
      if (output1 == 3'b000 && input1 == 8'b00000000) begin
        g = 0;
      end else if (enable == 0) begin
        g = 0;
      end else begin
        g = 1;
      end
    end
endmodule