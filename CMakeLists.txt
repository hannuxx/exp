cmake_minimum_required(VERSION 3.14)
project(Exp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exp
    OutsideHandler.h
    DerivedHandler.h
    BaseHandler.h
    main.cpp)
