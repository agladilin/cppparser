

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1z -fvisibility=hidden -fvisibility-inlines-hidden")
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fvisibility=hidden")
else()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -std=c++1z -fvisibility=hidden -fvisibility-inlines-hidden -fprofile-arcs -ftest-coverage --coverage")
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fvisibility=hidden")
endif()

set(CMAKE_CXX_STANDARD 17)

# Define DLLEXPORT and DLLIMPORT
if(WIN32 OR CYGWIN )
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		set(DLLEXPORT "__attribute__((dllexport))")
		set(DLLIMPORT "")
	else()
		set(DLLEXPORT "__declspec(dllexport)")
		set(DLLIMPORT "__declspec(dllimport)")
	endif()
else()
	set(DLLEXPORT "__attribute__((visibility (\"default\")))")
	set(DLLIMPORT "")
endif()

set(export_config_name ${PROJECT_NAME})

if(NOT DEFINED CPPPARSER_INSTALL_INCLUDE_DIR)
  set(CPPPARSER_INSTALL_INCLUDE_DIR include)
endif()

if(NOT DEFINED CPPPARSER_INSTALL_BIN_DIR)
  set(CPPPARSER_INSTALL_BIN_DIR bin)
endif()

if(NOT DEFINED CPPPARSER_INSTALL_LIBRARY_DIR)
  set(CPPPARSER_INSTALL_LIBRARY_DIR lib)
endif()

if(NOT DEFINED CPPPARSER_INSTALL_CONFIG_DIR)
  set(CPPPARSER_INSTALL_CONFIG_DIR ${CPPPARSER_INSTALL_LIBRARY_DIR}/cmake/${export_config_name})
endif()
