# \file rt-thread/libcpu/risc-v/bumblebee/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief RISCV library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/interrupt_gcc.S
    )
