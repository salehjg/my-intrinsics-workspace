cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_definitions(-DLOG=0)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -ffast-math -fno-tree-vectorize -qopt-report -qopenmp") # -mavx2

project(MyIntrinsicsWorkspace C CXX)

find_package(spdlog REQUIRED)
include(FetchContent)
FetchContent_Declare(
        libnpy
        URL https://github.com/llohse/libnpy/archive/refs/tags/v1.0.1.tar.gz
        URL_HASH MD5=0aba07020231be841d5eaa3e092c237b
)
FetchContent_MakeAvailable(libnpy libnpy)
FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

message(STATUS "C compiler used by CMake: ${CMAKE_C_COMPILER}")
message(STATUS "CXX compiler used by CMake: ${CMAKE_CXX_COMPILER}")
#message(STATUS "CUDA compiler used by CMake: ${CMAKE_CUDA_COMPILER}")
message(STATUS "Linker used by CMake: ${CMAKE_LINKER}")

add_subdirectory(src)