#ifndef PANDUZA_PLATFORM_DIO_H
#define PANDUZA_PLATFORM_DIO_H
#pragma once

#include <stdint.h>

void pza_platform_dio_init(uint32_t mask);
uint32_t pza_platform_dio_update(uint32_t directions, uint32_t pulls, uint32_t values);

#endif