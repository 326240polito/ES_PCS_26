#include <iostream>
#include <vector>
#include <string>
#include "randfiller.h"
#include "sorts.hpp"


template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";  // stampo l'elemento i-esimo
    }
    std::cout << "\n";
}

/*Genero un vettore lungo 1 che mi dice la dimensione casusale*/
int get_random_size(randfiller& rf) {
    std::vector<int> tmp;
    tmp.resize(1);          // creo il vettore di un solo elemento
    rf.fill(tmp, 1, 100);   // riempio quell'unico elemento con un numero tra 1 e 100
    return tmp[0];          // restituisco il numero generato come dimensione
}

int main(void) {
    randfiller rf;   //inizializza il generatore di numeri casuali

    /* Riempo i miei 100 vettori con INTERI */
    for (size_t i=0; i < 100; i++) {
        int dim = get_random_size(rf);   // sceglie una dimensione a caso
        /* Genero il vettore di dimensione "dim" */
        std::vector<int> vi;
        vi.resize(dim);                 // ridimensione il vettore
        rf.fill(vi, -500, 500);         // riempio con valori tra -500 e 500

        bubble_sort(vi);                // chiamo algoritmo di ordinamento
        if (!is_sorted(vi)) {           // mi dice se il vettore è davvero ordinato
            std::cout << "Test Fallito: il vettore numero " << i << " non è ordinato. \n";
            print_vector(vi);           // mostro il vettore sbagliato
            return EXIT_FAILURE;
        }
    }

    /* TEST SU STRINGHE */
    std::vector<std::string> vs = {"albero", "ciao", "mamma e papà" , "michele", "programmazione e calcolo scientifico", "c++"};
    vs.push_back("blackjack");  // aggiunge un elemento alla fine
    bubble_sort(vs);            // ordine le stringe in modo alfabetico
        if (!is_sorted(vs)) {
        std::cout << "Test Fallito: il vettore di stringhe non è ordinato!\n";
        return EXIT_FAILURE;
    }

    std::cout << "Test Completato con successo \n";
    return EXIT_SUCCESS;
}
