#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <set>

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

// DFS modificata per rilevare i cicli
void dfs(int nodo, const vector<vector<int>>& grafo, unordered_set<int>& visitato, unordered_set<int>& nello_stack, vector<int>& ciclo_stack, vector<vector<int>>& cicli) {
    visitato.insert(nodo);
    nello_stack.insert(nodo);
    ciclo_stack.push_back(nodo);

    for (int vicino : grafo[nodo]) {
        if (nello_stack.count(vicino)) {
            // Trovato ciclo: trova il percorso del ciclo
            vector<int> ciclo = trova_percorso(ciclo_stack, vicino);
            cicli.push_back(ciclo);
        } else if (!visitato.count(vicino)) {
            dfs(vicino, grafo, visitato, nello_stack, ciclo_stack, cicli);
        }
    }

    // Rimuovi nodo dallo stack di ricorsione e dal ciclo corrente
    nello_stack.erase(nodo);
    ciclo_stack.pop_back();
}

// Funzione principale per trovare tutti i cicli nel grafo
vector<vector<int>> trova_tutti_i_cicli(const vector<vector<int>>& grafo) {
    unordered_set<int> visitato;
    unordered_set<int> nello_stack;
    vector<int> ciclo_stack;
    vector<vector<int>> cicli;

    for (int nodo = 0; nodo < grafo.size(); nodo++) {
        if (!visitato.count(nodo)) {
            dfs(nodo, grafo, visitato, nello_stack, ciclo_stack, cicli);
        }
    }

    return cicli;
}

// Funzione per stampare un vettore di vettori su un file
void printCicli(ofstream& outFile, const vector<vector<int>>& cicli) {
    for (const auto& ciclo : cicli) {
        for (size_t i = 0; i < ciclo.size(); ++i) {
            outFile << ciclo[i];
            if (i < ciclo.size() - 1) {
                outFile << " ";
            }
        }
        outFile << endl;
    }
}

// Funzione per costruire il grafo da una lista di archi
vector<vector<int>> costruisci_grafo(int num_nodi, const vector<vector<int>>& archi) {
    vector<vector<int>> grafo(num_nodi);
    for (const auto& arco : archi) {
        grafo[arco[0]].push_back(arco[1]);
    }
    return grafo;
}

int main() {
    ifstream inputFile("input.txt"); // Apri il file input.txt
    ofstream outputFile("output.txt"); // Crea e apri il file output.txt per la scrittura

    if (!inputFile) {
        cerr << "Errore nell'apertura del file input.txt!" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Errore nell'apertura del file output.txt!" << endl;
        return 1;
    }

    int nodi, numero_archi;
    inputFile >> nodi >> numero_archi;  // Leggi il numero di nodi e archi

    vector<vector<int>> archi(numero_archi);
    for (int i = 0; i < numero_archi; i++) {
        int u, v;
        inputFile >> u >> v;  // Leggi ogni coppia di archi
        archi[i].push_back(u);
        archi[i].push_back(v);
    }

    inputFile.close();  // Chiudi il file di input dopo aver letto

    vector<vector<int>> grafo = costruisci_grafo(nodi, archi);
    vector<vector<int>> cicli = trova_tutti_i_cicli(grafo);

    // Scrivi i cicli su output.txt
    printCicli(outputFile, cicli);

    outputFile.close();  // Chiudi il file di output dopo aver scritto

    return 0;
}
