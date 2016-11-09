# CMake file to allow testing on MS-Visual C++, also works on Mac-OX, Linux
cmake_minimum_required(VERSION 2.8.4)
project(re2c)

include(CheckIncludeFile)
check_include_file("stdint.h" HAVE_STDINT_H)
configure_file(
	"${PROJECT_SOURCE_DIR}/CMakeConfig.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)
include_directories(
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/bootstrap"
)
file(GLOB_RECURSE SOURCES 
	src/codegen/*.cc
	src/codegen/*.h
	src/conf/*.cc
	src/conf/*.h
	src/ir/*.cc
	src/ir/*.h
	src/parse/*.cc
	src/parse/*.h
	src/util/*.cc
	src/util/*.h
	src/bootstrap/src/*.cc
	src/bootstrap/src/*.h
	bootstrap/src/*.cc
	bootstrap/src/*.h

	src/test/range/*.h
)
add_executable(re2c 
    src/main.cc
    src/globals.h
	${SOURCES}
)

# tests
enable_testing()
if(NOT RE2C_DISABLE_TESTS)
add_executable( range_test
	src/test/range/test.cc
	src/util/range.cc
)
add_test( range_test range_test )

add_executable( s_to_n32_unsafe_test	
	src/test/s_to_n32_unsafe/test.cc 
	src/util/s_to_n32_unsafe.cc
)
add_test( s_to_n32_unsafe_test s_to_n32_unsafe_test )

configure_file(
	"${PROJECT_SOURCE_DIR}/CMakeRunTests.pl.in"
	"${PROJECT_BINARY_DIR}/CMakeRunTests.pl"
)
add_test(
	NAME 	CMakeRunTests 
	COMMAND	perl CMakeRunTests.pl $<TARGET_FILE:re2c>
)
endif(NOT RE2C_DISABLE_TESTS)

