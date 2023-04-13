#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "tusb.h"
#include "modbus/modbus.h"
#include "hardware/timer.h"

#define MODBUS_PORT 0

int64_t pza_platform_modbus_alarm(alarm_id_t alarm_num, void *user_data)
{
    modbusController_t *controller = user_data;
    modbus_flush(controller);
}

uint32_t pza_platform_modbus_read(modbusController_t *controller, uint8_t *buf, uint8_t len)
{
    tusb_init();
    uint32_t count=0;
    if (tud_cdc_n_connected(MODBUS_PORT))
    {
        if (tud_cdc_n_available(MODBUS_PORT))
        {
            count = tud_cdc_n_read(MODBUS_PORT, buf, len);
            if(controller->alarm_id > 0)
                cancel_alarm(controller->alarm_id);
            controller->alarm_id = add_alarm_in_ms(10, pza_platform_modbus_alarm, controller, true);
        }
    }
    return count;
}

uint32_t pza_platform_modbus_write(modbusController_t *controller, const uint8_t * const buf, uint8_t len)
{
    irq_set_enabled(PICO_STDIO_USB_LOW_PRIORITY_IRQ, false);
    uint16_t remaining = len;
    do
    {
        uint32_t ret = tud_cdc_n_write(
            MODBUS_PORT,
            buf + (len-remaining),
            remaining > CFG_TUD_CDC_TX_BUFSIZE ? CFG_TUD_CDC_TX_BUFSIZE : remaining
            );
        remaining -= ret;
    } while(remaining);
    // tud_task();
    tud_cdc_n_write_flush(MODBUS_PORT);
    irq_set_enabled(PICO_STDIO_USB_LOW_PRIORITY_IRQ, true);
    // irq_set_pending(PICO_STDIO_USB_LOW_PRIORITY_IRQ);
    if(controller->alarm_id > 0)
        cancel_alarm(controller->alarm_id);
    return remaining;
}
