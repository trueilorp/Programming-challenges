#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef struct result
{
	vector<int> dist;
	vector<int> dad;
	long ntrees;
}res;

typedef struct passi_percorso
{
	int passi;
	vector<int> percorso;
}pp;

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

void printVector(const vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i < vec.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

void printVector(const vector<vector<int>>& vec) {
	for (const auto& riga : vec) {
		for (const auto& elemento : riga) {
			std::cout << elemento << ' ';
		}
		std::cout << std::endl; 
	}
}

// passi_percorso numero_passi(vector<vector<int>> archi, int numero_archi, int nodi){
// 	passi_percorso pas_perc;
// 	int passi = 0;
// 	int current_node = 0;
// 	vector <int> nodi_visitati;
// 	nodi_visitati.push_back(0);
	
// 	do{ //gestire i casi che ho già visitato
// 		for (int i = 0; i < numero_archi; i++){
// 			if(archi[i][0] == current_node){
// 				current_node = archi[i][1];
// 				passi++;
// 				nodi_visitati.push_back(current_node);
// 			}
// 			if(current_node == 0 && i!=0){
// 				break;
// 			}
// 		}
// 	}while(passi % 2 == 0);
	
// 	pas_perc.passi = passi;
// 	reverse(nodi_visitati.begin(), nodi_visitati.end());
// 	pas_perc.percorso = nodi_visitati;
// 	return pas_perc;
	
// 	result res = bfs(nodi, archi, 0);
// 	vector<int> distanze = res.dist;
// }

passi_percorso numero_passi_e_percorso(vector<vector<int>> grafo, int numero_archi, int nodi){
	int passi = 0;
	vector<int> ciclo;
	do{
		ciclo = trova_ciclo(grafo);
		passi = ciclo.size() - 1;
	}while(passi % 2 == 0);
	
	passi_percorso pas_perc;
	pas_perc.passi = passi;
	pas_perc.percorso = ciclo;
	
	return pas_perc;
}

// Funzione per costruire il grafo da una lista di archi
vector<vector<int>> costruisci_grafo(int num_nodi, const vector<vector<int>>& archi) {
	vector<vector<int>> grafo(num_nodi);
	for (const auto& arco : archi) {
		grafo[arco[0]].push_back(arco[1]);
	}
	return grafo;
}

int main(){
	int n_instances;
	cin >> n_instances;
	
	for (int instance = 0; instance < n_instances; instance++){

		int nodi, numero_archi;
		cin >> nodi;
		cin >> numero_archi;
		
		vector<vector<int>> archi(numero_archi);
		for (int i = 0; i < numero_archi; i++){
			int u,v;
			cin >> u >> v;
			archi[i].push_back(u);
			archi[i].push_back(v);
		}	
		
		vector<vector<int>> grafo = costruisci_grafo(nodi, archi);
		passi_percorso res = numero_passi_e_percorso(grafo, numero_archi, nodi);
		cout << res.passi << endl;
		printVector(res.percorso);
		//printVector(archi);
		//passi_percorso res = numero_passi(archi, numero_archi, nodi);
		//cout << res.passi << endl;
		//printVector(res.percorso);
	}
	//printVector(archi);
}
