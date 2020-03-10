# cmake_minimum_required(VERSION <specify CMake version here>)
project(BigInteger)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigInteger main.cpp BigInteger.cpp BigInteger.h)