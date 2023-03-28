#ifndef PANDUZA_PLATFORM_UART_H
#define PANDUZA_PLATFORM_UART_H
#pragma once

#include <stdint.h>

void pza_platform_uart_init(uint32_t baudrate);
void pza_platform_uart_write(uint8_t *buff_write, uint32_t len);
void pza_platform_uart_read(uint8_t *buff_read, uint32_t *len);
void pza_platform_uart_set_baudrate(uint32_t baudrate);

#endif