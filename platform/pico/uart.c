#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "hardware/dma.h"

uint8_t *rx_len;

static void dma_interrupt()
{
    *rx_len = 0;
    irq_clear(DMA_IRQ_0);
    dma_channel_acknowledge_irq0(0);
}

static void configure_dma(int channel, uint8_t *buffer, uint8_t len) {
    dma_channel_config config = dma_channel_get_default_config(channel);
    channel_config_set_transfer_data_size(&config, DMA_SIZE_8);

    // The read address is the address of the UART data register which is constant
    channel_config_set_read_increment(&config, false);

    // Write into a ringbuffer with '2^5=32' elements
    channel_config_set_write_increment(&config, true);
    channel_config_set_ring(&config, true, 6);

    // The UART signals when data is avaliable
    channel_config_set_dreq(&config, DREQ_UART0_RX);

    // Transmit '2^32 - 1' symbols, this should suffice for any practical case,
    // otherwise, the channel could be triggered again
    dma_channel_configure(
        channel,
        &config,
        buffer,
        &uart0_hw->dr,
        len,
        true);
}

void pza_platform_uart_init(uint32_t baudrate, uint8_t *read_buffer)
{
    uart_init(uart0, baudrate);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    // user_irq_claim(DMA_IRQ_0);
    irq_add_shared_handler(DMA_IRQ_0, dma_interrupt, PICO_SHARED_IRQ_HANDLER_LOWEST_ORDER_PRIORITY);
    irq_set_enabled(DMA_IRQ_0, true);
    dma_channel_set_irq0_enabled(0, true);
}

void pza_platform_uart_write(uint8_t *buff_write, uint8_t len)
{
    uart_write_blocking(uart0, buff_write, len);
}

void pza_platform_uart_read(uint8_t *buff_read, uint8_t *len)
{
    if(!dma_channel_is_busy(0))
    {
        configure_dma(0, buff_read, *len);
        rx_len = len;
    }
}

void pza_platform_uart_set_baudrate(uint32_t baudrate)
{
    uart_set_baudrate(uart0, baudrate);
}