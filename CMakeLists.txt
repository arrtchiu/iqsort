cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
project(iqsort)
add_executable(iqsort src/iqsort/main.cpp)

install(TARGETS iqsort DESTINATION bin)
