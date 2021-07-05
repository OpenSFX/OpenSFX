cmake_minimum_required(VERSION 3.19)
project(OpenSFXExample)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(OpenSFXExample main.cpp)
target_link_libraries(OpenSFXExample OpenSFX)
