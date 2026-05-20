#include <iostream>
#include "graph.hpp"             
#include "adapters.hpp"          
#include "graph_algorithms.hpp"

int main() {
    unidirected_graph G; // Creo un grafo vuoto

    // Costruiamo una griglia connessa di nodi fatta così:
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(1, 4);
    G.add_edge(1, 6);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
    G.add_edge(2, 7);
    G.add_edge(3, 6);
    G.add_edge(4, 6);
    G.add_edge(4, 7);
    G.add_edge(5, 7);
    G.add_edge(6, 7);
    G.add_edge(6, 8);
    G.add_edge(7, 9);
    G.add_edge(8, 9);
    std::cout << "--- TEST VISITE GRAFO ---" << std::endl;
    std::cout << "Numero totale di nodi nel grafo di partenza: " << G.all_nodes().size() << std::endl;
    std::cout << "Numero totale di archi nel grafo di partenza: " << G.all_edges().size() << std::endl;

    // TEST 1: VISITA IN AMPIEZZA (BFS)
    fifo q; // Creiamo il nostro adapter FIFO (coda)
    // Chiamiamo la funzione template passando 'q'. Effettuerà una BFS partendo dal nodo 1
    unidirected_graph bfsG = visita_grafo(G, 1, q);

    std::cout << "\n[BFS] Numero di archi nell'albero BFS generato: " << bfsG.all_edges().size() << std::endl;
    std::cout << "[BFS] Archi dell'albero di copertura:" << std::endl;
    for (const auto& arco :bfsG.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }

    // TEST 2: VISITA IN PROFONDITÀ (DFS ITERATIVA)
    lifo s; // Creiamo l'adapter LIFO (stack/pila)
    unidirected_graph dfsG_iterativa = visita_grafo(G, 1, s);
    std::cout << "\n[DFS Iterativa] Numero di archi nell'albero: " << dfsG_iterativa.all_edges().size() << std::endl;
    std::cout << "[DFS Iterativa] Archi dell'albero di copertura:" << std::endl;
    for (const auto& arco : dfsG_iterativa.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }
    // TEST 3: VISITA IN PROFONDITÀ (DFS RICORSIVA)
    unidirected_graph dfsG_ricorsiva = dfs_ricorsiva(G, 1); // Chiamata alla versione ricorsiva
    std::cout << "\n[DFS Ricorsiva] Numero di archi nell'albero: " << dfsG_ricorsiva.all_edges().size() << std::endl;
    std::cout << "[DFS Ricorsiva] Archi dell'albero di copertura:" << std::endl;
    for (const auto& arco : dfsG_ricorsiva.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }

    // TEST 4: ALGORITMO DI DIJKSTRA
    std::cout << "\n--- TEST DIJKSTRA (Sorgente dal nodo 1) ---" << std::endl;
    // Calcoliamo i cammini minimi dal nodo 1 a tutti gli altri nodi del grafo
    std::map<int, int> distanze = algoritmo_dijkstra(G, 1);
    // Scorriamo la mappa dei risultati. 'coppia.first' è il nodo di arrivo, 'coppia.second' è la distanza minima
    for (const auto& coppia : distanze) {
        std::cout << "Distanza minima dal nodo 1 al nodo " << coppia.first << ": " << coppia.second << " passi." << std::endl;
    }
    return 0;
}