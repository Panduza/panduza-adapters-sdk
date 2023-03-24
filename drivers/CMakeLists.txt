add_subdirectory(panduza_dio)
add_subdirectory(panduza_uart)
add_subdirectory(panduza_spi)

add_library(panduza_drivers INTERFACE EXCLUDE_FROM_ALL)
add_library(panduza::drivers ALIAS panduza_drivers)

target_link_libraries(panduza_drivers INTERFACE
    panduza_dio
    panduza_uart
    panduza_spi
)