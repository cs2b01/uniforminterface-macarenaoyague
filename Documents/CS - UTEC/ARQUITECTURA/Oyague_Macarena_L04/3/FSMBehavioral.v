module FSMBehavioral (input nreset, clk, x1,
                      output reg [1:0]y, 
                      output z);

reg [1:0] next_state;

parameter a = 2'b00, b = 2'b01, c = 2'b11, d = 2'b10;

assign z = y[1] & ~y[0];

always @ (posedge clk)
begin
    if (~nreset)
        y = a;
    else
        y = next_state;
end

always @ (y or x1)
begin
    case (y)
    a:
        if (x1 == 1) next_state = b;
        else next_state = a;

    b: 
        if (x1 == 0) next_state = c;
    c:
        if (x1 == 1) next_state = b;
        else next_state = d;
    d:
        if (x1 == 1) next_state = b;
        else next_state = a;
    endcase
end
endmodule