// OTLIB
// Open Transactions Pre-Compiled Headers File

#ifndef BUILDING_PCH_NOW
#pragma once
#endif


#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

// C++ containers
#include <list>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>


#ifdef _WIN32
#include <memory>
#else
#include <tr1/memory>
#endif


// decide should we now include various common libraries now (e.g. for PCH)
#ifdef _WIN32
#ifndef NO_OT_PCH
	#define INCLUDE_COMMON_OT_HEADERS_NOW
#else
#undef NO_OT_PCH
#endif
#endif

#ifdef BUILDING_PCH_NOW
	#define INCLUDE_COMMON_CPP_HEADERS_NOW // very safe 
	#define INCLUDE_COMMON_3RD_PARTY_HEADERS_NOW // quite safe 
	// #define INCLUDE_COMMON_OT_HEADERS_NOW // safe only if not working on too much OT internals
#endif


// execute the inclusions:

// these should be very safe (untill compilator/system upgrade)
#ifdef INCLUDE_COMMON_CPP_HEADERS_NOW
	// C++
	#include <iostream>
	#include <fstream>
	#include <exception>
	#include <stdexcept>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <typeinfo>
	#include <unistd.h>
	// #include <unicode/ucnv.h> //  used by SimpleIni - so we just include SimpleIni below
	// #include <wchar.h> // is done by SimpleIni
	#ifndef _WIN32 // only not windows
			#include <ucontext.h>
	#endif

	// C++ C
	#include <cstdio>
	#include <cstring>	
	#include <cstdlib>
	#include <cctype>
	#include <cassert>
	#include <cerrno>
#endif


// these should be safe, only rebuild PCH (manually if needed) after upgrading versions of this libs:
#ifdef INCLUDE_COMMON_3RD_PARTY_HEADERS_NOW
	// other 3rd party libs we use:
	#include <chaiscript/chaiscript.hpp> // huge one, dependency

	// in-our source tree (but usually not changed)
	#include <include/simpleini/SimpleIni.h>
	#include "irrxml/irrXML.h"
	#include <zmq.hpp>
#endif


// these can be dengerous if we are working on thoes files right now
#ifdef INCLUDE_COMMON_OT_HEADERS_NOW
	#include <OTString.h>
	#include <OTStorage.h>
	#include <OTSmartContract.h>
	#include <OTLog.h>
#endif


#define _TEST_TEST_IGNORE_ME asdfasfdasfs1

