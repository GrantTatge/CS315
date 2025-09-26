cmake_minimum_required(VERSION 4.0 )
project(Project_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_2 lex.cpp
        main.cpp
        parser.cpp
        reclists.cpp
        solutions.cpp)
