`include "RSLatch.v"
`include "DFF.v"
`include "Register.v"
module FIFO4(   input [3:0]din,
                input read,
                input write,
                input clr,
                output [3:0]dout,
                output empty,
                output full);
    wire clk1, clk2, clk3, clk4;
    wire q4, qn4, q3, qn3, q2, qn2, q1, qn1, q0;
    assign clk4 = ~read & qn4 & q3;
    assign clk3 = qn3 & q2;
    assign clk2 = qn2 & q1;
    assign clk1 = qn1 & q0;
    DFF F0(~clr, write, clr | clk1, q0); 
    RSLatch RS1(clk1, clk2, clr, q1, qn1);
    RSLatch RS2(clk2, clk3, clr, q2, qn2);
    RSLatch RS3(clk3, clk4, clr, q3, qn3);
    RSLatch RS4(clk4, read, clr, q4, qn4);
    wire [3:0]d12, d23, d34;
    Register R1(din, clk1, d12);
    Register R2(d12, clk2, d23);
    Register R3(d23, clk3, d34);
    Register R4(d34, clk4, dout);
endmodule
