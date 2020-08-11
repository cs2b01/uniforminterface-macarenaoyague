`timescale 1ns/1ns

module mux16_1_tb;
    reg [15:0]input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11, input12, input13, input14, input15, input16;
    reg [3:0]selector;
    wire [15:0]output1;
    mux16_1 mux (input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11, input12, input13, input14, input15, input16, selector, output1);
    initial begin
      selector[0] = 0;
      selector[1] = 0;
      selector[2] = 0;
      selector[3] = 0;
      input1=$random;
      input2=$random;
      input3=$random;
      input4=$random;
      input5=$random;
      input6=$random;
      input7=$random;
      input8=$random;
      input9=$random;
      input10=$random;
      input11=$random;
      input12=$random;
      input13=$random;
      input14=$random;
      input15=$random;
      input16=$random;
      $monitor("%d ns:\tsel[0]=%b sel[1]=%b sel[2]=%b sel[3]=%b\tin1=%h  in2=%h  in3=%h  in4=%h  in5=%h  in6=%h  in7=%h  in8=%h  in9=%h  in10=%h  in11=%h  in12=%h  in13=%h  in14=%h  in15=%h  in16=%h\tout1=%h", 
                $time, selector[0], selector[1], selector[2], selector[3], input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11, input12, input13, input14, input15, input16, output1);
      #16 $finish;
    end
    always #1 selector[0]=!selector[0];
    always #2 selector[1]=!selector[1];
    always #4 selector[2]=!selector[2];
    always #8 selector[3]=!selector[3];
    initial begin
        $dumpfile("mux16_1.vcd");
        $dumpvars;
    end
endmodule