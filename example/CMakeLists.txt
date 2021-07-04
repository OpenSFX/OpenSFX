cmake_minimum_required(VERSION 3.19)
project(AudioLibExample)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(AudioLibExample main.cpp)
target_link_libraries(AudioLibExample AudioLib)