cmake_minimum_required(VERSION 3.2)
project(unit-test-exercise)
# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
# C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
add_subdirectory(googletest)
# Link directories
link_directories(${LIBRARY_OUTPUT_PATH})
# Test executables for character_tests
add_executable(character_tests
  Character_tests/Character_tests.cpp
  Character_tests/Mainchartests.cpp
  Character_tests/Goblintests.cpp
)
target_link_libraries(character_tests gtest gmock gtest_main)
