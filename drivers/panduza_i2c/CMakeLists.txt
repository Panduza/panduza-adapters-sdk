add_library(panduza_i2c)
add_library(panduza::i2c ALIAS panduza_i2c)

target_sources(panduza_i2c PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/i2c.c
)

target_include_directories(panduza_i2c PRIVATE
${CMAKE_CURRENT_LIST_DIR}/inc
${CMAKE_CURRENT_LIST_DIR}/../../platform/inc
${CMAKE_CURRENT_LIST_DIR}/../../interfaces/inc
)

target_include_directories(panduza_i2c INTERFACE
${CMAKE_CURRENT_LIST_DIR}/inc
)
