FROM ubuntu:22.04


# Install Packages
RUN apt-get update && DEBIAN_FRONTEND=noninteractive TZ=Europe/Paris \
    apt-get -y install \
    g++ \
    make \
    cmake \
    wget \
    git

# RUN apt-get update && DEBIAN_FRONTEND=noninteractive TZ=Europe/Paris \
#     apt-get -y install \
#     gcc-arm-none-eabi

WORKDIR /sdk

# Create the directory for platform plugins
# Then run the platform
CMD cmake --version;\
    mkdir -p /sdk/examples/pza-pico-modbus-dio/build; \
    cd /sdk/examples/pza-pico-modbus-dio/build;\
    cmake .. &&\
    make

