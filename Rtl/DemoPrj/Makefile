.PHONY:all clean lint
all:SimPwm.vcd SimPwm.tcl
	gtkwave -T SimPwm.tcl $<
SimPwm.vcd:SimPwm.vvp # SimPwm.v should contain `$dumpfile("SimPwm.vcd");`
	vvp -N $<
SimPwm.vvp:Pwm.v SimPwm.v
	iverilog -Wall -o $@ $^
clean:
	rm *.vcd *.vvp
lint:
	verilator --lint-only -Wall Pwm.v
