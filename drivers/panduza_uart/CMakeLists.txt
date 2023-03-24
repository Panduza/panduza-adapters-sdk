add_library(panduza_uart)
add_library(panduza::uart ALIAS panduza_uart)

target_sources(panduza_uart PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/uart.c
)

target_include_directories(panduza_uart PRIVATE
${CMAKE_CURRENT_LIST_DIR}/inc
${CMAKE_CURRENT_LIST_DIR}/../../platform/inc
${CMAKE_CURRENT_LIST_DIR}/../../interfaces/inc
)

target_include_directories(panduza_uart INTERFACE
${CMAKE_CURRENT_LIST_DIR}/inc
)
