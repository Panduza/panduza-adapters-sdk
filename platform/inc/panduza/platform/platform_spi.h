#ifndef PANDUZA_PLATFORM_SPI_H
#define PANDUZA_PLATFORM_SPI_H
#pragma once

#include <stdint.h>

void pza_platform_spi_init();
void pza_platform_spi_transfer(uint8_t *buff_write, uint8_t *buff_read, uint32_t len);

#endif