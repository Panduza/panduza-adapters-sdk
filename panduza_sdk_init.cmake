macro(panduza_sdk_init TARGET)
    if (NOT CMAKE_PROJECT_NAME)
        message(WARNING "panduza_sdk_init() should be called after the project is created (and languages added)")
    endif()
    
    add_subdirectory(${PANDUZA_SDK_PATH} panduza-sdk)
    panduza_platfrom_init(${TARGET})
endmacro()

include(${PANDUZA_SDK_PATH}/platform/panduza_platform.cmake)