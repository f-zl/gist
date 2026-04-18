set sigs [list]
lappend sigs "Sim.clk"
lappend sigs "Sim.resetn"
lappend sigs "Sim.period"
lappend sigs "Sim.pulseWidth"
lappend sigs "Sim.out"
lappend sigs "Sim.pwm.count"
lappend sigs "Sim.pwm.isParamValid"

set num_added [ gtkwave::addSignalsFromList $sigs ]
gtkwave::setZoomRangeTimes 0 50
