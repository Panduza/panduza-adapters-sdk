#include "panduza/spi.h"
#include "panduza/platform/platform_spi.h"
#include <string.h>

#define PZA_SPI_ADDRESS 0x03

static const uint8_t pza_spi_magic[] = "PZASPI";

void pza_spi_init(pza_spi_t *regs)
{
    regs->id = PZA_SPI_ADDRESS;
    memcpy(regs->identifier.content.magic, pza_spi_magic, sizeof(pza_spi_magic));
    pza_platform_spi_init();
}

void pza_spi_run(pza_spi_t *regs)
{
    if(strlen(regs->control.content.enable))
    {
        regs->control.content.busy = 1;
        pza_platform_spi_transfer(regs->write.content.write, regs->read.content.read, strlen(regs->write.content.len));
        regs->control.content.busy = 0;
    }
}