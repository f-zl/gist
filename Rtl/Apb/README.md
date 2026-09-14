# Apb

This is a demo that separates bus and business in Verilog

Apb*.inc files are implementation of AMBA APB slave protocol

- ApbLogic.inc: the APB slave implementation
- ApbParameter.inc: parameters of APB bus
- ApbPort.inc: ports of APB bus

- Pwm.v: the business logic, has nothing to do with the bus
- PwmApb.v: the top module, implements bus required interfaces
