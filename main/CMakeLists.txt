cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

add_library(myLib STATIC
    myLib.hpp
    myLib.cpp
    )
target_include_directories(myLib PRIVATE .)

add_executable(main
    main.cpp
    data.h
    )

target_include_directories(main PRIVATE 
    .)

target_link_libraries(main
    myLib
    )
