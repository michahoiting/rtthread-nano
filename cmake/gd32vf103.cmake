# \file cmake/gd32vf103.cmake
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Target settings CMake file.

# Name of the target
set(CMAKE_SYSTEM_NAME unknown)
set(CMAKE_SYSTEM_PROCESSOR riscv32)

if(NOT DEFINED ENV{CROSS_COMPILE})
message(WARNING "Enviroment variable CROSS_COMPILE is not set, defaulting to riscv64-unknown-elf")
set(ENV{CROSS_COMPILE} "riscv32-unknown-elf-")
endif()

set(RT_THREAD_ARCH "risc-v")
set(RT_THREAD_CPU "bumblebee")
set(RT_THREAD_TOOLCHAIN "gcc")

#set(MCPU_FLAGS "-march=rv32imac -mabi=ilp32 -mcmodel=medlow")
set(MCPU_FLAGS "-march=rv32imac -mabi=ilp32 -DHAVE_CCONFIG_H -DUSE_PLIC -DUSE_M_TIME -DNO_INIT -mcmodel=medany -msmall-data-limit=8 -nostartfiles -lc")
#set(SPEC_FLAGS "--specs=nosys.specs")

include(${CMAKE_CURRENT_LIST_DIR}/gcc-riscv32-unknown-elf.cmake)

#------- GCC settings ----------------------------------------------------------
# if PLATFORM == 'gcc':
#     # toolchains
#     PREFIX = 'riscv-none-embed-'
#     CC = PREFIX + 'gcc'
#     CXX= PREFIX + 'g++'
#     AS = PREFIX + 'gcc'
#     AR = PREFIX + 'ar'
#     LINK = PREFIX + 'gcc'
#     TARGET_EXT = 'elf'
#     SIZE = PREFIX + 'size'
#     OBJDUMP = PREFIX + 'objdump'
#     OBJCPY = PREFIX + 'objcopy'

#     DEVICE = ' -march=rv32imac -mabi=ilp32 -DUSE_PLIC -DUSE_M_TIME -DNO_INIT -mcmodel=medany -msmall-data-limit=8 -L.  -nostartfiles  -lc '
#     CFLAGS = DEVICE
#     CFLAGS += ' -save-temps=obj'
#     AFLAGS = '-c'+ DEVICE + ' -x assembler-with-cpp'
#     AFLAGS += ' -Iplatform -Ilibraries/n22/include -Ilibraries/n22/env_Eclipse'
#     LFLAGS = DEVICE
#     LFLAGS += ' -Wl,--gc-sections,-cref,-Map=' + MAP_FILE
#     LFLAGS += ' -T ' + LINK_FILE
#     LFLAGS += ' -Wl,-wrap=memset'

#     CPATH = ''
#     LPATH = ''

#     if BUILD == 'debug':
#         CFLAGS += ' -O0 -g3'
#         AFLAGS += ' -g3'
#     else:
#         CFLAGS += ' -O2'

#     POST_ACTION = OBJCPY + ' -O binary $TARGET ' + TARGET_NAME + '\n'
#     POST_ACTION += SIZE + ' $TARGET\n'