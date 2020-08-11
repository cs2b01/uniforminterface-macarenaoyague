`include "mux_2_1.v"
`include "DFF_behavioral.v"
module SchematicMisterioso(   input [2:0]d,
                              input di,
                              input load,
                              input clk,
                              input clrn,
                              output [2:0]q,
                              output do);
    wire out_mux1, out_mux2, out_mux3;
    mux2_1 mux1(di, d[2], load, out_mux1);
    DFF_behavioral dff1(out_mux1, clk, clrn, q[2]);
    mux2_1 mux2(q[2], d[1], load, out_mux2);
    DFF_behavioral dff2(out_mux2, clk, clrn, q[1]);
    mux2_1 mux3(q[1], d[0], load, out_mux3);
    DFF_behavioral dff3(out_mux3, clk, clrn, q[0]);
    assign do = q[0];
endmodule