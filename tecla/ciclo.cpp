#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Funzione per trovare il percorso del ciclo a partire dal nodo 'start_nodo'
vector<int> trova_percorso(const vector<int>& ciclo_stack, int start_nodo) {
    vector<int> percorso;
    bool aggiungi = false;

    for (int nodo : ciclo_stack) {
        if (nodo == start_nodo) {
            aggiungi = true;
        }
        if (aggiungi) {
            percorso.push_back(nodo);
        }
    }
    percorso.push_back(start_nodo);  // Chiude il ciclo tornando al nodo iniziale
    return percorso;
}

// DFS modificata per rilevare il ciclo
bool dfs(int nodo, const vector<vector<int>>& grafo, unordered_set<int>& visitato, unordered_set<int>& nello_stack, vector<int>& ciclo_stack, vector<int>& ciclo) {
    visitato.insert(nodo);
    nello_stack.insert(nodo);
    ciclo_stack.push_back(nodo);

    for (int vicino : grafo[nodo]) {
        if (nello_stack.count(vicino)) {
            // Trovato ciclo: trova il percorso del ciclo
            ciclo = trova_percorso(ciclo_stack, vicino);
            return true;
        }

        if (!visitato.count(vicino)) {
            if (dfs(vicino, grafo, visitato, nello_stack, ciclo_stack, ciclo)) {
                return true;
            }
        }
    }

    // Rimuovi nodo dallo stack di ricorsione e dal ciclo corrente
    nello_stack.erase(nodo);
    ciclo_stack.pop_back();
    return false;
}

// Funzione principale per trovare un ciclo nel grafo
vector<int> trova_ciclo(const vector<vector<int>>& grafo) {
    unordered_set<int> visitato;
    unordered_set<int> nello_stack;
    vector<int> ciclo_stack;
    vector<int> ciclo;

    for (int nodo = 0; nodo < grafo.size(); nodo++) {
        if (!visitato.count(nodo)) {
            if (dfs(nodo, grafo, visitato, nello_stack, ciclo_stack, ciclo)) {
                return ciclo;
            }
        }
    }

    return {};  // Nessun ciclo trovato
}

// Funzione per costruire il grafo da una lista di archi
vector<vector<int>> costruisci_grafo(int num_nodi, const vector<pair<int, int>>& archi) {
    vector<vector<int>> grafo(num_nodi);
    for (const auto& arco : archi) {
        grafo[arco.first].push_back(arco.second);
    }
    return grafo;
}

int main() {
    // Esempio di input con tutti gli archi presenti nel grafo
    int num_nodi = 5;
    vector<pair<int, int>> archi = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},  // Crea un ciclo
        {2, 4}
    };

    // Costruisci il grafo dai bordi
    vector<vector<int>> grafo = costruisci_grafo(num_nodi, archi);

    // Trova un ciclo nel grafo
    vector<int> ciclo = trova_ciclo(grafo);

    // Stampa il risultato
    if (!ciclo.empty()) {
        cout << "Ciclo trovato: ";
        for (int nodo : ciclo) {
            cout << nodo << " ";
        }
        cout << endl;
    } else {
        cout << "Nessun ciclo trovato." << endl;
    }

    return 0;
}
