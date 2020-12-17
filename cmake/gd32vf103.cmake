# \file cmake/gd32vf103.cmake
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Target settings CMake file.

# Name of the target
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR rv32imac)

set(RT_THREAD_ARCH "rv32imac")
set(RT_THREAD_ARCH_TOOLCHAIN "gnu")

set(MCPU_FLAGS "-march=rv32imac -mabi=ilp32 -mcmodel=medlow")
set(VFP_FLAGS "")
#set(SPEC_FLAGS "--specs=nosys.specs")

if(NOT DEFINED ENV{CROSS_COMPILE})
message(WARNING "Enviroment variable CROSS_COMPILE is not set, defaulting to riscv64-unknown-elf")
set(ENV{CROSS_COMPILE} "riscv64-unknown-elf-")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/gcc-riscv64-unknown-elf.cmake)
