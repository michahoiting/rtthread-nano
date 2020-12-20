# \file rt-thread/libcpu/common/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief RISCV library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/context_gcc.S
    ${CMAKE_CURRENT_LIST_DIR}/cpuport.c
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    )
