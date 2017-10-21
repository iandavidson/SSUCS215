cmake_minimum_required(VERSION 3.6)
project(davidsonL07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Lab07b.cpp
    WordData.cpp
    WordData.h)

add_executable(davidsonL07 ${SOURCE_FILES})