module FSMBehavioral_tb;

    reg nreset, clk, x1;
    wire [1:0]y;
    wire z;

    FSMBehavioral fsm(.nreset(nreset), .clk(clk), .x1(x1), .y(y), .z(z));

    initial begin
        clk = 1;
        nreset = 0;
        x1 = 0; 
        #1 nreset = 1; 
        @(posedge clk) x1 = 1;
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 1;
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 0;
        @(posedge clk) x1 = 1;
        @(posedge clk) x1 = 1; 
        @(posedge clk) x1 = 0; 
        @(posedge clk) x1 = 0;   
        #14 $finish;
    end

    initial begin
        $monitor("%d ns:\tclk=\tnreset= \t x=%b\t y=%b\t z=%b", $time, x1, y, z);
    end
    
    always #1 clk = !clk;

    initial begin
        $dumpfile("FSMBehavioral.vcd");
        $dumpvars;
    end
endmodule