cmake_minimum_required(VERSION 3.20)

project(argparser LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(out main.cpp)