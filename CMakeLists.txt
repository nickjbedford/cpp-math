cmake_minimum_required(VERSION 3.15)
project(trace)

set(CMAKE_CXX_STANDARD 20)

add_executable(trace
        main.cpp
        src/vector3.h
        src/include.h)