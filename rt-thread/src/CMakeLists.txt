# \file rt-thread/src/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief RISCV library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/clock.c
    ${CMAKE_CURRENT_LIST_DIR}/components.c
    ${CMAKE_CURRENT_LIST_DIR}/cpu.c
    ${CMAKE_CURRENT_LIST_DIR}/idle.c
    ${CMAKE_CURRENT_LIST_DIR}/ipc.c
    ${CMAKE_CURRENT_LIST_DIR}/irq.c
    ${CMAKE_CURRENT_LIST_DIR}/kservice.c
    ${CMAKE_CURRENT_LIST_DIR}/mem.c
    ${CMAKE_CURRENT_LIST_DIR}/memheap.c
    ${CMAKE_CURRENT_LIST_DIR}/mempool.c
    ${CMAKE_CURRENT_LIST_DIR}/object.c
    ${CMAKE_CURRENT_LIST_DIR}/scheduler.c
    ${CMAKE_CURRENT_LIST_DIR}/slab.c
    ${CMAKE_CURRENT_LIST_DIR}/thread.c
    ${CMAKE_CURRENT_LIST_DIR}/timer.c
    )
