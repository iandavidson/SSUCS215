cmake_minimum_required(VERSION 3.6)
project(Lab11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    davidsonL11.hpp
    davidsonL11app.cpp
    Fraction.cpp
    Fraction.h
    Lab11app.cpp
    LList2.hpp)

add_executable(Lab11 ${SOURCE_FILES})