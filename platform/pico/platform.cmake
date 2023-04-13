include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    pico-sdk
    GIT_REPOSITORY  https://github.com/raspberrypi/pico-sdk.git
    GIT_TAG 1.5.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    GIT_SUBMODULES_RECURSE FALSE
)

FetchContent_Populate(pico-sdk)

include(${CMAKE_CURRENT_LIST_DIR}/../toolchain/arm-gcc.cmake)
message(STATUS "using toolchain: ${gcc-arm-none-eabi_SOURCE_DIR}")

set(PICO_SDK_PATH ${pico-sdk_SOURCE_DIR} CACHE FILEPATH "PICO_SDK_PATH")
set(PICO_TOOLCHAIN_PATH ${gcc-arm-none-eabi_SOURCE_DIR} CACHE FILEPATH "PICO_TOOLCHAIN_PATH")
set(PICO_PLATFORM "rp2040")
set(PICO_COMPILER "pico_arm_gcc")
set(PICO_BOARD "pico")
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

macro(panduza_platfrom_init TARGET)
    pico_sdk_init()
    # find gdb for debugger (pico_sdk_init forget to set it).
    # see build/_deps/pico-sdk-src/cmake/preload/toolchains/pico_arm_gcc.cmake)
    pico_find_compiler(PICO_COMPILER_GDB arm-none-eabi-gdb)
    set(CMAKE_DEBUGGER ${PICO_COMPILER_GDB} CACHE FILEPATH "path to gdb")

    # target_compile_definitions(${TARGET} PUBLIC
    #     -DCFG_TUSB_CONFIG_FILE="pico_tusb_config.h"
    #     # -DPICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS=-1 # wait in stdio_usb_init until usb is connected
    #     # -DPICO_STDIO_USB_POST_CONNECT_WAIT_DELAY_MS=1000 # wait 1s AFTER the usb is conected
    #     -DPICO_STDIO_USB_LOW_PRIORITY_IRQ=0x1f
    # )

    target_compile_definitions(panduza_platform_pico PUBLIC
        -DCFG_TUSB_CONFIG_FILE="pico_tusb_config.h"
        # -DPICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS=-1 # wait in stdio_usb_init until usb is connected
        # -DPICO_STDIO_USB_POST_CONNECT_WAIT_DELAY_MS=1000 # wait 1s AFTER the usb is conected
        -DPICO_STDIO_USB_LOW_PRIORITY_IRQ=0x1f
    )

    # # disable usb output, enable uart output
    
    pico_enable_stdio_uart(${TARGET} 1)
    pico_enable_stdio_usb(${TARGET} 1)

    # create uf2 
    pico_add_uf2_output(${TARGET} )
    # aditionnal cleanup
    set_property(
        TARGET ${TARGET}
        APPEND
        PROPERTY ADDITIONAL_CLEAN_FILES 
        ${TARGET}.bin
        ${TARGET}.dis
        ${TARGET}.elf.map
        ${TARGET}.hex
        ${TARGET}.uf2
    )



    # exclude stdio_usb_descriptors.c from compilation of pico_stdio_usb lib to use mine instead
    set_source_files_properties(
        ${pico-sdk_SOURCE_DIR}/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c
        PROPERTIES HEADER_FILE_ONLY ON
    )

endmacro()