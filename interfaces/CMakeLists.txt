if(NOT PANDUZA_INTERFACE)
message(FATAL_ERROR "Please define a PANDUZA_INTERFACE")
endif()

add_subdirectory(${PANDUZA_INTERFACE})

add_library(panduza::interface ALIAS panduza_${PANDUZA_INTERFACE})

target_include_directories(panduza_${PANDUZA_INTERFACE} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_include_directories(panduza_${PANDUZA_INTERFACE} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../platform/inc
)
