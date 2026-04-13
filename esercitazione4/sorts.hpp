#pragma once
#include <iostream>
#include <algorithm>
#include <vector> 
#include <optional> 

using namespace std;
// L'idea è far "risalire" l'elemento più piccolo verso l'inizio a ogni ciclo
template<typename T> 
void bubble_sort(vector<T>& vec) {
    //Se il vettore ha 0 o 1 elemento è già ordinato
    if (vec.size() <= 1) return; 

    int N=size(vec);
    // Garantisco che l'i-esimo elemento sia al posto giusto
    for (int i=0; i<= N-2; i++) {
        // Confronto coppie adiacenti di elementi partendo dal fondo
        for (int j=N-1; j>=i+1; j--) { 
            // Se l'elemento a dx è minore di quello a sx, li scambia
            if (vec.at(j) < vec.at(j-1)) {
                swap(vec.at(j),vec.at(j-1));
            }
        }
    }
}
// Cerca il minimo nel resto del vettore e lo scambia con la posizione corrente
template<typename T>
void selection_sort(vector<T>& vec) {
    
    if (vec.size() <= 1) return; 

    int N=size(vec);
    // Scorre tutto il vettore tranne l'ultimo elemento
    for (int i=0; i <= N-2; i++) {
        int min_index=i; // considero che il minimo sia l'elemento i
        // Cerco l'effettivo minimo
        for (int j=i+1; j<=N-1; j++) { 
            if (vec.at(j) < vec.at(min_index)) {
                min_index=j;  // Aggiorno il minimo trovato
            }
        }
        if (min_index != i) {  // Se il minimo di partenza non è quello trovato esegue lo scambio
            swap(vec.at(i),vec.at(min_index));
        }
    }
}
// Inserisce un elemento nella parte già ordinata
template<typename T>
void insertion_sort(vector<T>& vec) {

    if (vec.size() <= 1) return; 

    int N=size(vec);
    for (int i=1; i<= N-1; i++) {
        T value = vec.at(i);  // Valore da inserire correttamente
        int j = i-1;          // Indice dell'elemento precedente
        // Sposta a destra gli elementi maggiori del "value" corrente
        while (j >= 0 && vec.at(j) > value ) { 
            vec.at(j+1) = vec.at(j);
            j--;
        }
    // Inserisce il valore nella sua posizione corretta
    vec.at(j+1) = value;
    }
}
// Verifico ordinamento
// Restituisce true se il vettore è ordinato in modo crescente
template<typename T>
bool is_sorted(const vector<T>& vec) {
    if (size(vec) <= 1) return true; 

    int N=size(vec);
    /* Caso generale*/
    for (int i=0; i < N-1; i++) {
        // Se trova un elemento maggiore del successivo, il vettore non è ordinato
        if (vec.at(i) > vec.at(i+1)) {
            return false;
        }   
    }
    return true;
}