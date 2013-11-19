cmake_minimum_required (VERSION 2.6)
project (othint)
file(GLOB othint_SRC
	"*.h"
	"*.hpp"
	"*.c"
	"*.cpp"
)
SET(CMAKE_CXX_FLAGS "-std=c++11 -g3 -O0 -DOT_ALLOW_GNU_LIBRARIES=1")
#Find module for Readline
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

add_executable(othint ${othint_SRC})
find_package(readline)
if (READLINE_FOUND)
	message("[DBG]READLINE_INCLUDE_DIR: " ${READLINE_INCLUDE_DIR} " READLINE_LIBRARY: " ${READLINE_LIBRARY}) #for debug
	include_directories(${READLINE_INCLUDE_DIR})
	target_link_libraries (othint ${READLINE_LIBRARY})
endif (READLINE_FOUND)
