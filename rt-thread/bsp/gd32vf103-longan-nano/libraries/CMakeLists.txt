# \file rt-thread/bsp/gd32vf103-longan-nano/libraries/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief CMake file for the GD32vf103 Longan Nano BSP library.

target_sources(${PROJECT_NAME}
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/n22/env_Eclipse/start.S
    ${CMAKE_CURRENT_LIST_DIR}/n22/env_Eclipse/entry.S
    ${CMAKE_CURRENT_LIST_DIR}/n22/env_Eclipse/handlers.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/env_Eclipse/init.c

    ${CMAKE_CURRENT_LIST_DIR}/n22/drivers/n22_func.c

    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/read.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/sbrk.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/close.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/fstat.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/write.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/write_hex.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/lseek.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/stub.h
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/_exit.c
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs/isatty.c

    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/system_gd32vf103.c

    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_crc.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_dac.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_exmc.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_fwdgt.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_wwdgt.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_rcu.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_eclic.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_dbg.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_timer.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_rtc.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_usart.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_dma.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_i2c.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_adc.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_fmc.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_bkp.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_exti.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_can.c
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Source/gd32vf103_pmu.c
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/n22/drivers
    ${CMAKE_CURRENT_LIST_DIR}/n22/stubs
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral
    ${CMAKE_CURRENT_LIST_DIR}/GD32VF103_standard_peripheral/Include
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    -DHAVE_INITFINI_ARRAY
    -DHAVE_INIT_FINI
    )

target_link_options(${PROJECT_NAME} PUBLIC
    "-T${CMAKE_CURRENT_LIST_DIR}/n22/env_Eclipse/GD32VF103xB.lds"
    )
