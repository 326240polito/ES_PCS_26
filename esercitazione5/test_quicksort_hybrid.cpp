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

/*Genero un vettore lungo 1 che mi dice la dimensione casuale*/
std::vector<int> random_number(randfiller& rf) {
    std::vector<int> dim_vec;
    dim_vec.resize(1); 
    rf.fill(dim_vec, 0, 1000); 
    return dim_vec;
}

int main(void) {
    randfiller rf; 

    /* Riempo i miei 100 vettori con FLOAT */
    for (size_t i=0; i < 100; i++) {
        std::vector<int> dim_vec = random_number(rf);
        /* Genero il vettore di dimensione "dim" */
        std::vector<float> vf;
        vf.resize(dim_vec.at(0)); 
        rf.fill(vf, -500.5f, 500.5f);   
        
        if (vf.size() > 0) {
            quicksort_hybrid(vf, 0, vf.size()-1);
        }
        if (!is_sorted(vf)) {
            std::cerr << "Test Failed: the vector number " << i << " is not sorted! \n";
            print_vector(vf);
            return EXIT_FAILURE;
        }
    }
    
    /* TEST SU STRINGHE */
    std::vector<string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    vs.push_back("blackjack");
    quicksort_hybrid(vs, 0, vs.size()-1);
        if (!is_sorted(vs)) {
        std::cerr << "Test Failed: the String vector is not sorted! \n";
        return EXIT_FAILURE;
    }

    std::cout << "Test Successful \n";
    return EXIT_SUCCESS;
}
