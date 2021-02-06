cmake_minimum_required(VERSION 3.18.2)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_NAME Engine)

set(SOURCES
  src/Graph.cpp
  src/GraphColoring.cpp
)

add_library(${LIBRARY_NAME} OBJECT ${SOURCES})
target_include_directories(${LIBRARY_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}
)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
  PRIVATE ${LIBRARY_NAME}
)


# enable testing
enable_testing()
