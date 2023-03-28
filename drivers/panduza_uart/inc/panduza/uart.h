#ifndef PANDUZA_UART_H
#define PANDUZA_UART_H
#pragma once

#include "stdint.h"

typedef union {
    struct control_content {
        uint32_t baudrate;
        uint8_t readSize;
        uint8_t writeSize;
        uint8_t write[64];
    } content;
    uint8_t reg[sizeof(struct control_content)];
} pza_uart_control_t;

typedef union {
    struct identifier_content {
        uint8_t magic[6];
        uint8_t read[64];
    } content;
    uint8_t reg[sizeof(struct identifier_content)];
} pza_uart_identifier_t;

typedef struct {
    uint8_t id;
    pza_uart_control_t control;
    pza_uart_identifier_t identifier;
} pza_uart_t;

void pza_uart_init(pza_uart_t *regs);
void pza_uart_run(pza_uart_t *regs);

#endif