module DFF(   input d,
              input we,
              input clr,
              output reg q);
    always@(posedge we)
    begin
      if (clr == 1'b1) q <= 0;
      else q <= d;
    end
endmodule