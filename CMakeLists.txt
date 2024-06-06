cmake_minimum_required(VERSION 3.4...3.28)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0048 NEW)

project(cppparser VERSION 0.1.0)

enable_testing()

include("conf.cmake")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd\"4996\"")
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd\"4996\"")
endif()

add_subdirectory(third_party/btyacc_tp)

add_definitions(-DBOOST_AUTO_LINK_NOMANGLE)

#add_subdirectory(../common/third_party/boost_tp/cmake  ${CMAKE_BINARY_DIR}/boost)

#include_directories(../common/third_party)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS filesystem program_options date_time REQUIRED)

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/src/catch/catch.hpp")
  file(DOWNLOAD "https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp" "${CMAKE_SOURCE_DIR}/src/catch/catch.hpp")
endif()

#############################################
## CppParser

find_program(
	FLEX
	"flex"
	# Assuming for Linux and OSX flex is already available
	# Only for Windows the flex will be used from the repository
	PATHS ENV PATH "third_party/flex_tp"
)
if(${FLEX} MATCHES "FLEX-NOTFOUND")
	message(FATAL_ERROR "'flex' not found")
else()
	message(STATUS "Found 'flex' as ${FLEX}")
endif()

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}src/parser.tab.cpp GENERATED)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}src/parser.lex.cpp GENERATED)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}src/parser.tab.h GENERATED)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
	COMMAND $<TARGET_FILE:btyacc> -v -b parser -d ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.y
#	COMMAND ${CMAKE_COMMAND} -E copy y_tab.c ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp
#	COMMAND ${CMAKE_COMMAND} -E copy y_tab.h ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.h
	COMMAND ${CMAKE_COMMAND} -E copy parser.tab.c ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.cpp
	COMMAND ${CMAKE_COMMAND} -E copy parser.tab.h ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.y
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.lex.cpp
	COMMAND ${FLEX} -o${CMAKE_CURRENT_SOURCE_DIR}/src/parser.lex.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.l
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.l ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
)

set(CPPPARSER_SOURCES
	src/cppparser.cpp
	src/cppast.cpp
	src/cppprog.cpp
	src/cppwriter.cpp
	src/cppobjfactory.cpp
	src/lexer-helper.cpp
	src/parser.l
	src/parser.y
	src/parser.lex.cpp
	src/parser.tab.cpp
	src/utils.cpp
)

add_library(cppparser STATIC ${CPPPARSER_SOURCES})
#add_dependencies(cppparser btyacc boost_filesystem boost_program_options)
target_link_libraries(cppparser
	PUBLIC
		${Boost_FILESYSTEM_LIBRARY}
		${Boost_PROGRAM_OPTIONS_LIBRARY}
		${Boost_System}
)
target_include_directories(
	cppparser
	PUBLIC
		${Boost_INCLUDE_DIRS}
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pub>  
		$<INSTALL_INTERFACE:${CPPPARSER_INSTALL_INCLUDE_DIR}>
		#../common/third_party/boost_tp
	PRIVATE
		hack
)
target_compile_definitions(
	cppparser
	PRIVATE
		YY_NO_UNPUT
)

#install(TARGETS cppparser EXPORT cppparser-config)
#export(TARGETS cppparser NAMESPACE cppparser:: FILE "${CMAKE_CURRENT_BINARY_DIR}/cppparser-config.cmake")
#install(DIRECTORY pub/ DESTINATION include/cppparser)
#install(EXPORT cppparser-config DESTINATION cmake)

# Install rule for headers
install(
	DIRECTORY pub/
	DESTINATION ${CPPPARSER_INSTALL_INCLUDE_DIR}
	COMPONENT Development
)

install(
	TARGETS cppparser
	EXPORT ${export_config_name}Targets
	ARCHIVE DESTINATION ${CPPPARSER_INSTALL_LIBRARY_DIR} COMPONENT Development
	LIBRARY DESTINATION ${CPPPARSER_INSTALL_LIBRARY_DIR} COMPONENT RuntimeLibraries
	RUNTIME DESTINATION ${CPPPARSER_INSTALL_BIN_DIR} COMPONENT RuntimeLibraries
)

#------------------------------------------------------------------------------
# Configure <export_config_name>ConfigVersion.cmake common to build and install tree
include(CMakePackageConfigHelpers)
set(config_version_file ${PROJECT_BINARY_DIR}/${export_config_name}ConfigVersion.cmake)
write_basic_package_version_file(
	${config_version_file}
	VERSION "${CPPPARSER_VERSION}"
	COMPATIBILITY ExactVersion
)

#------------------------------------------------------------------------------
# Export '<export_config_name>Targets.cmake' for a build tree
export(
	EXPORT ${PROJECT_NAME}Targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/${export_config_name}Targets.cmake"
)

# Configure '<export_config_name>Config.cmake' for a build tree
set(build_config ${CMAKE_BINARY_DIR}/${export_config_name}Config.cmake)
configure_package_config_file(
	${export_config_name}Config.cmake.in 
	${build_config}
	INSTALL_DESTINATION "${PROJECT_BINARY_DIR}"
)

#------------------------------------------------------------------------------
# Export '<export_config_name>Targets.cmake' for an install tree
install(
	EXPORT ${export_config_name}Targets
	FILE ${export_config_name}Targets.cmake
	DESTINATION ${CPPPARSER_INSTALL_CONFIG_DIR}
)

set(install_config ${PROJECT_BINARY_DIR}/CMakeFiles/${export_config_name}Config.cmake)
configure_package_config_file(
	${export_config_name}Config.cmake.in 
	${install_config}
	INSTALL_DESTINATION ${CPPPARSER_INSTALL_CONFIG_DIR}
)

# Install config files
install(
	FILES ${config_version_file} ${install_config}
	DESTINATION "${CPPPARSER_INSTALL_CONFIG_DIR}"
)


#include(CMakePackageConfigHelpers)
#write_basic_package_version_file(
#	"cppparserConfigVersion.cmake"
#	VERSION ${cppparser_VERSION}
#	COMPATIBILITY AnyNewerVersion)

#install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cppparser-config.cmake" DESTINATION lib/cmake/cppparser)
# "${CMAKE_CURRENT_BINARY_DIR}/cppparserConfigVersion.cmake"

#############################################
## CppParserTest

add_executable(cppparsertest
	test/app/cppparsertest.cpp
)

target_link_libraries(cppparsertest
	PRIVATE
		cppparser
		${Boost_FILESYSTEM_LIBRARY}
		${Boost_PROGRAM_OPTIONS_LIBRARY}
		${Boost_System}
)

set(E2E_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test/e2e)
set(CTEST_OUTPUT_ON_FAILURE 1)
add_test(
	NAME ParserTest
	COMMAND cppparsertest --input-folder=${E2E_TEST_DIR}/test_input
		--output-folder=${E2E_TEST_DIR}/test_output
		--master-files-folder=${E2E_TEST_DIR}/test_master
)

#############################################
## Unit Test

set(TEST_SNIPPET_EMBEDDED_TESTS
	${CMAKE_CURRENT_LIST_DIR}/test/unit/attribute-specifier-sequence.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/disabled-code-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/error-handler-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/expr-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/namespace-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/template-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/uniform-init-test.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/vardecl-test.cpp
)

add_executable(cppparserunittest
	${CMAKE_CURRENT_LIST_DIR}/test/unit/main.cpp
	${CMAKE_CURRENT_LIST_DIR}/test/unit/test-hello-world.cpp

	${TEST_SNIPPET_EMBEDDED_TESTS}
)
target_include_directories(cppparserunittest
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(cppparserunittest
	PRIVATE
		cppparser
		${Boost_FILESYSTEM_LIBRARY}
		${Boost_PROGRAM_OPTIONS_LIBRARY}
		${Boost_System}
)
set(UNIT_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test/unit)
add_test(
	NAME ParserUnitTest
	COMMAND cppparserunittest
)

# cppparserembeddedsnippetvalidity is just to ensure that the embedded
# code snippets used in unit tests are valid C/C++ code.
# So, the goal is to test if the embedded test snippets compile without error.
add_executable(cppparserembeddedsnippetvalidity
	${CMAKE_CURRENT_LIST_DIR}/test/unit/main.cpp

	${TEST_SNIPPET_EMBEDDED_TESTS}
)
target_include_directories(cppparserembeddedsnippetvalidity
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src
)
target_compile_definitions(cppparserembeddedsnippetvalidity
  PRIVATE
		"TEST_CASE_SNIPPET_STARTS_FROM_NEXT_LINE=1"
		"CPPPARSER_TEST_DEFINED_MACRO=1"
)
target_link_libraries(cppparserembeddedsnippetvalidity
	PRIVATE
		cppparser
		${Boost_FILESYSTEM_LIBRARY}
		${Boost_PROGRAM_OPTIONS_LIBRARY}
		${Boost_System}
)

if(NOT MSVC)
	target_compile_options(cppparserembeddedsnippetvalidity
		PRIVATE
			-Wno-unused-variable
			-Wno-attributes
			-Wno-unused-value
			-Wno-uninitialized
			-Wno-unused-but-set-variable
	)
endif()

find_program(
	MARKDOWN_PP
	"markdown-pp"
	PATHS ENV PATH
)

if(NOT ${MARKDOWN_PP} MATCHES "MARKDOWN_PP-NOTFOUND")
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/README.md
		COMMAND ${MARKDOWN_PP} ${CMAKE_CURRENT_SOURCE_DIR}/src/README.mdpp -o ${CMAKE_CURRENT_SOURCE_DIR}/README.md
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/README.mdpp ${RESPATHS} ${EXAMPLE_HEADERS}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	)
	add_custom_target(
		ReadMe ALL
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
else()
  message("Markdown-pp NOT FOUND: README cannot be updated.")
endif()
