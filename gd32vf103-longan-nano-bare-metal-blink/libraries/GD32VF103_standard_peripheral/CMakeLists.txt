# \file libraries/GD32VF103_standard_peripheral/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief GD32VF103_standard_peripheral library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/system_gd32vf103.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_crc.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_dac.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_exmc.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_fwdgt.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_wwdgt.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_rcu.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_eclic.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_dbg.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_timer.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_rtc.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_usart.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_dma.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_i2c.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_adc.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_fmc.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_bkp.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_exti.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_can.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/gd32vf103_pmu.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/Include
)
