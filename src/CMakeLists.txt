set(SOURCE 
  Graph.cpp 
  GraphColoring.cpp 
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${SOURCE_SUITE} ${SOURCE})

target_include_directories(${SOURCE_SUITE} 
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

