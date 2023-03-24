#include "panduza/uart.h"
#include "panduza/platform/platform_uart.h"
#include "panduza/interface/interface_uart.h"
#include <string.h>

#define PZA_UART_ADDRESS 0x02

static const uint8_t pza_uart_magic[] = "PZASERI";

void pza_uart_init(pza_uart_t *regs)
{
    regs->id = PZA_UART_ADDRESS;
    memcpy(regs->identifier.content.magic, pza_uart_magic, sizeof(pza_uart_magic));
    regs->identifier.content.bufferSize = 64;
    pza_platform_uart_init(regs->control.content.baudrate);
    pza_interface_bind_uart(regs);
}

void pza_uart_run(pza_uart_t *regs)
{
    if(strlen(regs->control.content.write))
    {
        pza_platform_uart_write(regs->control.content.write, strlen(regs->control.content.write));
    }
}