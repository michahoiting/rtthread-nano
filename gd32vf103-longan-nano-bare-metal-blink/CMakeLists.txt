# \file gd32vf103-longan-nano-blink/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Top level gd32vf103-longan-nano-blink project CMake file.

cmake_minimum_required(VERSION 3.16)

# Set up the project
project(gd32vf103_longan_nano_firmware
    VERSION 0.1.0
    LANGUAGES C ASM
    )

add_library(${PROJECT_NAME})

add_subdirectory(applications)
add_subdirectory(drivers)
add_subdirectory(libraries)
