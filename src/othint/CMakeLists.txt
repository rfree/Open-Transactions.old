cmake_minimum_required (VERSION 2.6)
project (othint)
file(GLOB othint_SRC
	"*.cpp"
)

option(WITH_EDITLINE "Use Editline library" ON)
option(WITH_WRAPPER "Build with wrapper" OFF)

if (WITH_WRAPPER)
	set(CMAKE_CXX_COMPILER "$HOME/.local/bin/compile-cxx")
	set(CMAKE_CC_COMPILER "$HOME/.local/bin/compile-cc")
endif (WITH_WRAPPER)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g3 -O0")
add_executable(othint ${othint_SRC})

if (WITH_EDITLINE)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/") # Add folder with cmake modules
	find_package(Editline)
	if (EDITLINE_FOUND)
		include_directories(${EDITLINE_INCLUDE_DIR})
		target_link_libraries (othint ${EDITLINE_LIBRARY})
	endif (EDITLINE_FOUND)
endif(WITH_EDITLINE)
