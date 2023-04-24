add_library(panduza_dio)
add_library(panduza::dio ALIAS panduza_dio)

target_sources(panduza_dio PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/dio.c
)

target_include_directories(panduza_dio PRIVATE
${CMAKE_CURRENT_LIST_DIR}/inc
${CMAKE_CURRENT_LIST_DIR}/../../platform/inc
${CMAKE_CURRENT_LIST_DIR}/../../interfaces/inc
)

target_include_directories(panduza_dio INTERFACE
${CMAKE_CURRENT_LIST_DIR}/inc
)
