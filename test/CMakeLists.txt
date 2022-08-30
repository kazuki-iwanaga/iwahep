# To use GTest::gtest_main and gtest_discover_tests
# https://google.github.io/googletest/quickstart-cmake.html
# https://cmake.org/cmake/help/git-stage/module/GoogleTest.html
include(GoogleTest)

# Search test codes like ./test/*_test.cc
# https://cmake.org/cmake/help/latest/command/file.html#glob
file(GLOB LIST_TEST ${PROJECT_SOURCE_DIR}/test/*_test.cc)

# Configure test recursively foreach test codes: *_test.cc
# https://qiita.com/mrk_21/items/082bae48a5ef2ac1564c
# https://cmake.org/cmake/help/latest/command/foreach.html
foreach(PATH_TO_TEST IN LISTS LIST_TEST)
  # Remove file extensions (e.g. foo/bar/sample.cc -> sample)
  # and store in a cmake variable
  # https://cmake.org/cmake/help/latest/command/get_filename_component.html
  # https://qiita.com/mrk_21/items/5e7ca775b463a4141a58
  get_filename_component(TARGET_TESTNAME ${PATH_TO_TEST} NAME_WE)

  add_executable(
    ${TARGET_TESTNAME}
    ${PATH_TO_TEST}
  )
  target_include_directories(
    ${TARGET_TESTNAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
  )
  target_link_libraries(
    ${TARGET_TESTNAME}
    uthic
    GTest::gtest_main
  )

  # Register as a CMake test file
  # https://cmake.org/cmake/help/latest/module/GoogleTest.html#command:gtest_discover_tests
  gtest_discover_tests(${TARGET_TESTNAME})
endforeach()