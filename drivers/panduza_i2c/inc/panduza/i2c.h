#ifndef PANDUZA_I2C_H
#define PANDUZA_I2C_H
#pragma once

#include "stdint.h"

typedef union {
    struct control_content {
        uint32_t baudrate;
        uint8_t writeSize;
        uint8_t write[64];
    } content;
    uint8_t reg[sizeof(struct control_content)];
} pza_i2c_control_t;

typedef union {
    struct identifier_content {
        uint8_t magic[6];
        uint8_t read[64];
    } content;
    uint8_t reg[sizeof(struct identifier_content)];
} pza_i2c_identifier_t;

typedef struct {
    uint8_t id;
    pza_i2c_control_t control;
    pza_i2c_identifier_t identifier;
} pza_i2c_t;

void pza_i2c_init(pza_i2c_t *regs);
void pza_i2c_run(pza_i2c_t *regs);

#endif