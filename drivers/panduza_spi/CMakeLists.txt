add_library(panduza_spi)
add_library(panduza::spi ALIAS panduza_spi)

target_sources(panduza_spi PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/panduza_spi.c
)

target_include_directories(panduza_spi PRIVATE
${CMAKE_CURRENT_LIST_DIR}/inc
${CMAKE_CURRENT_LIST_DIR}/../../platform/inc
${CMAKE_CURRENT_LIST_DIR}/../../interfaces/inc
)

target_include_directories(panduza_spi INTERFACE
${CMAKE_CURRENT_LIST_DIR}/inc
)

# target_link_libraries(panduza_spi
#     panduza::platform
# )