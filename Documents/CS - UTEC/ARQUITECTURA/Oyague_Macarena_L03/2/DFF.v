module DFF(   input d,
              input clk,
              input clrn,
              output reg q);
    always@(posedge clk)
    begin
      if (clrn == 1'b0) q <= 0;
      else q <= d;
    end
endmodule