cmake_minimum_required(VERSION 3.12)
project(IZ1 C CXX)

set(CMAKE_CXX_STANDARD 17)

set(This roman_numerals)

include_directories(.)

set(Headers
        roman_numerals.h
)

set(Sources
        roman_numerals.c
)

add_library(${This} STATIC ${Sources} ${Headers})

enable_testing()
add_subdirectory(test)
