cmake_minimum_required(VERSION 2.8)
project(cpp_cache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_FLAGS_COVERAGE
        "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
        CACHE STRING "Flags used by the C++ compiler during coverage builds."
        FORCE )
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_COVERAGE)
set(SOURCE_FILES main.cpp LRUCache/LRUCache.h Cache.h LFUCache/LFUCache.h MFUCache/MFUCache.h MRUCache/MRUCache.h)
add_executable(cpp_cache ${SOURCE_FILES})