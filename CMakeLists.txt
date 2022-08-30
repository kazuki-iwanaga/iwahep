# At least v3.11 is required to use FetchContent
# https://cmake.org/cmake/help/latest/module/FetchContent.html
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(iwahep CXX)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD 14) # May required by GoogleTest>=v1.12.2

# Install GoogleTest with FetchContent provided by CMake>=3.11
# https://google.github.io/googletest/quickstart-cmake.html
# https://github.com/google/googletest/blob/main/googletest/README.md
# https://qiita.com/shohirose/items/d2b9c595a37b27ece607
# Be careful that GoogleTest>1.8 requires gcc>=5 (c++11)
set(GOOGLE_TEST_VERSION 1.12.1)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-${GOOGLE_TEST_VERSION}
)
# Disable unnecessary caches
# https://qiita.com/shohirose/items/30e39949d8bf990b0462
# https://komorinfo.com/blog/add-gtest-and-gmock-into-your-project/
# set(BUILD_GMOCK CACHE BOOL OFF "" FORCE)
# set(INSTALL_GTEST CACHE BOOL OFF "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows
# FetchContent_MakeAvailable(googletest) # This command requires CMake>=3.14
# Altanative commands for FetchContent_MakeAvailable
# https://runebook.dev/ja/docs/cmake/module/fetchcontent
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()