#pragma once
#include <queue>
#include <stdexcept>
#include <stack>

// Contenitore FIFO (First In, First Out) -> Una Coda standard
// Chi entra per primo, esce per primo (come alla fila alle poste).
class fifo {
private:
    std::queue<int> q; // Usiamo la coda della Standard Library dentro la nostra classe

public:
    fifo() = default; // Costruttore di default
    // Inserisco un elemento in fondo alla coda
    void put(int val) {
        q.push(val);
    }
    // Estrae e restituisce l'elemento in testa alla coda
    int get() {
        if (q.empty()) {
            throw std::runtime_error("Errore: la coda è vuota");
        }
        int val = q.front(); // Prende l'elemento davanti
        q.pop();             // Lo rimuove dalla coda
        return val;          // Lo rstituisce
    }
    // Controllo se la coda è vuota
    bool empty() const {
        return q.empty();
    }
};
// Contenitore LIFO (Last In, First Out) -> Uno Stack (Pila) standard
// L'ultimo che entra è il primo a uscire
class lifo {
private:
    std::stack<int> s; // Usiamo lo stack della Standard Library 
public:
    lifo() = default;
    // Inserire un elemento in cima alla pila
    void put(int val) {
        s.push(val);
    }
    // Estrarre e restituire l'elemento in cima alla pila
    int get() {
        if (s.empty()) {
            throw std::runtime_error("Errore: lo stack è vuoto");
        }
        int val = s.top(); // Prende l'elemento in cima
        s.pop();           // Lo rimuove dallo stack
        return val;        // Lo restituisce
        }
        // Controllo se la pila è vuota
    bool empty() const {
        return s.empty();
    }
};
