# At least v3.14 is required to use FetchContent_MakeAvailable
# https://cmake.org/cmake/help/latest/module/FetchContent.html
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(iwahep)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD 14) # May required by GoogleTest>=v1.12.2

# Install GoogleTest with FetchContent provided by CMake>=3.14
# https://google.github.io/googletest/quickstart-cmake.html
# https://github.com/google/googletest/blob/main/googletest/README.md
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# Disable unnecessary caches
# https://qiita.com/shohirose/items/30e39949d8bf990b0462
# https://komorinfo.com/blog/add-gtest-and-gmock-into-your-project/
# set(BUILD_GMOCK CACHE BOOL OFF "" FORCE)
# set(INSTALL_GTEST CACHE BOOL OFF "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows
FetchContent_MakeAvailable(googletest)