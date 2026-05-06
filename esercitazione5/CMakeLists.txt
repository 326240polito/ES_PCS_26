cmake_minimum_required(VERSION 3.20)
project(esercitazione5)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flag di compilazione richiesti
# -Wall: attiva tutti gli avvertimenti
# -Wshadow: avvisa se una variabile locale ne copre un'altra
# -Werror=vla: impedisce l'uso di Variable Length Arrays (non standard in C++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Abilita l'infrastruttura per i test (permette di usare 'make test' o 'ctest')
enable_testing()

# --- ESEGUIBILE PRINCIPALE (BENCHMARK) ---
# Compila il programma per la misurazione dei tempi medi
add_executable(measure_sorts timecounter.cpp measure_sorts.cpp)

# --- TEST UNITARI ---
# Ogni test è un eseguibile separato che deve restituire EXIT_SUCCESS o EXIT_FAILURE

# Test Bubble Sort
add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

# Test Insertion Sort
add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

# Test Selection Sort
add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

# Test Mergesort
add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

# Test Quicksort[cite: 1]
add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

# Test Quicksort Hybrid[cite: 1]
add_executable(test_quicksort_hybrid test_quicksort_hybrid.cpp)
add_test(NAME quicksort_hybrid COMMAND test_quicksort_hybrid)