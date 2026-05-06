#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sorts.hpp"


template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

/*Genero un vettore lungo 1 che mi dice la dimensione casusale*/
int get_random_size(randfiller& rf) {
    std::vector<int> tmp;
    tmp.resize(1); 
    rf.fill(tmp, 1, 100); 
    return tmp[0];
}

int main(void) {
    randfiller rf; 

    /* Riempo i miei 100 vettori con DOUBLE */
    for (size_t i=0; i < 100; i++) {
        int dim = get_random_size(rf);
        /* Genero il vettore di dimensione "dim" */
        std::vector<double> vd;
        vd.resize(dim);
        rf.fill(vd, -500.5, 500.5);   
        selection_sort(vd);
        if (!is_sorted(vd)) {
            std::cout << "Test Fallito: il vettore numero " << i << " non è ordinato. \n";
            print_vector(vd);
            return EXIT_FAILURE;
        }
    }

    /* TEST SU STRINGHE */
    std::vector<string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    vs.push_back("blackjack");
    selection_sort(vs);
        if (!is_sorted(vs)) {
        std::cout << "Test Fallito: il vettore di stringhe non è ordinato! \n";
        return EXIT_FAILURE;
    }

    std::cout << "Test Completato con Successo \n";
    return EXIT_SUCCESS;
}