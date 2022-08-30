# Search test codes like ./src/*.cc
# https://cmake.org/cmake/help/latest/command/file.html#glob
file(GLOB LIST_SRC ${PROJECT_SOURCE_DIR}/src/*.cc)

add_library(
  uthic
  ${LIST_SRC}
)
target_include_directories(
  uthic
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)