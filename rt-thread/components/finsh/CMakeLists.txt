# \file rt-thread/components/finsh/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief RISCV library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/cmd.c
    ${CMAKE_CURRENT_LIST_DIR}/msh.c
    ${CMAKE_CURRENT_LIST_DIR}/shell.c
    )
