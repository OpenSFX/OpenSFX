cmake_minimum_required(VERSION 3.19)
project(OpenSFX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC_MAIN
    SFXDevice.cpp SFXDevice.h
    SFXBuffer.cpp SFXBuffer.h
    SFXSource.cpp SFXSource.h
    io/SFXHandle.cpp io/SFXHandle.h
    io/SFXHandleMP3.cpp io/SFXHandleMP3.h

    OpenSFX.cpp ${CMAKE_SOURCE_DIR}/include/OpenSFX.h
)

add_library(OpenSFX STATIC ${SRC_MAIN})
add_dependencies(OpenSFX mojoAL)
target_link_libraries(OpenSFX mojoAL)

set(OpenSFX_PRIVATE_INCLUDES
    ${CMAKE_SOURCE_DIR}/lib/mojoAL
    ${CMAKE_SOURCE_DIR}/lib/MP3Detect
    ${CMAKE_SOURCE_DIR}/lib/minimp3
)

target_include_directories(OpenSFX PRIVATE ${OpenSFX_PRIVATE_INCLUDES})
