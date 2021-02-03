set(TESTS
  GraphColoring.cpp
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${TEST_SUITE} ${TESTS})

enable_testing()

target_include_directories(${TEST_SUITE}
  PUBLIC ${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${TEST_SUITE} PUBLIC gtest)
