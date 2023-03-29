#ifndef PANDUZA_PLATFORM_I2C_H
#define PANDUZA_PLATFORM_I2C_H
#pragma once

#include "stdint.h"

void pza_platform_i2c_init(uint32_t freq);
void pza_platfrom_i2c_write(uint8_t addr, const uint8_t *src, uint8_t len, uint8_t nostop);
void pza_platfrom_i2c_read(uint8_t addr, uint8_t *dest, uint8_t len, uint8_t nostop);

#endif