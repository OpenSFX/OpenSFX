cmake_minimum_required(VERSION 3.19)
project(AudioLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC_MAIN
    AudioLib.cpp ${CMAKE_SOURCE_DIR}/include/AudioLib.h
)

add_library(AudioLib ${SRC_MAIN})
