cmake_minimum_required(VERSION 4.3)
project(labsAlgo)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lab2
        lab2/main.cpp
        lab2/Train.cpp
        lab2/Train.h
)

add_executable(
        lab3
        lab3/main.cpp
        lab3/Soft.cpp
        lab3/Soft.h
)

add_executable(
        lab4
        lab4/main.cpp
        lab4/StudentGroup.cpp
        lab4/StudentGroup.h
)

add_executable(
        lab5
        lab5/main.cpp
        lab5/Date.cpp
        lab5/Date.h
)

add_executable(
        lab7
        lab7/main.cpp
        lab7/Champion.cpp
        lab7/Champion.h
)

add_executable(
        lab8
        lab8/main.cpp
        lab8/Array.h
        lab8/Shape.h
)