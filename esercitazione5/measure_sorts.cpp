#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "randfiller.h"
#include "timecounter.h"
#include "sorts.hpp"

using namespace std;

// Funzione di utilità per stampare i tempi medi
void print_results(const string& label, const vector<double>& times) {
    cout << label << ": ";
    for (double t : times) {
        cout << t << " ";
    }
    cout << endl;
}

int main() {
    randfiller rf;
    timecounter tc;
    const int num_vettori = 100; 

    vector<int> test_sizes = {2, 4, 8, 16, 32, 50, 75, 90, 100, 110, 120, 150};

    // Vettori per memorizzare le medie dei tempi per ogni dimensione
    vector<double> sizes, times_bub, times_sel, times_ins;
    vector<double> times_merge, times_quick, times_hybrid, times_std;
    
    cout << "Avvio misurazioni medie su " << num_vettori << " vettori per dimensione..." << endl;

    for (int dim : test_sizes) {
        sizes.push_back(static_cast<double>(dim));
        
        // Preallocazione del dataset (vettore di vettori)
        vector<vector<double>> dataset(num_vettori, vector<double>(dim));
        for (auto& v : dataset) {
            rf.fill(v, -500.0, 500.0); // Riempimento casuale con positivi e negativi
        }

        // --- TEST BUBBLE SORT ---
        auto data_bub = dataset;
        tc.tic(); 
        for (auto& v : data_bub) bubble_sort(v);
        times_bub.push_back(tc.toc() / num_vettori); // Calcolo media

        // --- TEST SELECTION SORT ---
        auto data_sel = dataset;
        tc.tic(); 
        for (auto& v : data_sel) selection_sort(v);
        times_sel.push_back(tc.toc() / num_vettori);

        // --- TEST INSERTION SORT ---
        auto data_ins = dataset;
        tc.tic(); 
        for (auto& v : data_ins) insertion_sort(v);
        times_ins.push_back(tc.toc() / num_vettori);

        // --- TEST MERGE SORT ---
        auto data_merge = dataset;
        tc.tic(); 
        for (auto& v : data_merge) mergesort(v, 0, v.size() - 1);
        times_merge.push_back(tc.toc() / num_vettori);

        // --- TEST QUICK SORT ---
        auto data_quick = dataset;
        tc.tic(); 
        for (auto& v : data_quick) quicksort(v, 0, (int)v.size() - 1);
        times_quick.push_back(tc.toc() / num_vettori);

        // --- TEST QUICK SORT HYBRID ---
        auto data_hyb = dataset;
        tc.tic(); 
        for (auto& v : data_hyb) quicksort_hybrid(v, 0, (int)v.size() - 1, 15);
        times_hybrid.push_back(tc.toc() / num_vettori);

        // --- TEST STD SORT ---
        auto data_std = dataset;
        tc.tic(); 
        for (auto& v : data_std) std::sort(v.begin(), v.end());
        times_std.push_back(tc.toc() / num_vettori);
        
        cout << "Completata dimensione: " << dim << endl;
    }

    // Stampa finale dei risultati per l'analisi
    cout << "\n--- RISULTATI MEDI (secondi) ---\n" << endl;
    cout << "Dimensioni:           "; for(auto s : sizes) cout << s << " "; cout << endl;
    print_results("BUBBLE SORT      ", times_bub);
    print_results("SELECTION SORT   ", times_sel);
    print_results("INSERTION SORT   ", times_ins);
    print_results("MERGE SORT       ", times_merge);
    print_results("QUICK SORT       ", times_quick);
    print_results("QUICK HYBRID     ", times_hybrid);
    print_results("STD SORT         ", times_std);

    return EXIT_SUCCESS; // Segnala corretta esecuzione
}