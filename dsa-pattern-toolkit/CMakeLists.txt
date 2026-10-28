cmake_minimum_required(VERSION 3.16)
project(dsa_pattern_toolkit VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dsa_patterns INTERFACE)
target_include_directories(dsa_patterns INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_executable(dsa_tests tests/test_main.cpp)
target_link_libraries(dsa_tests PRIVATE dsa_patterns)
add_test(NAME dsa_tests COMMAND dsa_tests)

add_executable(prefix_sum_example examples/prefix_sum_example.cpp)
target_link_libraries(prefix_sum_example PRIVATE dsa_patterns)
