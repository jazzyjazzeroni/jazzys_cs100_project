cmake_minimum_required(VERSION 3.2)
project(unit-test-exercise)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
  ${CMAKE_SOURCE_DIR}/Character_header
  ${CMAKE_SOURCE_DIR}/addit_header
)

add_subdirectory(lib)
add_subdirectory(test)

file(GLOB CHARACTER_HEADERS ${CMAKE_SOURCE_DIR}/Character_header/*.h)
add_library(CharacterLib ${CHARACTER_HEADERS})

file(GLOB ADDIT_HEADERS ${CMAKE_SOURCE_DIR}/addit_header/*.h)
add_library(AdditLib ${ADDIT_HEADERS})

add_executable(main_app main.cpp)
target_link_libraries(main_app CharacterLib AdditLib