# Find OT lib and include directories
message(STATUS "Looking for OT locally.")
find_path(OT_INCLUDE_DIR
	NAMES OTAPI.h
	PATHS "$ENV{HOME}/.local/include/ot/otapi"
	)

find_library(OT_LIBRARY
	NAMES otapi
	PATHS "$ENV{HOME}/.local/lib"
	)

if (OT_LIBRARY AND OT_INCLUDE_DIR )
	set(OT_LIBRARIES ${OT_LIBRARY})
	set(OT_FOUND "YES")
else ()
	set(OT_FOUND "NO")
endif ()

if (OT_FOUND)
	if (NOT OT_FIND_QUIETLY)
		message(STATUS "OT include directory: ${OT_INCLUDE_DIR}")
		message(STATUS "OT libraries found: ${OT_LIBRARIES}")
	endif ()
else ()
	if (OT_FIND_REQUIRED)
		message(FATAL_ERROR "Could not find required OT libraries")
	endif ()
endif ()

mark_as_advanced(
	OT_INCLUDE_DIR
	OT_LIBRARY
	)
