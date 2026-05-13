#pragma once
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
class unidirected_edge {
private:
    int node1;
    int node2;
    void node_sort(){
        if (node1 > node2) {
            std::swap(node1, node2);
        }
    }
public:
    unidirected_edge(const int& u, const int& v) {
        node1 = u;
        node2 = v;
        node_sort(); //garantisce node1 < node2
    }
    unidirected_edge() : node1(0), node2(0) {} //Costruttore di default
    int from() const { return node1; }
    int to() const { return node2; }
    //Operatore per confrontare due archi
    bool operator<(const unidirected_edge& other) const {
        if (node1 < other.node1) return true;
        if (node1 == other.node1 && node2 < other.node2) return true;
        return false;
    }
    //Operatore per vedere se due archi sono uguali
    bool operator==(const unidirected_edge& other) const {
        return (node1 == other.node1 && node2 == other.node2);
    }
};
//Operatore per stampare arco
std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge) {
    os << "(" << edge.from() << ", " << edge.to() << ")";
    return os;
}
//Classe per il grafo
 class unidirected_graph {
private:
    std::set<unidirected_edge> archi; //non permette duplicati
    std::map<unidirected_edge, int> mappa_id; //Associa a ogni oggetto unidirected_edge un numero intero
    std::map<int, unidirected_edge> mappa_archi; //Associa a un intero l'arco
    int contatore_id = 0;

public: 
    unidirected_graph() { contatore_id = 0; } //Costruttore vuoto
    //Aggiungi arco
    void add_edge(int u, int v) {
        unidirected_edge nuovo_arco(u, v);
        
        if (archi.find(nuovo_arco) == archi.end()) {//Vede se arco non c'è già. Cerca l'arco nel set. Se arrivi alla fine (end()) senza averlo trovato, allora procedi
            archi.insert(nuovo_arco);
            mappa_id[nuovo_arco] = contatore_id;
            mappa_archi[contatore_id] = nuovo_arco;
            contatore_id++;
        }
    }
    //Trovare vicini di un nodo
    std::set<int> neighbours(int nodo) const {
        std::set<int> vicini;
        for (const auto& arco: archi) { //passo in rassegna ogni arco del grafo
            if (arco.from() == nodo) { //Se il nodo cercato è il primo, allora il suo vicino è il secondo (arco.to())
                vicini.insert(arco.to()); //lo aggiungo ai vicini
            } else if (arco.to() == nodo) { //il contrario
                vicini.insert(arco.from());
            }
        }
        return vicini;
    }
    //Restituisce tutti gli archi del grafo
    std::set<unidirected_edge> all_edges() const { 
        return archi;
    }
    //Restituisce tutti i nodi del grafo
    std::set<int> all_nodes() const {
        std::set<int> nodi;
        for (const auto& arco : archi) {
            nodi.insert(arco.from());
            nodi.insert(arco.to());
        }
        return nodi;
    }
    int edge_number(const unidirected_edge& e) const {
        return mappa_id.at(e);
    }

    unidirected_edge edge_at(int id) const {
        return mappa_archi.at(id);
    }
    //Differenza tra grafi
    unidirected_graph operator-(const unidirected_graph& other_grafo) const {
        unidirected_graph risultato;
        for (const auto& arco : archi) {
            // Se l'arco non è nel secondo grafo, lo aggiungiamo al risultato
            if (other_grafo.archi.find(arco) == other_grafo.archi.end()) {
                risultato.add_edge(arco.from(), arco.to()); //Se arco solo del primo grafo lo aggiungiamo
            }
        }
        return risultato;
    }
};
