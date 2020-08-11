module FSMBehavioral (input nreset, clk, x1, x2, x3,
                      output reg [2:0]y, z);

reg [2:0] next_state;

parameter a = 3'b000, b = 3'b001, c = 3'b101, d = 3'b010, e = 3'b100, f = 3'b110, g = 3'b111;

always @ (posedge clk)
begin
    if (~nreset)
        y = a;
    else
        y = next_state;
    case (y)
    d:
      z = 3'b100;
    e:
      z = 3'b010;
    g:
      z = 3'b001;
    default: 
      z = 3'b000;
    endcase
end

always @ (y or x1 or x2 or x3)
begin
    case (y)
    a:
        if (x1 == 1) next_state = b;
        else next_state = c;

    b: 
        if (x2 == 1) next_state = d;
        else next_state = a;
    c:
        if (x2 == 1 & x3 == 1) next_state = e;
        else if (x2 == 1 & x3 == 0) next_state = a;
        else if (x2 == 0 & x3 == 1) next_state = f;
        else if (x2 == 0 & x3 == 0) next_state = g;
    default: 
        next_state = a;
    endcase
end

endmodule