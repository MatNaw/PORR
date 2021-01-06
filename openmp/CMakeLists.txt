cmake_minimum_required(VERSION 3.17)
project(PORR)

set(CMAKE_CXX_STANDARD 20)

add_executable(PORR Graph.cpp Graph.h main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(PORR PUBLIC OpenMP::OpenMP_CXX)
endif()

