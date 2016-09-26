cmake_minimum_required(VERSION 2.8)
project(cpp_cache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

set(SOURCE_FILES main.cpp LRUCache.h)
add_executable(cpp_cache ${SOURCE_FILES})