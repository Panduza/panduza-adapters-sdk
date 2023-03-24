add_subdirectory(${PANDUZA_PLATFORM})

add_library(panduza::platform ALIAS panduza_platform_${PANDUZA_PLATFORM})

target_include_directories(panduza_platform_${PANDUZA_PLATFORM} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/inc
)
