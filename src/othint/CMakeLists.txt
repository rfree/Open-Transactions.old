cmake_minimum_required (VERSION 2.6)
project (othint)
file(GLOB othint_SRC
	"*.h"
	"*.hpp"
	"*.cpp"
)
set(CMAKE_PREFIX_PATH "$ENV{HOME}/.local")
include_directories("${CMAKE_PREFIX_PATH}/include/ot/otapi")
include_directories("${CMAKE_PREFIX_PATH}/include/ot/otlib")



option(LOCAL_EDITLINE "Use local Editline library ($HOME/.local)" OFF)
option(WITH_WRAPPER "Build with wrapper" OFF)

if (WITH_WRAPPER)
	set(CMAKE_CXX_COMPILER "$ENV{HOME}/.local/bin/compile-cxx")
	set(CMAKE_CC_COMPILER "$ENV{HOME}/.local/bin/compile-cc")
endif (WITH_WRAPPER)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g3 -O0 ")
SET(CMAKE_EXE_LINKER_FLAGS "-L${CMAKE_PREFIX_PATH}/lib -lotapi -lot") #TODO:  Find a proper way to link ot libraries
#add_library( otapi SHARED IMPORTED )
#set_target_properties( otapi PROPERTIES IMPORTED_LOCATION "${CMAKE_PREFIX_PATH}/lib")
#add_library( ot SHARED IMPORTED )
#set_target_properties( ot PROPERTIES IMPORTED_LOCATION "${CMAKE_PREFIX_PATH}/lib")

add_executable(othint ${othint_SRC})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/") # Add folder with cmake modules

if (LOCAL_EDITLINE)
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

add_custom_target(run
    COMMAND echo "" && ./othint --complete-shell
    DEPENDS othint
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
