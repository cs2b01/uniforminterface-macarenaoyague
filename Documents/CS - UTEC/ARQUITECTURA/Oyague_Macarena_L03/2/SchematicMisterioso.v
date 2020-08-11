`include "mux_2_1.v"
`include "DFF.v"
module SchematicMisterioso(   input [2:0]d,
                              input di,
                              input load,
                              input clk,
                              input clrn,
                              output [2:0]q,
                              output do);
    wire mout1, mout2, mout3;
    mux2_1 m1(.d_0(di), .d_1(d[2]), .selector(load), .out(mout1));
    DFF d1(.d(mout1), .clk(clk), .clrn(clrn), .q(q[2]));
    mux2_1 m2(.d_0(q[2]), .d_1(d[1]), .selector(load), .out(mout2));
    DFF d2(.d(mout2), .clk(clk), .clrn(clrn), .q(q[1]));
    mux2_1 m3(.d_0(q[1]), .d_1(d[0]), .selector(load), .out(mout3));
    DFF d3(.d(mout3), .clk(clk), .clrn(clrn), .q(q[0]));
    assign do = q[0];
endmodule