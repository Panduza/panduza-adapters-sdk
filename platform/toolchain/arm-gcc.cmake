include(FetchContent)

if(${CMAKE_VERSION} VERSION_LESS "3.17.0")
    FetchContent_Declare(
        gcc-arm-none-eabi
        URL https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
        URL_MD5 2383e4eb4ea23f248d33adc70dc3227e
    )
else()
    FetchContent_Declare(
        gcc-arm-none-eabi
        URL https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        URL_MD5 2383e4eb4ea23f248d33adc70dc3227e
    )
endif()


FetchContent_MakeAvailable(gcc-arm-none-eabi)