cmake_minimum_required(VERSION 3.12)

project(YourProjectName)

# Enable testing
enable_testing()

# Add other configurations as needed
add_subdirectory(googletest)

# Include the necessary directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define the test executable
add_executable(Tests Base/TestFull.cpp)

# Link with Google Test
target_link_libraries(Tests gtest gtest_main)

# Add all cpp files in the src folder to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# Add all header files in the include folder to the HEADERS variable
file(GLOB HEADERS include/*.h)
