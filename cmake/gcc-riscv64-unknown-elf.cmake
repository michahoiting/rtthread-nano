# \file cmake/gcc-riscv64-unknown-elf.cmake
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Toolchain settings CMake file.

# Toolchain settings
#riscv64-unknown-elf-
#$ENV{CROSS_COMPILE}
if(NOT DEFINED ENV{CROSS_COMPILE})
message(FATAL_ERROR "Enviroment variable CROSS_COMPILE is not set")
endif()

set(CMAKE_C_COMPILER    $ENV{CROSS_COMPILE}gcc)
set(CMAKE_CXX_COMPILER  $ENV{CROSS_COMPILE}g++)
#set(CMAKE_ASM_COMPILE_OBJECT $ENV{CROSS_COMPILE}ld)
set(AS                  $ENV{CROSS_COMPILE}as)
set(AR                  $ENV{CROSS_COMPILE}ar)
set(OBJCOPY             $ENV{CROSS_COMPILE}objcopy)
set(OBJDUMP             $ENV{CROSS_COMPILE}objdump)
set(SIZE                $ENV{CROSS_COMPILE}size)
set(STRIP               $ENV{CROSS_COMPILE}strip)
set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# This makes the test compiles use static library option so that we don't need to pre-set linker flags and scripts
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_FLAGS   "${MCPU_FLAGS} ${SPEC_FLAGS} -I/usr/include -fmessage-length=0 -fno-builtin-printf" CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS "${MCPU_FLAGS} -fmessage-length=0" CACHE INTERNAL "cxx compiler flags")
set(CMAKE_ASM_FLAGS "${MCPU_FLAGS} -fmessage-length=0" CACHE INTERNAL "asm compiler flags")
set(CMAKE_EXE_LINKER_FLAGS "${MCPU_FLAGS} ${LD_FLAGS} -static -nostdlib -nostartfiles -Wno-unused -Wl,--no-relax -Wl,--gc-sections -ffreestanding -ffunction-sections -fdata-sections" CACHE INTERNAL "exe link flags")

SET(CMAKE_C_FLAGS_DEBUG "-Og -g -ggdb3" CACHE INTERNAL "c debug compiler flags")
SET(CMAKE_CXX_FLAGS_DEBUG "-Og -g -ggdb3" CACHE INTERNAL "cxx debug compiler flags")
SET(CMAKE_ASM_FLAGS_DEBUG "-g -ggdb3" CACHE INTERNAL "asm debug compiler flags")

SET(CMAKE_C_FLAGS_RELEASE "-O3" CACHE INTERNAL "c release compiler flags")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3" CACHE INTERNAL "cxx release compiler flags")
SET(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm release compiler flags")

SET(CMAKE_C_FLAGS_RELEASE "-Os" CACHE INTERNAL "c release compiler flags")
SET(CMAKE_CXX_FLAGS_RELEASE "-Os" CACHE INTERNAL "cxx release compiler flags")
SET(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm release compiler flags")
