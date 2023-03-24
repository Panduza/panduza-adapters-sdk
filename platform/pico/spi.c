#include "hardware/spi.h"

void pza_platform_spi_init(uint32_t baudrate)
{
    spi_init(spi0, 1000000);
}

void pza_platform_spi_write(uint8_t *buff_write, uint8_t *buff_read, uint32_t len)
{
    spi_write_read_blocking(spi0, buff_write, buff_read, len);
}