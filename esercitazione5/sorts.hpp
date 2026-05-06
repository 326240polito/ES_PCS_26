#pragma once
#include <iostream>
#include <algorithm>
#include <vector> 
#include <optional>
#include <cmath>
#include <limits>

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

template<typename T>
void merge(std::vector<T>& vec, size_t p, size_t q, size_t r) {
    // Calcola le dimensioni dei due sottovettori ausiliari
    size_t n1 = q - p + 1;
    size_t n2 = r - q;

    // Crea i vettori senza lo spazio extra per la sentinella
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    // Copia i dati dal vettore originale ai vettori temporanei L e R
    for (size_t i = 0; i < n1; i++)
        L[i] = vec[p + i];
    for (size_t j = 0; j < n2; j++)
        R[j] = vec[q + 1 + j];

    size_t i = 0, j = 0, k = p;

    // Confronta gli elementi di L e R e li ricolloca in vec in ordine crescente
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia gli eventuali elementi rimanenti di L
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    // Copia gli eventuali elementi rimanenti di R
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void mergesort(vector<T>& vec, size_t p, size_t r) {
    if (p < r) {
        // Calcolo sicuro del punto medio per evitare overflow di interi
        size_t q = p + (r - p) / 2; 
        mergesort(vec, p, q);
        mergesort(vec, q + 1, r);
        // Fusione dei risultati ordinati
        merge(vec, p, q, r);
    }
}
// Usa l'ultimo elemento come pivot e organizza gli elementi minori a sinistra.
template<typename T>
size_t partition(vector<T>& vec, int p, int r) {
    T x = vec[r]; // Scelta dell'ultimo elemento come pivot
    int i = p - 1; // Indice dell'ultimo elemento minore del pivot
    for (int j = p; j <= r - 1; j++) {
        if (vec[j] <= x) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    // Posiziona il pivot nella sua collocazione finale ordinata
    swap(vec[i + 1], vec[r]);
    return i + 1; // Ritorna l'indice del pivot
}

template<typename T>
void quicksort(vector<T>& vec, int p, int r) {
    if (p < r) {
        // Divide il vettore attorno al pivot
        int q = partition(vec, p, r);
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}
// Utilizza Insertion Sort per piccoli sotto-vettori per ridurre l'overhead della ricorsione.
template<typename T>
void quicksort_hybrid(vector<T>& vec, int p, int r, int threshold = 15) {
    if (p < r) {
        // Se la dimensione dell'intervallo è sotto la soglia, cambia algoritmo
        if ((r - p) < threshold) {
            // Algoritmo Insertion Sort applicato localmente al range [p, r]
            for (int i = p + 1; i <= r; i++) {
                T value = vec.at(i);
                int j = i - 1;
                // Sposta gli elementi maggiori di 'value' una posizione avanti
                while (j >= p && vec.at(j) > value) {
                    vec.at(j + 1) = vec.at(j);
                    j--;
                }
                vec.at(j + 1) = value;
            }
        } else {
            // Se sopra soglia, prosegue con la logica standard del Quicksort
            int q = partition(vec, p, r);
            quicksort_hybrid(vec, p, q - 1, threshold);
            quicksort_hybrid(vec, q + 1, r, threshold);
        }
    }
}