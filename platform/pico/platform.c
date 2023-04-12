#include <pico/stdlib.h>
// #include "hardware/uart.h"


// #define UART_ID uart1
// #define BAUD_RATE 115200

// #define UART_TX_PIN 4
// #define UART_RX_PIN 5


void pza_platform_init(void)
{
    // stdio_usb_init();

    stdio_init_all();
    // uart_init(UART_ID, BAUD_RATE);

    // gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    // gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // uart_puts(UART_ID, "uart debug \r\n");
}