#include "panduza/dio.h"
#include "panduza/platform/platform_dio.h"
#include "panduza/interface/interface_dio.h"
#include <string.h>

#define PZA_DIO_ADDRESS 0x01

static const uint8_t pza_dio_magic[] = "PZADIO";

void pza_dio_init(pza_dio_t *regs, uint32_t enable)
{
    regs->id = PZA_DIO_ADDRESS;
    memcpy(regs->identifier.content.magic, pza_dio_magic, sizeof(pza_dio_magic));
    regs->identifier.content.IOs = __builtin_popcount(enable);
    regs->identifier.content.accessMask.content.direction = enable;
    regs->identifier.content.accessMask.content.pulls = enable;
    regs->identifier.content.accessMask.content.values = enable;
    pza_platform_dio_init(enable);
    pza_interface_bind_dio(regs);
}

void pza_dio_run(pza_dio_t *regs)
{
    regs->inputs.content.inputs = pza_platform_dio_update(
        regs->control.content.direction,
        regs->control.content.pulls,
        regs->control.content.values);
}