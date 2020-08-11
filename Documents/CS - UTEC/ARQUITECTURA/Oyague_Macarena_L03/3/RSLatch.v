module RSLatch(    input s,
                   input r, 
                   input clr,
                   output reg q, 
                   output reg qn);
    always@(*)
        begin
            if (clr == 1'b1) begin q <= 0; qn <= 0; end
            else 
                begin
                if (s == 1'b1 & r == 1'b0) begin q <= 1; qn <= 0; end
                else if (s == 1'b0 & r == 1'b1) begin q <= 0; qn <= 1; end
                else if (s == 1'b1 & r == 1'b1) begin q <= 0; qn <= 0; end
                end
        end
endmodule