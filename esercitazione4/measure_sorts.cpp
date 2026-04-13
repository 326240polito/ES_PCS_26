#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "randfiller.h"
#include "timecounter.h"
#include "sorts.hpp"

using namespace std;

// Funzione teplate per stampare i tempi contenuti nei vettori
template<typename T>
void print_vector(const vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        
    }
    cout << endl;
}


int main() {
    randfiller rf;   // Generatore di numeri casuali
    timecounter tc;  // Oggetto per misurare il tempo (tic/toc)

    // Vettori per memorizzare i tempi di esecuzione

    vector<double> times_sel_sort;
    vector<double> times_bub_sort;
    vector<double> times_ins_sort;
    vector<double> times_std_sort;
    
   // Partiamo da una dimensione di 2 elementi e raddoppiamo fino a 8192
   for (size_t i=2; i <= 8192; i*=2) {

        vector<double> v;  // Prepariamo il vettore di dimensione 'i'
        v.resize(i); 
        rf.fill(v, -500.0, 500.0);    

        // Creiamo copie identiche per ogni algoritmo
        vector<double> v_sel=v;
        tc.tic();  // Fa partire il cronometro
        selection_sort(v_sel);
        double t_sel = tc.toc();
        times_sel_sort.push_back(t_sel);  // Salva il tempo trascorso

        /*TEST BUBBLE SORT*/
        vector<double> v_bub=v;
        tc.tic();
        bubble_sort(v_bub);
        double t_bub = tc.toc();
        times_bub_sort.push_back(t_bub);

        /*TEST INSERTION SORT*/
        vector<double> v_ins=v;
        tc.tic();
        insertion_sort(v_ins);
        double t_ins = tc.toc();
        times_ins_sort.push_back(t_ins);

        /*TEST STD SORT*/
        vector<double> v_std=v;
        tc.tic();
        sort(v_std.begin(), v_std.end());
        double t_std = tc.toc();
        times_std_sort.push_back(t_std);

    } 

    cout << "Tempi BUBBLE SORT:\n";
    print_vector(times_bub_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "Tempi SELECTION SORT:\n";
    print_vector(times_sel_sort);
    cout << "--------------------------------------------------------------------\n\n";

    cout << "Tempi INSERTION SORT:\n";
    print_vector(times_ins_sort);
    cout << "--------------------------------------------------------------------\n\n";  
    
    cout << "Tempi STD SORT:\n";
    print_vector(times_std_sort);
    cout << "--------------------------------------------------------------------\n\n";




    return EXIT_SUCCESS;
}
