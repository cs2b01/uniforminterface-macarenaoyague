`timescale 1ns/1ns
module RSLatch_tb;
    reg s, r, clr;
    wire q, qn;
    RSLatch latch(s, r, clr, q, qn);
    initial begin
        s = 0;
        r = 1;
        clr = 0;
        $display("time\ten\tn\td\t");
        $monitor("%d ns:\ts=%h\tr=%h\tclr=%h\tq=%h\tqn=%h", $time, s, r, clr, q, qn);
        #10 $finish;
    end
    always #1 s = !s; //funciona con 0 0, no debería funcionar
    always #1 r = !r;
    always #4 clr = !clr;
initial begin
        $dumpfile("RSLatch.vcd");
        $dumpvars;
    end
endmodule