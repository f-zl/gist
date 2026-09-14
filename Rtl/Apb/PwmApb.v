module PwmApb #(
	// business parameters (PWM_NUM) are placed before ApbParameter.inc
	// so that ApbParameter.inc can always end without a comma
	// a consequence is business parameters cannot use parameters in ApbParameter.inc
	parameter PWM_NUM = 8,
	`include "ApbParameter.inc"
)(
	// business ports (pwmOut) are placed before ApbPort.inc
	// so that ApbPort.inc can always end without a comma
	output [PWM_NUM-1:0] pwmOut,
	`include "ApbPort.inc"
);

// business-bus interface code, implement bus required interfaces
// like OnReset, OnWrite, OnRead

// param
localparam integer ParamNum = PWM_NUM*2;
reg[31:0] param[0:ParamNum-1];
wire[31:0] period[0:PWM_NUM-1];
wire[31:0] pulseWidth[0:PWM_NUM-1];

// signal
wire clk = APB_PCLK;
wire resetn = APB_PRESETn;

genvar i;
generate
for (i = 0; i < PWM_NUM; i = i + 1) begin
assign period[i] = param[i*2];
assign pulseWidth[i] = param[i*2+1];
Pwm pwm(
	.clk(clk),
	.resetn(resetn),
	.period(period[i]),
	.pulseWidth(pulseWidth[i]),
	.out(pwmOut[i])
);
end
endgenerate

task OnReset;
	for (integer i = 0; i < ParamNum; i = i + 1) begin
		param[i] <= 0;
	end
endtask

task OnWrite;
	input[31:0] addr;
	input[31:0] data;
	input[3:0] strb; // strb[0] means whether data[7:0] is written

	if (addr < ParamNum) begin
		for (integer i = 0; i < 4; i = i + 1) begin
			if (strb[i]) begin
				param[addr][(i*8) +: 8] <= data[(i*8) +: 8];
			end
		end
	end
endtask

function automatic [31:0] OnRead;
	input[31:0] addr;
	if (addr < ParamNum) begin
		OnRead = param[addr];
	end else begin
		case (addr - ParamNum)
			0: OnRead = {{(32-PWM_NUM){1'b0}}, pwmOut};
			default: OnRead = 0;
		endcase
	end
endfunction

`include "ApbLogic.inc"

endmodule
