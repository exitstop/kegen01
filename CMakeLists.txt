cmake_minimum_required (VERSION 3.9.0)

option(TEST "Testing off default" OFF) 

set(This Example)
project(${This} CXX)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (Threads)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory(main)

#if(TEST)
#    enable_testing()
#    add_subdirectory(googletest)
#endif()
