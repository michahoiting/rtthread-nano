# \file libraries/RISCV/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief RISCV library CMake file.

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/entry.S
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/start.S
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/init.c
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/handlers.c
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/init_array.c
    ${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/fini_array.c
    ${CMAKE_CURRENT_LIST_DIR}/drivers/n200_func.c
    ${CMAKE_CURRENT_LIST_DIR}/drivers/systick.c

    ${CMAKE_CURRENT_LIST_DIR}/stubs/crt0.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/exit.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/string.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/read.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/sbrk.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/close.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/fstat.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/write.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/write_hex.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/lseek.c
    ${CMAKE_CURRENT_LIST_DIR}/stubs/isatty.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/drivers
    ${CMAKE_CURRENT_LIST_DIR}/stubs
    ${CMAKE_CURRENT_LIST_DIR}/Include
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    -DHAVE_INITFINI_ARRAY
    -DHAVE_INIT_FINI
    )

target_link_options(${PROJECT_NAME} PUBLIC
    "-T${CMAKE_CURRENT_LIST_DIR}/env_Eclipse/GD32VF103xB.lds"
    )
