#ifndef PANDUZA_PLATFORM_MODBUS_H
#define PANDUZA_PLATFORM_MODBUS_H
#pragma once

#include "modbus/modbus.h"

uint32_t pza_platform_modbus_write(modbusController_t *controller, const uint8_t *const buf, uint8_t len);
uint32_t pza_platform_modbus_read(modbusController_t *controller, uint8_t *buf, uint8_t len);

#endif