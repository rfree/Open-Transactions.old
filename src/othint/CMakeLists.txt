cmake_minimum_required (VERSION 2.6)
project (othint)
file(GLOB othint_SRC
	"*.h"
	"*.hpp"
	"*.cpp"
)

option(WITH_READLINE "Use GNU Readline library" ON)
option(WITH_WRAPPER "Build with wrapper" OFF)

if (WITH_WRAPPER)
	set(CMAKE_CXX_COMPILER "$HOME/.local/bin/compile-cxx")
	set(CMAKE_CC_COMPILER "$HOME/.local/bin/compile-cc")
endif (WITH_WRAPPER)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g3 -O0")
add_executable(othint ${othint_SRC})

if (WITH_READLINE) # if Readline was found in the system
	add_definitions(-DOT_ALLOW_GNU_LIBRARIES=1)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/") # Add folder with cmake modules
	find_package(readline) # Find Readline libs and headers
	if (READLINE_FOUND)
		message("[DBG]READLINE_INCLUDE_DIR: " ${READLINE_INCLUDE_DIR} " READLINE_LIBRARY: " ${READLINE_LIBRARY}) # For debug
		include_directories(${READLINE_INCLUDE_DIR})
		target_link_libraries (othint ${READLINE_LIBRARY})
	endif (READLINE_FOUND)
endif(WITH_READLINE)
