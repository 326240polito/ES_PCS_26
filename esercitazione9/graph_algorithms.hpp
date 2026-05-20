#pragma once
#include "graph.hpp" 
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <limits>

// --- VISITA ITERATIVA (BFS o DFS a seconda del container) ---
template <typename C>
unidirected_graph visita_grafo(const unidirected_graph& G, int nodo_partenza, C& container) {
    unidirected_graph albero; // L'albero finale che conterà i nodi visitati
    std::set<int> visitati; // Insieme per ricordarsi i nodi già scoperti

    std::map<int, int> mappa_padri; // Questa mappa serve per ricordarci da quale padre siamo arrivati a un nodo.
    // Inseriamo il nodo iniziale nel contenitore e lo marchiamo come visitato
    container.put(nodo_partenza);
    visitati.insert(nodo_partenza);
    
    while (!container.empty()) { // Finché il contenitore (la coda o la pila) non è vuoto
        int nodo_corrente = container.get(); 
        // Se per questo nodo 'nodo_corrente' avevamo memorizzato un padre, significa che abbiamo trovato un arco dell'albero di visita.
        if (mappa_padri.find(nodo_corrente) != mappa_padri.end()) {
            albero.add_edge(mappa_padri[nodo_corrente], nodo_corrente);
        }
        // Esploriamo tutti i vicini del nodo corrente
        for (int neighbor : G.neighbours(nodo_corrente)) {
            // Se il vicino non è ancora stato visitato
            if (visitati.find(neighbor) == visitati.end()) {
                visitati.insert(neighbor); // Lo segnamo come visitato
                mappa_padri[neighbor] = nodo_corrente; // Memorizziamo chi è suo padre
                container.put(neighbor); // Lo mettiamo nel contenitore per i prossimi passi
            }
        }
    }
    return albero; // Restituisco albero di visita generato
}

// VISITA DFS RICORSIVA
// Funzione di supporto interna che si auto-invoca (ricorsione)
void dfs_aiuto_ricorsivo(const unidirected_graph& G, int nodo_corrente, int padre, std::set<int>& visitati, unidirected_graph& albero) {
    visitati.insert(nodo_corrente); // Segnamo il nodo corrente come visitato
    // Se il padre è diverso da -1, significa che non siamo alla radice iniziale, quindi questo è un arco valido che fa parte dell'albero DFS.
    if (padre != -1) {
        albero.add_edge(padre, nodo_corrente);
    }
    // Scopriamo i vicini del nodo corrente
    for (int neighbor : G.neighbours(nodo_corrente)) {
        if (visitati.find(neighbor) == visitati.end()) {
            dfs_aiuto_ricorsivo(G, neighbor, nodo_corrente, visitati, albero); // Chiamata ricorsiva
        }
    }
}

// Funzione principale per la DFS ricorsiva
unidirected_graph dfs_ricorsiva(const unidirected_graph& G, int nodo_partenza) {
    unidirected_graph albero;
    std::set<int> visitati;
    // Verifichiamo che il nodo iniziale esista nel grafo prima di partire
    auto tutti_i_nodi = G.all_nodes();
    if (tutti_i_nodi.find(nodo_partenza) != tutti_i_nodi.end()) {
        dfs_aiuto_ricorsivo(G, nodo_partenza, -1, visitati, albero);
    }
    return albero;
}

// ALGORITMO DI DIJKSTRA
std::map<int, int> algoritmo_dijkstra(const unidirected_graph& G, int nodo_partenza) {
    std::map<int, int> distanze; // Mappa finale
    // Inizialmente impostiamo la distanza di ogni nodo a "infinito"
    for (int nodo : G.all_nodes()) {
        distanze[nodo] = std::numeric_limits<int>::max();
    }
    
    distanze[nodo_partenza] = 0;

    // Coda con priorità per estrarre sempre il nodo più vicino (distanza minore)
    // Memorizza coppie nella forma: {distanza, nodo}
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> coda_prioritaria;
    coda_prioritaria.push({0, nodo_partenza}); // Mettiamo il nodo di partenza nella coda

    while (!coda_prioritaria.empty()) { // Finché ci sono nodi nella coda da elaborare
        // Estraiamo il nodo che ha la distanza stimata più piccola in assoluto
        int d_corrente = coda_prioritaria.top().first; // Prende la distanza
        int u = coda_prioritaria.top().second;         // Prende il nome/ID del nodo
        coda_prioritaria.pop();                        // Lo toglie dalla coda
        
        if (d_corrente > distanze[u]) continue; 
        
        // Esploriamo tutti i vicini del nodo 'u' appena estratto
        for (int v : G.neighbours(u)) {
            int peso_arco = 1; 
            if (distanze[u] + peso_arco < distanze[v]) {
                distanze[v] = distanze[u] + peso_arco;   // Aggiorniamo la mappa con la nuova distanza minore
                coda_prioritaria.push({distanze[v], v}); // Inseriamo la nuova stima nella coda con priorità
            }
        }
    }
    return distanze; // Restituisiamo la mappa con tutte le distanze minime calcolate
}