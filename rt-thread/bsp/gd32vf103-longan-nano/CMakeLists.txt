# \file rt-thread/bsp/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Drivers CMake file.

add_subdirectory(applications)
add_subdirectory(board)
add_subdirectory(libraries)

# pickup rtconfig.h
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    )
