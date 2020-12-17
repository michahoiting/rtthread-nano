# \file gd32vf103-longan-nano-bare-metal-blink/drivers/CMakeLists.txt
# \author Micha Hoiting <micha.hoiting@gmail.com>
# \brief Drivers CMake file.

target_sources(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/gd32vf103_longan_nano.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
