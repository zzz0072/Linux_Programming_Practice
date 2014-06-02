cmake_minimum_required(VERSION 2.8)
# Project data
project(testcmake)

# Directories
set(SRC_DIR src)
set(LIB_DIR libs)
set(INC_DIR include)

# Release mode
set(CMAKE_BUILD_TYPE Debug)

# Compile flags
set(CMAKE_C_FLAGS "-Wall -Werror")

# I like verbose, must after project, do not know why
set(CMAKE_VERBOSE_MAKEFILE true)

# Where to include?
include_directories(${INC_DIR})

# Dive into libs directory
add_subdirectory(${LIB_DIR})

# Build binary
set(test_SRCS ${SRC_DIR}/test.c)
add_executable(${PROJECT_NAME} ${test_SRCS})
target_link_libraries(${PROJECT_NAME} ${LIB_DIR})
