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

    /* Riempo i miei 100 vettori con FLOAT */
    for (size_t i = 0; i < 100; i++) {
        int dim = get_random_size(rf);
        /* Genero il vettore di dimensione "dim" */
        std::vector<float> vf;
        vf.resize(dim);
        rf.fill(vf, -500.5f, 500.5f);   
        insertion_sort(vf);
        if (!is_sorted(vf)) {
            std::cout << "Test Fallito: il vettore numero " << i << " non è ordinato. \n";
            print_vector(vf);
            return EXIT_FAILURE;
        }
    }
    
    /* TEST SU STRINGHE */
    std::vector<string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    vs.push_back("blackjack");
    insertion_sort(vs);
        if (!is_sorted(vs)) {
        std::cout << "Test Fallito: il vettore di stringhe non è ordinato! \n";
        return EXIT_FAILURE;
    }

    std::cout << "Test Completato con successo \n";
    return EXIT_SUCCESS;
}