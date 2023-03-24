#include "modbus/modbus.h"
#include "panduza/platform/platform_modbus.h"
#include "panduza/dio.h"
#include "panduza/uart.h"

static modbusController_t controller = {0};
static modbusDevice_t devices[254] = {0};

static uint8_t RWAccessMask[MODBUS_RTU_ADU_MAX] = {-1};

void pza_interface_init(void)
{
    modbus_init(&controller);
    modbus_register_platform(&controller, pza_platform_modbus_read, pza_platform_modbus_write);
}

void pza_interface_bind_dio(pza_dio_t *regs)
{
    modbusDevice_t *device = &devices[regs->id];
    device->address = regs->id;
    modbusDevice_add_coilRegister(device, regs->control.reg, sizeof(regs->control.reg), regs->identifier.content.accessMask.reg);
    modbusDevice_add_inputRegister(device, regs->identifier.reg, sizeof(regs->identifier.reg));
    modbusDevice_add_discretInputRegister(device, regs->inputs.reg, sizeof(regs->inputs.reg));
    modbus_add_device(&controller, device);
}

void pza_interface_bind_uart(pza_uart_t *regs)
{
    modbusDevice_t *device = &devices[regs->id];
    device->address = regs->id;
    modbusDevice_add_holdingRegister(device, regs->control.reg, sizeof(regs->control.reg), RWAccessMask);
    modbusDevice_add_inputRegister(device, regs->identifier.reg, sizeof(regs->identifier.reg));
    modbus_add_device(&controller, device);
}


void pza_interface_run(void)
{
    modbus_run(&controller);
}