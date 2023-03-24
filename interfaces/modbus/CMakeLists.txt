include(FetchContent)

FetchContent_Declare(
    modbus-slave-controller
    GIT_REPOSITORY  https://github.com/BCadet/modbus-slave-controller.git
    GIT_TAG main
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    GIT_SUBMODULES_RECURSE FALSE
)

FetchContent_MakeAvailable(modbus-slave-controller)

add_library(panduza_modbus)
add_library(panduza::modbus ALIAS panduza_modbus)

target_sources(panduza_modbus PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/modbus.c
)

target_include_directories(panduza_modbus PRIVATE
${CMAKE_CURRENT_LIST_DIR}/../../platform/inc
)

target_link_libraries(panduza_modbus PRIVATE
    modbus
    panduza::drivers
)