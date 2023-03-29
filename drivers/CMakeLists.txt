add_subdirectory(panduza_dio)
add_subdirectory(panduza_uart)
add_subdirectory(panduza_spi)
add_subdirectory(panduza_i2c)

add_library(panduza_drivers INTERFACE)
add_library(panduza::drivers ALIAS panduza_drivers)

target_link_libraries(panduza_drivers INTERFACE
    panduza_dio
    panduza_uart
    panduza_spi
    panduza_i2c
)