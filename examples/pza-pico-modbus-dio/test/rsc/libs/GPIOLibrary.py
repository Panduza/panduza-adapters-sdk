import ModbusLibrary as ModbusLibrary

from robot.api.deco import keyword

# --- DIRECTION REGISTER ---
@keyword("Get GPIO ${GPIONumber} direction, master = ${master}")
def getDirection(GPIONumber, master):
    read = ModbusLibrary.readCoil(int(GPIONumber), 1, master)
    return read

@keyword("Set GPIO ${GPIONumber} as Input, master = ${master}")
def setInput(GPIONumber, master):
    valueToWrite=[0]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber), 1, master)
    return write
    
@keyword("Set GPIO ${GPIONumber} as Output, master = ${master}")
def setOutput(GPIONumber, master):
    valueToWrite=[1]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber), 1, master)
    return write
    
# --- PULLS REGISTER ---
@keyword("Get GPIO ${GPIONumber} pulls, master = ${master}")
def getPulls(GPIONumber, master):
    read = ModbusLibrary.readCoil(int(GPIONumber)+32, 1, master)
    return read
    
@keyword("Set GPIO ${GPIONumber} as Pull_up, master = ${master}")
def setPullup(GPIONumber, master):
    valueToWrite=[1]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber)+32, 1, master)
    return write
    
@keyword("Set GPIO ${GPIONumber} as Pull_down, master = ${master}")
def setPulldown(GPIONumber, master):
    valueToWrite=[0]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber)+32, 1, master)
    return write
    
# --- OUTPUT VALUES REGISTER ---
@keyword("Set Output GPIO ${GPIONumber}, master = ${master}")
def activeGPIO(GPIONumber, master):
    valueToWrite=[1]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber)+64, 1, master)
    return write
    
@keyword("Reset Output GPIO ${GPIONumber}, master = ${master}")
def desactiveGPIO(GPIONumber, master):
    valueToWrite=[0]
    write = ModbusLibrary.writeCoil(valueToWrite, int(GPIONumber)+64, 1, master)
    return write
    
@keyword("Get GPIO ${GPIONumber} Output Value, master = ${master}")
def getOutputValue(GPIONumber, master):
    read = ModbusLibrary.readCoil(int(GPIONumber)+64, 1, master)
    return read
    
# --- INPUT VALUES ---
@keyword("Get GPIO ${GPIONumber} Input value, master = ${master}")
def getInputValue(GPIONumber, master):
    read = ModbusLibrary.readDiscretInput(int(GPIONumber), 1, master)
    return read

