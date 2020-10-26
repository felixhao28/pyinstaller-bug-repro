set(CMAKE_VERBOSE_MAKEFILE ON)

# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0063 NEW)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "Minimum OS X deployment version")

# Project's name

project(test)

# 使用变量设置编译标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

message("CMAKE_CXX_COMPILER_ID=" ${CMAKE_CXX_COMPILER_ID})
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    # set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-export_dynamic")
else()
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -rdynamic")
endif()

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(Boost_USE_STATIC_LIBS ON)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/../../downloads/boost_1_71_0")

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../../downloads/boost_1_71_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../../downloads/boost_1_71_0/stage/lib")

find_package(Boost 1.71 COMPONENTS thread filesystem REQUIRED)

file(GLOB tfnative_SRC
    "*.h"
    "*.cpp"
    "*.hpp"
)

add_executable(tfnative ${tfnative_SRC})
target_link_libraries(tfnative stdc++)
target_link_libraries(tfnative Boost::thread)
target_link_libraries(tfnative Boost::filesystem)
if (UNIX AND NOT APPLE)
    target_link_libraries(tfnative -static-libgcc -static-libstdc++)
endif()
