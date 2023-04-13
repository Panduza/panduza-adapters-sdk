#include "panduza/dio.h"
#include "panduza/interface.h"
#include <stdio.h>
#include <pico/stdlib.h>
#include "tusb.h"


#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_TX_PIN 4
#define UART_RX_PIN 5




int main()
{
    pza_platform_init();
    pza_interface_init();
    tusb_init();
    
    // init the panduza dio modbus device and regs + bind
    pza_dio_t dio = {0};
    const uint32_t gpioMask = ~((1 << 31) | (1 << 30) | (1 << 29) | (1 << 24) | (1 << 23)); // disable io 31/30/29/24/23
    pza_dio_init(&dio, gpioMask);

    while (1){
      
        pza_interface_run();
        pza_dio_run(&dio);
    }

    return 0;
}

