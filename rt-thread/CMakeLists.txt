# \file rt-thread/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Libraries CMake file.

project(rttread-nano
    VERSION 4.0.1
    LANGUAGES C ASM
    )

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    )

add_subdirectory(bsp)
add_subdirectory(components)
add_subdirectory(libcpu)
add_subdirectory(src)
