cmake_minimum_required(VERSION 3.18.2)
project(graph-tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp Bipartite-test.cpp)

add_subdirectory(../extern/googletest)

target_include_directories(${PROJECT_NAME}
  PUBLIC extern/googletest/googletest/include
)

target_link_libraries(${PROJECT_NAME} gtest)
