module Pwm #(
	parameter WIDTH = 32
)(
	input clk,
	input resetn,
	input [WIDTH-1:0] period,	// in the unit of clk tick
	input [WIDTH-1:0] pulseWidth,
	output out
);
reg[WIDTH-1:0] count;
wire isParamValid = (period > 0) && (pulseWidth <= period);
// NOTE initial out is high if param is valid and pulseWidth < period
// if pulseWidth > period, out = 0
// if pulseWidth == 0, out = 0
// if period == 0, out = 0
assign out = (count < pulseWidth) && isParamValid;

always @(posedge clk) begin
	if (!resetn) begin
		count <= 0;
	end else if ((!isParamValid) || (pulseWidth == 0)) begin 
		count <= 0; // save power
	end else if (count < period - 1) begin
		// since isParamValid = 1 here, period will be > 0, period - 1 will not underflow
		count <= count + 1;
	end else begin // count == period
		count <= 0;
	end
end
endmodule
