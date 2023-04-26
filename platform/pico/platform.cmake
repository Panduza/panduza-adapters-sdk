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

    # # disable usb output, enable uart output
    pico_enable_stdio_uart(${TARGET} 0)
    pico_enable_stdio_usb(${TARGET} 1)

    # create uf2 
    pico_add_uf2_output(${TARGET})
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

    target_compile_definitions(${TARGET} PRIVATE
        USBD_VID=0x16C0 # ID_VENDOR_ID
        USBD_PID=0x05E1 # ID_MODEL_ID
        USBD_MANUFACTURER="panduza.io" # ID_VENDOR
        USBD_PRODUCT="dio-modbus" # ID_MODEL
    ) 

endmacro()