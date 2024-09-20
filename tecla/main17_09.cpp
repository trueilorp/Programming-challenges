#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef struct result
{
	vector<int> dist;
	vector<int> dad;
	long ntrees;
}res;

void printVector(const vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i < vec.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

void printVectorVector(const vector<vector<int>>& vec) {
	for (const auto& riga : vec) {
		for (const auto& elemento : riga) {
			std::cout << elemento << ' ';
		}
		std::cout << std::endl; 
	}
}
bool trovaCicloDFS(int nodo, int genitore, vector<vector<int>>& listaAdiacenza, vector<bool>& visitato, vector<int>& ciclo, vector<int>& parent) {
    visitato[nodo] = true;  // Marca il nodo come visitato
    cout << "Visiting node: " << nodo << endl;

    for (int vicino : listaAdiacenza[nodo]) {
        cout << "Checking neighbor: " << vicino << " of node: " << nodo << endl;
        if (!visitato[vicino]) {
            parent[vicino] = nodo;  // Aggiorna il genitore del vicino
            cout << "Visiting neighbor: " << vicino << " (parent: " << nodo << ")" << endl;

            // Se il vicino non è stato visitato, continua la DFS
            if (trovaCicloDFS(vicino, nodo, listaAdiacenza, visitato, ciclo, parent)) {
                return true;  // Se troviamo un ciclo, ritorniamo vero
            }
        } else if (vicino != genitore) {
            // Se il vicino è stato visitato ed è diverso dal genitore, abbiamo trovato un ciclo
            cout << "Cycle detected at node: " << vicino << endl;

            // Ricostruisci il ciclo
            ciclo.clear();  // Pulisce il ciclo precedente
            ciclo.push_back(vicino);
            for (int cur = nodo; cur != vicino; cur = parent[cur]) {
                ciclo.push_back(cur);
            }
            ciclo.push_back(vicino);  // Aggiungi di nuovo il nodo iniziale per completare il ciclo

            return true;
        }
    }

    return false;
}

vector<int> trovaCiclo(int numNodi, vector<vector<int>>& listaAdiacenza) {
    vector<bool> visitato(numNodi, false);  // Array per tracciare i nodi visitati
    vector<int> parent(numNodi, -1);  // Array per tracciare i genitori dei nodi
    vector<int> ciclo;  // Vettore per memorizzare il ciclo

    // Esegui DFS a partire da ogni nodo non visitato
    for (int i = 0; i < numNodi; ++i) {
        if (!visitato[i]) {
            cout << "Starting DFS from node: " << i << endl;
            if (trovaCicloDFS(i, -1, listaAdiacenza, visitato, ciclo, parent)) {
                int lunghezza_ciclo = ciclo.size() - 1;  // Numero di archi nel ciclo
                cout << "Cycle length: " << lunghezza_ciclo << endl;
                
                // Verifica se il ciclo ha un numero dispari di archi
                if (lunghezza_ciclo % 2 != 0) {  // Verifica se è dispari
                    return ciclo;  // Ritorna il ciclo trovato
                } else {
                    cout << "Cycle is even, continuing search." << endl;
                    ciclo.clear();  // Pulisci il ciclo trovato e continua la ricerca
                }
            }
        }
    }

    return {};  // Se non viene trovato nessun ciclo, ritorna un vettore vuoto
}


vector<vector<int>> adjList (vector<vector<int>> archi, int numNodi){
	// Inizializza la lista di adiacenza
	vector<vector<int>> listaAdiacenza(numNodi); 
	
	// Popola la lista di adiacenza
	for (const auto& arco : archi) {
		int u = arco[0];
		int v = arco[1];

		// Aggiungi v alla lista di u
		listaAdiacenza[u].push_back(v);

		// Se il grafo è non orientato, aggiungi anche u alla lista di v
		listaAdiacenza[v].push_back(u);
	}

	return listaAdiacenza;
}

int numero_passi(vector<vector<int>> archi, int numero_archi, int nodi){
	int current_node = 0;
	vector<vector<int>> listaAdiacenza = adjList(archi, nodi);
	cout << endl << "LISTA D'ADIACENZA: " << endl;
	printVectorVector(listaAdiacenza);

	vector<int> ciclo = trovaCiclo(nodi, listaAdiacenza);
	cout << endl << endl;
	printVector(ciclo);
	return ciclo.size();
}

int main(){
	int n_instances;
	cin >> n_instances;
	
	int nodi, numero_archi;
	cin >> nodi;
	cin >> numero_archi;
	
	vector<vector<int>> archi(numero_archi);
	for (int i = 0; i < numero_archi; i++){
		int u,v;
		cin >> u >> v;
		archi[i].push_back(v);
		archi[i].push_back(u);
	}	
	
	cout << numero_passi(archi, numero_archi, nodi);
	
	//printVector(archi);
}