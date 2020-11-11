cmake_minimum_required(VERSION 3.17)
project(PORR)

set(CMAKE_CXX_STANDARD 20)

#set(Boost_ROOT "C:/boost/boost_1_74_0/boost")
#set(Boost_INCLUDE_DIR "C:/boost/boost_1_74_0")
#set(Boost_LIBRARY_DIR "C:/boost/boost_1_74_0/libs")

#find_package(Boost REQUIRED)

#include_directories("${Boost_INCLUDE_DIR}")

add_executable(PORR Graph.cpp Graph.h main.cpp)