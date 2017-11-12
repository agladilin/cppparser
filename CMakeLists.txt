project(cppparser)

cmake_minimum_required(VERSION 3.4)

include("../common/cmake/conf.cmake")

add_subdirectory(third_party/btyacc_tp)

add_definitions(-DBOOST_AUTO_LINK_NOMANGLE)

add_subdirectory(${ROOT_DIR}/common/third_party/boost_tp/cmake  ${CMAKE_OBJFILE_OUTPUT_DIRECTORY}/boost)

#############################################
## CppParser

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/parser.lex.cpp
	COMMAND flex -o${CMAKE_CURRENT_SOURCE_DIR}/parser.lex.cpp ${CMAKE_CURRENT_SOURCE_DIR}/parser.l
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser.l
)
add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.h
	COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/btyacc -d ${CMAKE_CURRENT_SOURCE_DIR}/parser.y
	COMMAND ${CMAKE_COMMAND} -E copy y_tab.c ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp
	COMMAND ${CMAKE_COMMAND} -E copy y_tab.h ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.h
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser.y
)

set_source_files_properties(parser.tab.cpp GENERATED)
set_source_files_properties(parser.lex.cpp GENERATED)
set_source_files_properties(parser.tab.h GENERATED)

set(CPPPARSER_SOURCES
	cppparser.cpp
	cppdom.cpp
	cppprog.cpp
	cppwriter.cpp
	cppobjfactory.cpp
	parser.l
	parser.y
	parser.lex.cpp
	parser.tab.cpp
)

add_library(cppparser STATIC ${CPPPARSER_SOURCES})
add_dependencies(cppparser btyacc boost_filesystem boost_program_options)
target_link_libraries(cppparser
	PUBLIC
		boost_filesystem
		boost_program_options
		boost_system
)
target_include_directories(
	cppparser
	PUBLIC
		pub
		${ROOT_DIR}/common/third_party/boost_tp
	PRIVATE
		hack
)

#############################################
## CppParserTest
file( GLOB CPPPARSERTEST_SOURCES
	cppparsertest/*.cpp
)
add_executable(cppparsertest ${CPPPARSERTEST_SOURCES})
target_link_libraries(cppparsertest
	PRIVATE
		cppparser
		boost_filesystem
		boost_program_options
		boost_system
)
enable_testing()
set(CPPPARSERTEST_DIR ${CMAKE_CURRENT_LIST_DIR}/cppparsertest)
set(CTEST_OUTPUT_ON_FAILURE 1)
add_test(
	NAME ParserTest
	COMMAND cppparsertest --input-folder=${CPPPARSERTEST_DIR}/test_input
		--output-folder=${CPPPARSERTEST_DIR}/test_output
		--master-files-folder=${CPPPARSERTEST_DIR}/test_master
)