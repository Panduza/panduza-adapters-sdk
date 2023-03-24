#include "hardware/uart.h"

void pza_platform_uart_init(uint32_t baudrate)
{
    uart_init(uart0, baudrate);
}

void pza_platform_uart_write(uint8_t *buff_write, uint32_t len)
{
    uart_write_blocking(uart0, buff_write, len);
}

void pza_platform_uart_read(uint8_t *buff_read, uint32_t len)
{
    uart_read_blocking(uart0, buff_read, len);
}

void pza_platform_uart_set_baudrate(uint32_t baudrate)
{
    uart_set_baudrate(uart0, baudrate);
}