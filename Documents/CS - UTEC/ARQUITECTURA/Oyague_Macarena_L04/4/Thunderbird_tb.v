module Thunderbird_tb;

    reg reset, clk, R, L;
    wire [2:0]y;
    wire LC, LB, LA, RA, RB, RC;

    FSMBehavioral fsm(.reset(reset), .clk(clk), .R(R), .L(L),
                      .LC(LC), .LB(LB), .LA(LA), 
                      .RA(RA), .RB(RB), .RC(RC), 
                      .y(y));
    initial begin
        clk = 0;
        reset = 1;         
        L = 0;
        R = 0;
        #1 reset = 0;
        #1 R = 1;
        #8 L = 1;     
        #16 $finish;
    end

    initial begin
        $monitor("%d ns:\tL=%b \tR=%b \t LEFT=%b%b%b\t RIGHT=%b%b%b\t y=%b", $time, L, R, LC, LB, LA, RA, RB, RC, y);
    end
    
    always #1 clk = !clk;

    initial begin
        $dumpfile("Thunderbird.vcd");
        $dumpvars;
    end
endmodule