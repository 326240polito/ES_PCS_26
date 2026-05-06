#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "randfiller.h"
#include "sorts.hpp"

int main() {
    randfiller rf;
    
    // 1. Test su 100 vettori di dimensioni casuali con interi
    for (int i = 0; i < 100; ++i) {
        int size = rand() % 100 + 1;
        std::vector<int> v(size);
        rf.fill(v, -500, 500); // Numeri casuali anche negativi
        
        if (!v.empty()) {
            mergesort(v, 0, v.size() - 1);
        }
        
        if (!is_sorted(v)) {
            std::cerr << "Test Fallito: Mergesort non ha ordinato correttamente il vettore intero n. " << i << std::endl;
            return EXIT_FAILURE;
        }
    }

    // 2. Test su un vettore di stringhe
    std::vector<std::string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    if (!vs.empty()) {
        mergesort(vs, 0, vs.size() - 1);
    }
    
    if (!is_sorted(vs)) {
        std::cerr << "Test Fallito: Mergesort non ha ordinato correttamente le stringhe." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Mergesort: Tutti i test unitari completati con successo!" << std::endl;
    return EXIT_SUCCESS;
}