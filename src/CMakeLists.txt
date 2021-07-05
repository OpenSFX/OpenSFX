cmake_minimum_required(VERSION 3.19)
project(OpenSFX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC_MAIN
    OpenSFX.cpp ${CMAKE_SOURCE_DIR}/include/OpenSFX.h
)

add_library(OpenSFX ${SRC_MAIN})
