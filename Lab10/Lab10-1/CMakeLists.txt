cmake_minimum_required(VERSION 3.6)
project(Lab10_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Lab10app.cpp
    LList.cpp
    LList.h
    makefile
    test.input)

add_executable(Lab10_1 ${SOURCE_FILES})