# At least v3.14 is required to use FetchContent_MakeAvailable
# https://cmake.org/cmake/help/latest/module/FetchContent.html
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(iwahep CXX)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD 14) # May required by GoogleTest>=v1.12.2

# Install GoogleTest with FetchContent provided by CMake>=3.14
set(GOOGLE_TEST_VERSION 1.12.1)
include(cmake/GoogleTest.cmake)