cmake_minimum_required(VERSION 3.18.2)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

# enable testing
enable_testing()

set(TEST_SUITE ${PROJECT_NAME}_test_suite)

# adding subdirs 
add_subdirectory(extern/googletest)
add_subdirectory(tests)
add_subdirectory(src)

target_include_directories(${PROJECT_NAME}
  PUBLIC extern/googletest/googletest/include
  PUBLIC extern/googletest/googlemock/include
)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE gtest
)
