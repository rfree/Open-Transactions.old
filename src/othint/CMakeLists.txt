cmake_minimum_required (VERSION 2.6)
project (othint)
file(GLOB othint_SRC
	"*.cpp"
)

option(LOCAL_EDITLINE "Use local Editline library ($HOME/.local)" OFF)
option(WITH_WRAPPER "Build with wrapper" OFF)

if (WITH_WRAPPER)
	set(CMAKE_CXX_COMPILER "$HOME/.local/bin/compile-cxx")
	set(CMAKE_CC_COMPILER "$HOME/.local/bin/compile-cc")
endif (WITH_WRAPPER)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g3 -O0")
add_executable(othint ${othint_SRC})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/") # Add folder with cmake modules

if (LOCAL_EDITLINE)
	set(CMAKE_PREFIX_PATH "$ENV{HOME}/.local")
	find_package(EditlineLocal)
	if (EDITLINE_FOUND)
		include_directories(${EDITLINE_INCLUDE_DIR})
		target_link_libraries (othint ${EDITLINE_LIBRARY})
	endif (EDITLINE_FOUND)
else (LOCAL_EDITLINE)
	find_package(Editline)
	if (EDITLINE_FOUND)
		include_directories(${EDITLINE_INCLUDE_DIR})
		target_link_libraries (othint ${EDITLINE_LIBRARY})
	endif (EDITLINE_FOUND)
endif(LOCAL_EDITLINE)
