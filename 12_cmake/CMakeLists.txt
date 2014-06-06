cmake_minimum_required(VERSION 2.8)
# Project data
project(testcmake)

# Pack to deb
set(CPACK_DEB_COMPONENT_INSTALL 1)

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

# --------------------------------------
# Build and install
# --------------------------------------
# Build library in libs directory or not?
# Default is yes. Use cmake ../ -DBUILD_LIB_TOP=y to test it
if(NOT DEFINED BUILD_LIB_TOP)
    # Dive into libs directory
    add_subdirectory(${SRC_DIR})
    add_subdirectory(${LIB_DIR})
    add_subdirectory(${INC_DIR})
else()
    # Build binary
    set(test_SRCS ${SRC_DIR}/test.c)
    add_executable(${PROJECT_NAME} ${test_SRCS})
    target_link_libraries(${PROJECT_NAME} a b)

    # Build library
    set(liba_SRCS ${LIB_DIR}/liba.c)
    set(libb_SRCS ${LIB_DIR}/libb.c)

    add_library(a SHARED ${liba_SRCS})
    add_library(b SHARED ${libb_SRCS})

    # Installation
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
    install(TARGETS a b LIBRARY DESTINATION lib)
endif()


# --------------------------------------
# Pack
# --------------------------------------
set(CPACK_GENERATOR "TGZ" )
# Setup package version
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 1)
set(CPACK_PACKAGE_VERSION_PATCH 0)

include(CPack)


