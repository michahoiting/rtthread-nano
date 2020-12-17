# \file CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Top level CMake file.

cmake_minimum_required(VERSION 3.16)

# Set up the project
project(rtthread-nano
    VERSION 3.1.3
    LANGUAGES C ASM
    )


if(NOT DEFINED RT_THREAD_ARCH)
    message(FATAL_ERROR "Error: RT_THREAD_ARCH not defined")
endif()
if(NOT DEFINED RT_THREAD_ARCH_TOOLCHAIN)
    message(FATAL_ERROR "Error: RT_THREAD_ARCH_TOOLCHAIN not defined")
endif()

# Define our target library and an alias for consumers
#add_library(${PROJECT_NAME})

# # A place for generated/copied include files (no need to change)
# set(CUSTOM_INC_DIR ${CMAKE_CURRENT_BINARY_DIR}/custom_inc)

# Pick up the port specific variables and apply them
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/ports/${THREADX_ARCH}/${THREADX_TOOLCHAIN})

# # Pick up the common stuff
# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/common)

# # If the user provided an override, copy it to the custom directory
# if (NOT TX_USER_FILE)
#     message(STATUS "Using default tx_user.h file")
#     set(TX_USER_FILE ${CMAKE_CURRENT_LIST_DIR}/common/inc/tx_user_sample.h)
# else()
#     message(STATUS "Using custom tx_user.h file from ${TX_USER_FILE}")
# endif()
# configure_file(${TX_USER_FILE} ${CUSTOM_INC_DIR}/tx_user.h COPYONLY)
# target_include_directories(${PROJECT_NAME} 
#     PUBLIC 
#     ${CUSTOM_INC_DIR}
# )
# target_compile_definitions(${PROJECT_NAME} PUBLIC "TX_INCLUDE_USER_DEFINE_FILE" )

# # Enable a build target that produces a ZIP file of all sources
# set(CPACK_SOURCE_GENERATOR "ZIP")
# set(CPACK_SOURCE_IGNORE_FILES
#   \\.git/
#   \\.github/
#   _build/
#   \\.git
#   \\.gitattributes
#   \\.gitignore
#   ".*~$"
# )
# set(CPACK_VERBATIM_VARIABLES YES)
# include(CPack)

#add_subdirectory(rt-thread)
add_subdirectory(gd32vf103-longan-nano-bare-metal-blink)
