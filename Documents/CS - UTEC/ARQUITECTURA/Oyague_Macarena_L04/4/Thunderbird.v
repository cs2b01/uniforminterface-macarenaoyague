module FSMBehavioral (input reset, clk, R, L,
                      output LC, LB, LA, RA, RB, RC, 
                      output reg[2:0]y);

reg [2:0] next_state;

parameter a = 3'b000, b = 3'b001, c = 3'b010, d = 3'b011, 
          e = 3'b100, f = 3'b101, g = 3'b111;

assign LC = (y==d);
assign LB = (y==c | y==d);
assign LA = (y==b | y==c | y==d);
assign RA = (y==e | y==f | y==g);
assign RB = (y==f | y==g);
assign RC = (y==g);

always @ (posedge clk)
begin
    if (reset)
        y = a;
    else
        y = next_state;
end

always @ (y or L or R)
begin
    case (y)
    a:
        if (L) next_state = b;
        else if (R) next_state = e;
    b: 
        next_state = c;
    c:
        next_state = d;
    d:
        next_state = a;
    e: 
        next_state = f;
    f:
        next_state = g;
    g:
        next_state = a;
    default:
        next_state = a;
    endcase
end
endmodule