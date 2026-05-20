cmake_minimum_required(VERSION 3.10)
project(Esercitazione9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Se l'utente non specifica una modalità quando compila, 
# forziamo CMake a usare la modalità "Release" (ottimizzata).
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Scegli il tipo di build: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()
add_executable(esercitazione9 main.cpp)
