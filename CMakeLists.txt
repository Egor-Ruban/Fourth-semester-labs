# cmake_minimum_required(VERSION <specify CMake version here>)
project(SearchTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchTree main.cpp Node.cpp Node.h Utils.h)