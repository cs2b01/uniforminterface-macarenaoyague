`timescale 1ns/1ns
module FIFO4_tb;
    reg [3:0]din;
    reg read, write, clr;
    wire [3:0]dout;
    wire empty, full;
    FIFO4 fifo(din, read, write, clr, dout, empty, full);
    initial begin
        read = 0;
        write = 0;
        clr = 1;
        din = $random;
        $monitor("%d ns:\tdin=%b\tempty=%b\tfull=%b\tdout=%b", 
                 $time, din, empty, full, dout);
        #20 $finish;
    end
    always #5 clr = 0;
    always #10 write = !write;
    initial begin
        $dumpfile("FIFO4.vcd");
        $dumpvars;
    end
endmodule