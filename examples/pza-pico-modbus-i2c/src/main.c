#include "panduza/i2c.h"
#include "panduza/interface.h"
#include "panduza/platform.h"
#include <stdio.h>

int main()
{
    pza_platform_init();
    pza_interface_init();

    pza_i2c_t i2c = {0};
    pza_i2c_init(&i2c);

    while (1)
    {
        pza_interface_run();
        pza_i2c_run(&i2c);
    }
    return 0;
}
