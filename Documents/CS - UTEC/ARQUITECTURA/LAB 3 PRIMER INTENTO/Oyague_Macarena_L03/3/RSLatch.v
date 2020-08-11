module RSLatch(    input s,
                   input r, 
                   input clr,
                   output q, 
                   output qn);
    assign q = clr ? 0 : ( (~(r | qn) == 0 && ~(s | q) == 0) ? q : (~(r | qn)) ); 
    assign qn = clr ? 1 : ( (~(r | qn) == 0 && ~(s | q) == 0) ? qn : (~(s | q)) );
endmodule