cmake_minimum_required(VERSION 3.6)
project(Lab04)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    davidsonL04.h
    davidsonL04app.cpp)

add_executable(Lab04 ${SOURCE_FILES})