add_library(panduza_platform_pico)

target_sources(panduza_platform_pico PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/modbus.c
    ${CMAKE_CURRENT_LIST_DIR}/dio.c
    ${CMAKE_CURRENT_LIST_DIR}/platform.c
    ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
    ${CMAKE_CURRENT_LIST_DIR}/uart.c
    ${CMAKE_CURRENT_LIST_DIR}/spi.c
)

target_include_directories(panduza_platform_pico PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(panduza_platform_pico INTERFACE
    pico_stdlib
    pico_stdio_usb
    pico_bootrom
    hardware_uart
    hardware_spi
    modbus
)



target_link_libraries(panduza_platform_pico PRIVATE
    pico_stdlib_headers
    pico_stdio_usb_headers
    pico_bootrom_headers
    hardware_uart_headers
    hardware_spi_headers
    modbus
    tinyusb_device_unmarked
)

# USB definition
target_compile_definitions(panduza_platform_pico PUBLIC USB_PID=0x16C0) # ID_VENDOR
target_compile_definitions(panduza_platform_pico PUBLIC USB_VID=0x05E1) # ID_MODEL_ID
target_compile_definitions(panduza_platform_pico PUBLIC MANUFACTURER="panduza.io") # ID_VENDOR
target_compile_definitions(panduza_platform_pico PUBLIC PRODUCT="dio-modbus") #ID_MODEL