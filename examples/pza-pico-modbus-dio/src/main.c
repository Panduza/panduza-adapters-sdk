#include "panduza/dio.h"
#include "panduza/interface.h"
#include <stdio.h>

int main()
{
    pza_platform_init();
    pza_interface_init();

    // init the panduza dio modbus device and regs + bind
    pza_dio_t dio = {0};
    const uint32_t gpioMask = ~((1 << 31) | (1 << 30) | (1 << 29) | (1 << 24) | (1 << 23)); // disable io 31/30/29/24/23
    pza_dio_init(&dio, gpioMask);

    while (1)
    {
        pza_interface_run();
        pza_dio_run(&dio);
    }
    return 0;
}
