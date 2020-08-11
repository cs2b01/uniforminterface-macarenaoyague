module alu_tb_2;
reg clk;  
reg [31:0]    a, b, y_expected;  
wire [31:0]   y;  
reg [3:0]     f;  
wire          zero;  
reg           zero_expected;  
reg [31:0]    vectornum, errors;  
reg [103:0]   testvectors[6:0];  

// instantiate device under test  
alu dut(a, b, f, y, zero);  

// generate clock  
always begin    
clk = 1; 
#50; 
clk = 0; 
#50;  
end  

// at start of test, load vectors  
initial begin    
$readmemh("alu.tv", testvectors);    
vectornum = 0; 
errors = 0;  
end  

// apply test vectors at rising edge of clock  
always @(posedge clk)    
begin      
#1;       
f = testvectors[vectornum][102:100];      
a = testvectors[vectornum][99:68];      
b = testvectors[vectornum][67:36];      
y_expected = testvectors[vectornum][35:4];      
zero_expected = testvectors[vectornum][0];    
end 

always @(negedge clk)    
begin
if (y_expected != y || zero != zero_expected)begin
$display("Error in vector %d", vectornum);
$display("Input: a = %h, b = %h, f = %b", a, b, f);
$display("Outputs: y = %h (%h expected), zero = %h (%h expected)", 
            y, y_expected, zero, zero_expected);
end
vectornum = vectornum + 1;
if (testvectors[vectornum][0] == 1'bx) begin
$display("%d tests completed with %d errors", vectornum, errors);
end
end

endmodule