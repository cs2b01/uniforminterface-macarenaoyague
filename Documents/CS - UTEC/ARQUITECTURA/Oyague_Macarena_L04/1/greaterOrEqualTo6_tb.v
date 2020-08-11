`timescale 1ns/1ns
module greaterOrEqualTo6_tb;
    reg [2:0]y;
    wire z1;
    greaterOrEqualTo6 mod(.y(y), .z1(z1));
    initial begin
        y = 3'b000;
        $monitor("%d ns:\ty=%b\t z1=%b", $time, y, z1);
        #10 $finish;
    end
    always #1 y = y + 1'h1; 
    initial begin
        $dumpfile("greaterOrEqualTo6.vcd");
        $dumpvars;
    end
endmodule