cmake_minimum_required(VERSION 3.6)
project(Lab10_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CoordPt.cpp
    CoordPt.h
    FB-Test.cpp
    LList.hpp)

add_executable(Lab10_2 ${SOURCE_FILES})