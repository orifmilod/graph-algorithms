cmake_minimum_required(VERSION 3.18.2)
project(GraphAlgorithms)

add_executable(${PROJECT_NAME} main.cpp)

# enable testing
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# adding subdirs 
add_subdirectory(extern/googletest)
add_subdirectory(tests)
add_subdirectory(src)

include_directories(src)

target_include_directories(${PROJECT_NAME}
  PUBLIC extern/googletest/googletest/include
  PUBLIC extern/googletest/googlemock/include
)

