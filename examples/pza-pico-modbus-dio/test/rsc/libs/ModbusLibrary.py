from pymodbus.client import ModbusSerialClient
from pymodbus.transaction import ModbusRtuFramer
from robot.api.deco import keyword

import logging

@keyword("Sum ${a} and ${b}")
def sum(a,b):
    return int(a)+int(b)

@keyword("Define master on ${USB_Port} with baudrate = ${baudrate}") 
def masterDefine(USB_Port, baudrate):
    master = ModbusSerialClient(framer=ModbusRtuFramer, 
                                port = USB_Port,
                                stopbits=1,
                                bytesize=8,
                                parity='N',
                                baudrate=int(baudrate))
    return master

@keyword("Connect master ${master}")
def masterConnect(master):
    connect = master.connect()
    return connect

@keyword("Read one holding regs from ${regAdress} at slave adress ${slaveAdress} with master ${master}")
def readHolding(regAdress, slaveAdress, master ):
    getReadHolding = master.read_holding_registers(int(regAdress), 1, int(slaveAdress))
    return getReadHolding.registers[0]

@keyword("Write ${value} into holding reg ${regAdress} for slave adress ${slaveAdress} with master ${master}")
def writeHolding(value, regAdress, slaveAdress, master):
    getWriteHolding = master.write_registers(int(regAdress), int(value), int(slaveAdress))
    return getWriteHolding

@keyword("Read a coil from ${coilAdress} at slave adress ${slaveAdress} with master ${master}")
def readCoil(coilAdress, slaveAdress, master):
    getReadCoil = master.read_coils(int(coilAdress), 1, int(slaveAdress))
    return getReadCoil.getBit(0)

@keyword("Write ${value} into coil ${coilAdress} at slave adress ${slaveAdress} with master ${master}")
def writeCoil(value, coilAdress, slaveAdress, master):
    getWriteCoil = master.write_coils(int(coilAdress), value, int(slaveAdress))
    return getWriteCoil

@keyword("Read one discrete input from ${regAdress} at slave adress ${slaveAdress} with master ${master}")
def readDiscretInput(regAdress, slaveAdress, master):
    getRead = master.read_discrete_inputs(int(regAdress), 1, int(slaveAdress))
    return getRead.bits[0]

@keyword("Read one input register from ${regAdress} at slave adress ${slaveAdress} with master ${master}")
def readInputRegister(regAdress, slaveAdress, master):
    getRead = master.read_input_registers(int(regAdress), 1, int(slaveAdress))
    return getRead.registers[0]