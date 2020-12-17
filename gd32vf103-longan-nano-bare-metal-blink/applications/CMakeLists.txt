# \file gd32vf103-longan-nano-bare-metal-blink/applications/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Applications CMake file.

project(gd32vf103-longan-nano-bare-metal-blink
        VERSION 0.1.0
        LANGUAGES C ASM
        )

add_executable(${PROJECT_NAME}.elf
    bare-metal-longan-nano-blink.c
    )

target_link_libraries(${PROJECT_NAME}.elf
    gd32vf103_longan_nano_firmware
    gcc
    )

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map
    -Wl,--print-memory-usage
    )

add_custom_target(size
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND ${SIZE} ${PROJECT_NAME}.elf
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )

add_custom_target(${PROJECT_NAME}.out
    DEPENDS size
    BYPRODUCTS ${PROJECT_NAME}.S
    COMMAND ${STRIP} -p -s -g -S -d -o ${PROJECT_NAME}.out ${PROJECT_NAME}.elf
    COMMAND ${SIZE} ${PROJECT_NAME}.out
    COMMAND ${OBJDUMP} --disassemble-all ${PROJECT_NAME}.out > ${PROJECT_NAME}.S
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )

add_custom_target(${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}.out
    COMMAND ${OBJCOPY} -O ihex ${PROJECT_NAME}.out ${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )

add_custom_target(flash
    DEPENDS ${PROJECT_NAME}.hex
    COMMAND $ENV{HOME}/.platformio/packages/tool-gd32vflash/stm32flash -b 115200  /dev/ttyUSB0 -g 0x08000000 -R -w  ${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    USES_TERMINAL
    )
