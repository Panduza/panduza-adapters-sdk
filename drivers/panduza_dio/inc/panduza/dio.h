#ifndef PANDUZA_DIO_H
#define PANDUZA_DIO_H
#pragma once

#include <stdint.h>

typedef union {
    struct dio_control_content {
        uint32_t direction;
        uint32_t pulls;
        uint32_t values;
    } content;
    uint8_t reg[sizeof(struct dio_control_content)];
} pza_dio_control_t;

typedef union {
    struct dio_identifier_content {
        uint8_t magic[6];
        uint8_t IOs;
        pza_dio_control_t accessMask;
    } content;
    uint8_t reg[sizeof(struct dio_identifier_content)];
} pza_dio_identifier_t;

typedef union {
    struct dio_input_content {
        uint32_t inputs;
    } content;
    uint8_t reg[sizeof(struct dio_input_content)];
} pza_dio_input_t;

typedef struct {
    uint8_t id;
    pza_dio_control_t control;
    pza_dio_identifier_t identifier;
    pza_dio_input_t inputs;
} pza_dio_t;

void pza_dio_init(pza_dio_t *regs, uint32_t mask);
void pza_dio_run(pza_dio_t *regs);

#endif 