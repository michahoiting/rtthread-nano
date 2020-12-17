# gd32vf103-longan-nano-blink


## Building

### Configure
```shell
$ cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=cmake/gd32vf103.cmake -GNinja .
```
Optionally specify the build type:
- `-DCMAKE_BUILD_TYPE=DEBUG` - Enables on-target debugging
- `-DCMAKE_BUILD_TYPE=RELEASE` - Optimize on Flash memory size

### Build

```shell
$ cmake --build ./build --target all
```

### Flash to target and start the serial monitor
```shell
$ cmake --build ./build --target flash && pio device monitor -p /dev/ttyUSB0 -b 115200
```
