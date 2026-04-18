module Sim();

reg clk;
reg resetn;
reg[31:0] period;
reg[31:0] pulseWidth;
wire out;

initial begin
	$dumpfile("SimPwm.vcd");
	$dumpvars(0, Sim);
	clk = 0;
	forever #1 clk = !clk;
end

initial begin
	resetn = 0;
	period = 0;
	pulseWidth = 0;
	#2 resetn = 1;
	#4 period = 10;
	#4 pulseWidth = 1;
	#80 period = 15;
	pulseWidth = 13;
	#86 period = 13;
	#60 period = 0;
	#20 $finish;
end

Pwm pwm(
	.clk(clk),
	.resetn(resetn),
	.period(period),
	.pulseWidth(pulseWidth),
	.out(out)
);

endmodule
