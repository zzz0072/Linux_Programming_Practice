cmake_minimum_required(VERSION 2.8)

# Directories
set(SRC_DIR src)
set(LIB_DIR libs)
set(INC_DIR include)

# Project data
project(testcmake)

# Release mode
set(CMAKE_BUILD_TYPE Debug)

# I like verbose, must after project, do not know why
set(CMAKE_VERBOSE_MAKEFILE true)

# Where to include?
include_directories(${INC_DIR})

# Files to compile
set(test_SRCS ${SRC_DIR}/test.c ${LIB_DIR}/liba.c ${LIB_DIR}/libb.c)
add_executable(${PROJECT_NAME} ${test_SRCS})

