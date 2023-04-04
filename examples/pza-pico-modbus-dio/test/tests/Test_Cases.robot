*** Settings ***
Resource    ../rsc/test_env.resource

*** Variables *** 
 
*** Test Cases ***
Connection
    [Documentation]    Connect to pico
    [Tags]    OK
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

ReadReadableCoil
    [Documentation]    Read readable coil
    [Tags]    OK

    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    ${write}    Set GPIO 0 as Input, master = ${master}

    ${read}    Read a coil from ${readableCoilAdress} at slave adress 1 with master ${master}
    Should Be Equal As Integers    ${read}    ${attendedValueFromCoil}

WriteCoilWritable
    [Documentation]    Write 1 in coil writable coil, expect success
    [Tags]    OK

    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    ${value}=    Create List    ${1}

    ${write}    Write ${value} into coil ${WritableCoilAdress} at slave adress 1 with master ${master}
    Should Be Equal As Strings    ${write}    WriteNCoilResponse(${WritableCoilAdress}, 1)

WriteNotWritableCoil
    [Documentation]    Write in non-writable coil, expect failure
    [Tags]    OK

    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    ${value}=    Create List    ${1}

    ${write}    Write ${value} into coil ${NotWritableCoilAdress} at slave adress 1 with master ${master}
    Should Be Equal As Strings    ${write}    Exception Response(143, 15, SlaveFailure)

ReadReadableDiscretInput
    [Documentation]    Read readable discret input 
    [Tags]    OK

    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    ${write}    Set GPIO 0 as Input, master = ${master}
    ${write}    Set GPIO 1 as Output, master = ${master}
    ${write}    Reset Output GPIO 1, master = ${master}
    ${read}    Read one discrete input from ${readableDiscretInput} at slave adress 1 with master ${master}
    Should Be Equal As Integers    ${read}    ${attendedValueFromDiscretInput}

ReadReadableInputRegister
    [Documentation]    Read readable input register
    [Tags]    OK
    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    ${read}    Read one input register from ${readableInputRegister} at slave adress 1 with master ${master}

    Should Be Equal As Integers    ${read}    ${attendedValueFromInputRegister}

ChangeOutputState
    [Documentation]     Change output state, check result in an input
    ...                 hygtgtygtg

    [Tags]    OK
    [Template]    Change Output state
    ${0}    ${1}
    ${2}    ${3}
    ${4}    ${5}
    ${6}    ${7}
    ${8}    ${9}
    ${10}    ${11}
    ${12}    ${13}
    ${14}    ${15}
    ${16}    ${17}
    ${18}    ${19}
    ${20}    ${21}
    ${22}    ${26}
    ${27}    ${28}
    ${1}    ${0}
    ${3}    ${2}
    ${5}    ${4}
    ${7}    ${6}
    ${9}    ${8}
    ${11}    ${10}
    ${13}    ${12}
    ${15}    ${14}
    ${17}    ${16}
    ${19}    ${18}
    ${21}    ${20}
    ${26}    ${22}
    ${28}    ${27}

ChangePullsGPIO
    [Documentation]     Define an input as pull-down, check the value for 1 and 0 from an output, same with pull-up 
    [Tags]    OK
    [Template]    Change Pull
    ${0}    ${1}
    ${2}    ${3}
    ${4}    ${5}
    ${6}    ${7}
    ${8}    ${9}
    ${10}    ${11}
    ${12}    ${13}
    ${14}    ${15}
    ${16}    ${17}
    ${18}    ${19}
    ${20}    ${21}
    ${22}    ${26}
    ${27}    ${28}
    ${1}    ${0}
    ${3}    ${2}
    ${5}    ${4}
    ${7}    ${6}
    ${9}    ${8}
    ${11}    ${10}
    ${13}    ${12}
    ${15}    ${14}
    ${17}    ${16}
    ${19}    ${18}
    ${21}    ${20}
    ${26}    ${22}
    ${28}    ${27}

*** Keywords ***
Change Output state
    [Arguments]    ${GPIO_IN}    ${GPIO_OUT}
    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    # Set GPIO_IN as Input
    ${writeDirIN}    Set GPIO ${GPIO_IN} as Input, master = ${master}
    Should Be Equal As Strings    ${writeDirIN}    WriteNCoilResponse(${GPIO_IN}, 1)

    # Set GPIO_OUT as Output
    ${writeDir}    Set GPIO ${GPIO_OUT} as Output, master = ${master}
    Should Be Equal As Strings    ${writeDir}    WriteNCoilResponse(${GPIO_OUT}, 1)

    # Activate GPIO out
    ${activate}    Set Output GPIO ${GPIO_OUT}, master = ${master}
    ${state}    Get GPIO ${GPIO_OUT} Output Value, master = ${master}
    Should Be Equal As Integers    ${state}    1
    ${read}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${read}    1

    # Desactivate GPIO out
    ${activate}    Reset Output GPIO ${GPIO_OUT}, master = ${master}
    ${state}    Get GPIO ${GPIO_OUT} Output Value, master = ${master}
    Should Be Equal As Integers    ${state}    0
    ${read}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${read}    0

Change Pull
    [Arguments]    ${GPIO_IN}    ${GPIO_OUT}
    # Master connection
    ${master}    Define master on ${USB_port} with baudrate = ${baudrate}
    ${connected}    Connect master ${master}
    Should Be True    ${connected}

    # Set the first GPIO as input
    ${writeDir}    Set GPIO ${GPIO_IN} as Input, master = ${master}
    Should Be Equal As Strings    ${writeDir}    WriteNCoilResponse(${GPIO_IN}, 1)

    # Read the first GPIO direction
    ${readDir}    Get GPIO ${GPIO_IN} direction, master = ${master}
    Should Be Equal As Integers    ${readDir}    0

    # Set the second GPIO as output
    ${writeDirSecondGPIO}    Set GPIO ${GPIO_OUT} as Output, master = ${master}
    Should Be Equal As Strings    ${writeDirSecondGPIO}    WriteNCoilResponse(${GPIO_OUT}, 1)

    # Read the second GPIO direction
    ${readDirSecondGPIO}    Get GPIO ${GPIO_OUT} direction, master = ${master}
    Should Be Equal As Integers    ${readDirSecondGPIO}    1
    
    # --- PULL DOWN ---
    # Set the first GPIO as pull-down
    ${writePulls}    Set GPIO ${GPIO_IN} as Pull_down, master = ${master}
    Should Be Equal As Strings    ${writePulls}    WriteNCoilResponse(${GPIO_IN+32}, 1)

    # Read the first GPIO pulls
    ${readPulls}    Get GPIO ${GPIO_IN} pulls, master = ${master}
    Should Be Equal As Integers    ${readPulls}    0

    # Desactivate second GPIO output
    ${activate}    Reset Output GPIO ${GPIO_OUT}, master = ${master}

    # Read value of the first GPIO
    ${readValue}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${readValue}    0

    # Activate second GPIO output
    ${activate}    Set Output GPIO ${GPIO_OUT}, master = ${master}

    # Read value of the first GPIO
    ${readValue}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${readValue}    1
    
    # --- PULL UP ---
    # Set the first GPIO pull-up
    ${writePulls}    Set GPIO ${GPIO_IN} as Pull_up, master = ${master}
    Should Be Equal As Strings    ${writePulls}    WriteNCoilResponse(${GPIO_IN+32}, 1)

    # Read the first GPIO pulls
    ${readPulls}    Get GPIO ${GPIO_IN} pulls, master = ${master}
    Should Be Equal As Integers    ${readPulls}    1

    # Read value of the first GPIO
    ${readValue}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${readValue}    1

    # Desactivate second GPIO output
    ${activate}    Reset Output GPIO ${GPIO_OUT}, master = ${master}

    # Read value of the first GPIO
    ${readValue}    Get GPIO ${GPIO_IN} Input value, master = ${master}
    Should Be Equal As Integers    ${readValue}    0