cmake_minimum_required(VERSION 3.19)
project(mojoAL)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/SDL2)

add_compile_definitions(AL_LIBTYPE_STATIC)
add_library(mojoAL STATIC ${CMAKE_SOURCE_DIR}/lib/mojoAL/mojoal.c)
target_include_directories(mojoAL PRIVATE ${CMAKE_SOURCE_DIR}/lib/SDL2/include)
target_link_libraries(mojoAL SDL2-static)
