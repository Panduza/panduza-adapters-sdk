#ifndef PANDUZA_SPI_H
#define PANDUZA_SPI_H
#pragma once

#include "stdint.h"

typedef union {
    struct control_content {
        uint8_t enable:1;
        uint8_t busy:1;
    } content;
    uint8_t reg[sizeof(struct control_content)];
} pza_spi_control_t;

typedef union {
    struct identifier_content {
        uint8_t magic[6];
    } content;
    uint8_t reg[sizeof(struct identifier_content)];
} pza_spi_identifier_t;

typedef union {
    struct write_content {
        uint8_t len;
        uint8_t write[64];
    } content;
    uint8_t reg[sizeof(struct write_content)];
} pza_spi_write_t;

typedef union {
    struct read_content {
        uint8_t len;
        uint8_t read[64];
    } content;
    uint8_t reg[sizeof(struct read_content)];
} pza_spi_read_t;

typedef struct {
    uint8_t id;
    pza_spi_control_t control;
    pza_spi_identifier_t identifier;
    pza_spi_write_t write;
    pza_spi_read_t read;
} pza_spi_t;

void pza_spi_init(pza_spi_t *regs);
void pza_spi_run(pza_spi_t *regs);

#endif