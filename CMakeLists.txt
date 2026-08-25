cmake_minimum_required(VERSION 3.16)

project(cpu_cache_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cache-sim
    src/main.cpp
    src/cache.cpp
)

target_include_directories(cache-sim PRIVATE include)