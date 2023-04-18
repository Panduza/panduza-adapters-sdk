#include <pico/stdlib.h>
#include "hardware/uart.h"

// #define DEBUG
#ifdef DEBUG
    #define UART_ID uart1
    #define BAUD_RATE 115200

    #define UART_TX_PIN 4
    #define UART_RX_PIN 5

    #define debugUART(...) uart_puts(UART_ID, __VA_ARGS__);
#endif

void pza_platform_init(void)
{
    // stdio_usb_init();

    stdio_init_all();

    #ifdef DEBUG
        uart_init(UART_ID, BAUD_RATE);
        gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
        gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
        while(1){
            debugUART("uart debug\r\n");
        }
    #endif

}
