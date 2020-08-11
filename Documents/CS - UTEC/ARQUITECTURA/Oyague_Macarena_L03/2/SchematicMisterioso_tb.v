`timescale 1ns/1ns
module SchematicMisterioso_tb;
    reg [2:0]d;
    reg di, load, clk, clrn;
    wire [2:0]q;
    wire do;
    SchematicMisterioso SM(d, di, load, clk, clrn, q, do);
    initial begin
        clk = 0;
        di = 1;
        d = 3'b101;
        clrn = 0;
        load = 0;
        $monitor("%d ns:  d=%b  di=%b  load=%b  clk=%b  clrn=%b  q=%b  do=%b", 
                 $time, d, di, load, clk, clrn, q, do);
        #9 $finish;
    end
    always #1 clk =! clk;
    always #8 load =! load;
    always #2 clrn = 1;
    initial begin
        $dumpfile("SM.vcd");
        $dumpvars;
    end
endmodule
