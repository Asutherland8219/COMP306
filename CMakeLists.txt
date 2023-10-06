cmake_minimum_required(VERSION 3.26)
project(COMP306)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Assignment1)
include_directories(Assignment2)
include_directories(Assignment3)

add_executable(COMP306
        Assignment1/Assignment1Question1.cpp
        Assignment1/Assignment1Question2.cpp
        Assignment1/Assignment1Question3.cpp
        Assignment1/Assignment1Question4.cpp
        Assignment1/Assignment1Question5.cpp
        Assignment1/main.cpp
        Assignment1/unitConversion.cpp
        Assignment1/unitConversionHeader.h
        Assignment2/Assignment2Question1.cpp
        Assignment2/Assignment2Question2.cpp
        Assignment2/Assignment2Question3.cpp
        Assignment2/Assignment2Question4.cpp
        Assignment2/Assignment2Question5.cpp
        Assignment2/main.cpp
        Assignment3/main.cpp
        Assignment3/Problem1.cpp)
