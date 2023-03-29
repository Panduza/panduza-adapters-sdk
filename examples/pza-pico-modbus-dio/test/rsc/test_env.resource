*** Settings ***
Library    Collections
Library    Dialogs
Library    libs/GPIOLibrary.py
Library    libs/ModbusLibrary.py
Variables    envs/bench.py    

*** Variables ***
# ReadCoil
${readableCoilAdress}    0
${attendedValueFromCoil}    0
${WritableCoilAdress}    25
${NotWritableCoilAdress}    30
#ReadDiscretInput
${readableDiscretInput}    0
${attendedValueFromDiscretInput}    0
${notReadableDiscretInput}    32
#ReadInputRegister
${readableInputRegister}    0
${attendedValueFromInputRegister}   23120 

*** Keywords ***