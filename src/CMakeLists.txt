# Let users choose a kind of library to build.
# https://qiita.com/shohirose/items/5b406f060cd5557814e9
option(UTHIC_BUILD_SHARED_LIBS "Build uthic as a shared library" ON)

# Search test codes like ./src/*.cc
# https://cmake.org/cmake/help/latest/command/file.html#glob
file(GLOB LIST_SRC ${PROJECT_SOURCE_DIR}/src/*.cc)

if (UTHIC_BUILD_SHARED_LIBS)
  # Wether build UTHIC as a shared library or static library
  # https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
  add_library(
    uthic
    SHARED
    ${LIST_SRC}
  )
else()
  add_library(
    uthic
    STATIC
    ${LIST_SRC}
  )
endif()
target_include_directories(
  uthic
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)