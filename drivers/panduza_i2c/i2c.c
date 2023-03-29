#include "panduza/i2c.h"
#include "panduza/platform/platform_i2c.h"
#include "panduza/interface/interface_i2c.h"
#include <string.h>

#define PZA_I2C_ADDRESS 0x03

static const uint8_t pza_i2c_magic[] = "PZAI2C";

void pza_i2c_init(pza_i2c_t *regs)
{
    regs->id = PZA_I2C_ADDRESS;
    memcpy(regs->identifier.content.magic, pza_i2c_magic, sizeof(pza_i2c_magic));
    pza_platform_i2c_init(regs->control.content.baudrate);
    pza_interface_bind_i2c(regs);
}

void pza_i2c_run(pza_i2c_t *regs)
{

}