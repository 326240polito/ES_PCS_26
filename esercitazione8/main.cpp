#include "graph.hpp"
#include <iostream>

int main() {
    // Faccio test per la simmetria 
    std::cout << "--- TEST LOGICA UNIDIRECTED_EDGE ---" << std::endl;
    unidirected_edge e_test1(5, 8);
    unidirected_edge e_test2(8, 5);
    
    std::cout << "Confronto (5,8) e (8,5): ";
    if (e_test1 == e_test2) {
        std::cout << "OK, sono lo stesso" << std::endl;
    } else {
        std::cout << "ERRORE, sono diversi" << std::endl;
    }
    // Creo il primo grafo
    unidirected_graph g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 1); // Il numero di archi non deve aumentare, deve contare un solo arco per (1, 2) e (2, 1)
    g1.add_edge(2, 3);
    g1.add_edge(7, 9);
    g1.add_edge(11, 3);
    g1.add_edge(6, 4);
    g1.add_edge(7, 7); // nodo con se stesso

    std::cout << "--- TEST GRAFO G1 ---" << std::endl;
    std::cout << "Numero archi in G1: " << g1.all_edges().size() << std::endl;

    // Faccio test per recupero tramite ID 
    std::cout << "\n--- TEST RECUPERO TRAMITE ID ---" << std::endl;
    unidirected_edge da_cercare(11, 3);
    int id = g1.edge_number(da_cercare);
    unidirected_edge recuperato = g1.edge_at(id);
    
    std::cout << "ID dell'arco:  " << da_cercare << " " << id << std::endl;
    std::cout << "Arco recuperato con ID " << id << ": " << recuperato << std::endl;
    if (da_cercare == recuperato) std::cout << "OK: Recupero riuscito!" << std::endl;

    // Creo il secondo grafo
    unidirected_graph g2;
    g2.add_edge(1, 2);
    g2.add_edge(6, 4);
    g2.add_edge(4, 7);

    // Faccio il test per la differenza
    // Gli archi (1,2) e (6,4) sono in entrambi, quindi spariranno da G1
    unidirected_graph dif = g1 - g2;
    std::cout << "\n--- TEST DIFFERENZA ---" << std::endl;
    std::cout << "Archi rimasti in G1-G2: " << dif.all_edges().size() << std::endl;

    // Stampiamo gli archi rimasti e i loro nuovi ID
    for (const auto& e : dif.all_edges()) {
        std::cout << "Arco: " << e << " | ID assegnato: " << dif.edge_number(e) << std::endl;
    }

    // Faccio test per i vicini
    std::cout << "\n--- TEST VICINI ---" << std::endl;
    std::cout << "Vicini del nodo 3 in G1: ";
    std::set<int> v = g1.neighbours(3);
    for (int n : v) std::cout << n << " ";
    
    std::cout << "\nVicini di un nodo inesistente: "; // Testo un nodo che non esiste, ad esempio 99
    std::set<int> v_vuoto = g1.neighbours(99);
    std::cout << (v_vuoto.empty() ? "Nessun vicino " : "ERRORE") << std::endl;

    // Faccio test per nodi totali
    std::cout << "\n--- TEST NODI TOTALI ---" << std::endl;
    std::cout << "Numero totale di nodi in G1: " << g1.all_nodes().size() << std::endl;
    return 0;
}