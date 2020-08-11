module greaterOrEqualTo6(input [2:0]y,
                         output reg z1);
    always @ (y[2] or y[1] or y[0])
    begin
      if (y[2] & y[1])
        z1 = 1'b1;
      else
         z1 = 1'b0;
    end
endmodule