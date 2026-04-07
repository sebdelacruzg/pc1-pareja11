cmake_minimum_required(VERSION 3.20)
project(PC1_Pareja11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sanitizers 
#add_compile_options(-g -fsanitize=address -fsanitize=undefined)
#add_link_options(-fsanitize=address -fsanitize=undefined)

# Encapsulación y módulos
add_library(solution src/solution.cpp)
target_include_directories(solution PUBLIC src)

# CTest
enable_testing()
add_executable(test_solution tests/tests.cpp)
target_link_libraries(test_solution PRIVATE solution)
add_test(NAME test_solution COMMAND test_solution)

#Benchmark
add_executable(benchmark_app bench/benchmark.cpp)
target_link_libraries(benchmark_app PRIVATE solution)