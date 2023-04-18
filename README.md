# How to build

go to the current directory

```bash
    cd examples/pza-pico-modbus-dio
```

```bash 
    mkdir build
    cd build
    cmake ..
    make
```

flash the .uf2 file of the build dir to the pico

```bash
    cp pza-pico-modbus-dio.uf2 /media/<user>/RP2_RPI
```