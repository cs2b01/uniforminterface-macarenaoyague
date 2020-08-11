module nand_4(    input i1,
                  input i2,
                  input i3,
                  input i4,
                  output o);
    assign o = i1 & i2 & i3 & i4;
endmodule

module nand_3(    input i1,
                  input i2,
                  input i3,
                  output o);
    assign o = i1 & i2 & i3;
endmodule