if(NOT PANDUZA_PLATFORM)
message(FATAL_ERROR "Please define a PANDUZA_PLATFORM")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/${PANDUZA_PLATFORM}/platform.cmake)