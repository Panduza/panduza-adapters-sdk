#ifndef PANDUZA_I2C_H
#define PANDUZA_I2C_H
#pragma once

#include "stdint.h"

typedef union {
    struct i2c_control_content {
        uint16_t address;
        uint16_t writeSize;
        uint16_t readSize;
        uint8_t write[64];
    } content;
    uint8_t reg[sizeof(struct i2c_control_content)];
} pza_i2c_control_t;

typedef union {
    struct i2c_identifier_content {
        uint8_t magic[6];
        uint8_t read[64];
    } content;
    uint8_t reg[sizeof(struct i2c_identifier_content)];
} pza_i2c_identifier_t;

typedef struct {
    uint8_t id;
    pza_i2c_control_t control;
    pza_i2c_identifier_t identifier;
} pza_i2c_t;

void pza_i2c_init(pza_i2c_t *regs);
void pza_i2c_run(pza_i2c_t *regs);

#endif