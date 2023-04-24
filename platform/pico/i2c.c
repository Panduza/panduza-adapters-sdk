#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"

void pza_platform_i2c_init(uint32_t freq)
{
    i2c_init(i2c1, freq);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    gpio_pull_up(14);
    gpio_pull_up(15);
    bi_decl(bi_2pins_with_func(14, 15, GPIO_FUNC_I2C));
}

void pza_platfrom_i2c_write(uint8_t addr, const uint8_t *src, size_t len, uint8_t nostop)
{
    i2c_write_blocking(i2c1, addr, src, len, nostop);
}

void pza_platfrom_i2c_read(uint8_t addr, uint8_t *dest, size_t len, uint8_t nostop)
{
    i2c_read_blocking(i2c1, addr, dest, len, nostop);
}