add_library(panduza_platform_pico)

target_sources(panduza_platform_pico PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/modbus.c
    ${CMAKE_CURRENT_LIST_DIR}/dio.c
    ${CMAKE_CURRENT_LIST_DIR}/platform.c
    ${CMAKE_CURRENT_LIST_DIR}/uart.c
    ${CMAKE_CURRENT_LIST_DIR}/spi.c
    ${CMAKE_CURRENT_LIST_DIR}/i2c.c
)

target_link_libraries(panduza_platform_pico INTERFACE
    pico_stdlib
    pico_stdio_usb
    pico_bootrom
    hardware_uart
    hardware_spi
    hardware_i2c
    modbus
)

target_link_libraries(panduza_platform_pico PRIVATE
    pico_stdlib_headers
    pico_stdio_usb_headers
    pico_bootrom_headers
    hardware_uart_headers
    hardware_spi_headers
    hardware_i2c_headers
    modbus
)
