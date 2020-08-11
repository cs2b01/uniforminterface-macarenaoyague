`timescale 1ns/1ns
module SchematicMisterioso_tb;
    reg [2:0]d;
    reg di, load, clk, clrn;
    wire [2:0]q;
    wire do;
    SchematicMisterioso SM(d, di, load, clk, clrn, q, do);
    initial begin
        clk = 1;
        di = 0;
        d = 3'b000;
        clrn = 1;
        load = 1;
        $monitor("%d ns:\td=%b  di=%b  load=%b  clk=%b  clrn=%b  q=%b  do=%b", 
                 $time, d, di, load, clk, clrn, q, do);
        #20 $finish;
    end
    always #1 di =! di;
    always #1 d = $random;
    always #3 clk =! clk;
    always #4 load =! load;
    always #12 clrn =! clrn;
    initial begin
        $dumpfile("SM.vcd");
        $dumpvars;
    end
endmodule