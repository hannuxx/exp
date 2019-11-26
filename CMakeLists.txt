cmake_minimum_required(VERSION 3.14)
project(Exp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exp
    SubHandler1.h
    SubHandler2.h
    BaseHandler.h
    main.cpp)
