module FSMBehavioral_tb;

    reg nreset, clk, x1, x2, x3;
    wire [2:0]y, z;

    FSMBehavioral fsm(.nreset(nreset), .clk(clk), .x1(x1), .x2(x2), 
                      .x3(x3), .y(y), .z(z));

    initial begin
        clk = 1;
        nreset = 0;
        {x1, x2, x3} = 3'b100; 
        #1 nreset = 1; 
        @(posedge clk) {x1, x2, x3} = 3'b010;
        @(posedge clk) {x1, x2, x3} = 3'b000; 
        @(posedge clk) {x1, x2, x3} = 3'b000; 
        @(posedge clk) {x1, x2, x3} = 3'b011;
        @(posedge clk) {x1, x2, x3} = 3'b011; 
        @(posedge clk) {x1, x2, x3} = 3'b001; 
        @(posedge clk) {x1, x2, x3} = 3'b000; 
        @(posedge clk) {x1, x2, x3} = 3'b000; 
        @(posedge clk) {x1, x2, x3} = 3'b000; 
        #14 $finish;
    end

    initial begin
        $monitor("%d ns:\tclk=%b\tnreset=%b\tx=%b%b%b\t y=%b\t z=%b", $time, clk, nreset, x1, x2, x3, y, z);
    end
    
    always #1 clk = !clk;

    initial begin
        $dumpfile("FSMBehavioral.vcd");
        $dumpvars;
    end
endmodule