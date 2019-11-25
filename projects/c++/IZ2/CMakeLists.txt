cmake_minimum_required(VERSION 3.14)
project(IZ2)

set(CMAKE_CXX_STANDARD 17)

add_executable(IZ2 main.c matrix.c matrix.h err.h)