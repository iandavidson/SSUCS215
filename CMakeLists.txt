cmake_minimum_required(VERSION 3.6)
project(cs215f16)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Lab07/CoordPt.cpp
    Lab07/CoordPt.h
    Lab07/Lab07a.cpp)

add_executable(cs215f16 ${SOURCE_FILES})