cmake_minimum_required(VERSION 3.12)

set(This UnitTestsIZ1)

set(Sources
        unit_tests.cpp
)

set(Headers

)

add_executable(${This} ${Sources} ${Headers})

target_link_libraries(${This} PUBLIC
        gtest_main
        roman_numerals
)

add_test(
        NAME ${This}
        COMMAND ${This}
)
