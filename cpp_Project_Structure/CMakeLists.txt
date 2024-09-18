cmake_minimum_required(VERSION 3.29)
project(cpp_Project_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_Project_Structure src/main.cpp
        src/math/MathOperations.cpp
        include/math/MathOperations.hpp)
