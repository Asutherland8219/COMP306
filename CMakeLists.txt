cmake_minimum_required(VERSION 3.12)

project(YourProjectName)

# Enable testing
enable_testing()

# Add the directory containing your tests
add_subdirectory(Assignment4/Tests)

# Add all cpp files in the src folder to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# Add all header files in the include folder to the HEADERS variable
file(GLOB HEADERS include/*.h)
