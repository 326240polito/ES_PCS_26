cmake_minimum_required(VERSION 3.20)
project(Esercitazione1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_ST ANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall")

add_executable(parametri es1_arg.cpp)
add_executable(calcola_media esercitazione1.cpp)
