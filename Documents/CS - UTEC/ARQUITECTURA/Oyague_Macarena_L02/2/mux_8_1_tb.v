`timescale 1ns/1ns

module mux8_1_tb;
    reg [15:0]input1, input2, input3, input4, input5, input6, input7, input8;
    reg [2:0]selector;
    wire [15:0]output1;
    mux8_1 mux(input1, input2, input3, input4, input5, input6, input7, input8, selector, output1);
    initial begin
      selector[0] = 0;
      selector[1] = 0;
      selector[2] = 0;
      input1=$random;
      input2=$random;
      input3=$random;
      input4=$random;
      input5=$random;
      input6=$random;
      input7=$random;
      input8=$random;
      $monitor("%d ns:\tsel[0]=%d  sel[1]=%b  sel[2]=%b \tin1=%h  in2=%h  in3=%h  in4=%h  in5=%h  in6=%h  in7=%h  in8=%h\tout1=%h", 
                $time, selector[0], selector[1], selector[2], input1, input2, input3, input4, input5, input6, input7, input8, output1);
      #8 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    always #4 selector[2]=!selector[2];
    initial begin
        $dumpfile("mux8_1.vcd");
        $dumpvars;
    end
endmodule