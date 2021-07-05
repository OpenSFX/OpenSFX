cmake_minimum_required(VERSION 3.19)
project(OpenSFX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC_MAIN
    SFXDevice.cpp SFXDevice.h
    SFXBuffer.cpp SFXBuffer.h
    SFXSource.cpp SFXSource.h

    OpenSFX.cpp ${CMAKE_SOURCE_DIR}/include/OpenSFX.h
)

add_library(OpenSFX STATIC ${SRC_MAIN})
add_dependencies(OpenSFX mojoAL)
target_link_libraries(OpenSFX mojoAL)
target_include_directories(OpenSFX PRIVATE ${CMAKE_SOURCE_DIR}/lib/mojoAL)
