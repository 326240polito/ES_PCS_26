#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "randfiller.h"
#include "sorts.hpp"

int main() {
    randfiller rf;
    
    // 1. Test su 100 vettori casuali con double
    for (int i = 0; i < 100; ++i) {
        int size = rand() % 100 + 1; // Dimensione tra 1 e 100
        std::vector<double> v(size);
        rf.fill(v, -1000.0, 1000.0); // Include numeri negativi
        
        // Chiamata protetta per evitare underflow su size_t
        if (!v.empty()){
            quicksort(v, 0, v.size() - 1);
        }
        
        if (!is_sorted(v)) {
            std::cerr << "Test Fallito: Quicksort standard non ha ordinato correttamente il vettore n. " << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    // 2. Test specifico per Quicksort Hybrid (soglia 15)
    std::vector<int> vh(50);
    rf.fill(vh, 0, 100);
    if (!vh.empty()) {
        quicksort_hybrid(vh, 0, vh.size() - 1, 15);
    }
    
    if (!is_sorted(vh)) {
        std::cerr << "Test Fallito: Quicksort Hybrid non ha ordinato correttamente." << std::endl;
        return EXIT_FAILURE;
    }

    // 3. Test su un vettore di stringhe
    std::vector<std::string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    if (!vs.empty()) {
        quicksort(vs, 0, vs.size() - 1);
    }
    
    if (!is_sorted(vs)) {
        std::cerr << "Test Fallito: Quicksort non ha ordinato correttamente le stringhe." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Quicksort: Tutti i test unitari completati con successo!" << std::endl;
    return EXIT_SUCCESS;
}