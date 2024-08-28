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

void printVector(const vector<vector<int>>& vec) {
	for (const auto& riga : vec) {
		for (const auto& elemento : riga) {
			std::cout << elemento << ' ';
		}
		std::cout << std::endl; 
	}
}

// Function to perform Breadth First Search on a graph
// represented using adjacency list
result bfs(int N, vector<vector<int>> adjList, int startNode)
{
	result res;
	
	long ntrees = 1;
	
	// Create a vector for mark the visited nodes
	vector<bool> visited(N,false);
	
	// Create a queue for BFS
	queue<int> q;
	
	// Create a vector to store the distances
	vector<int> distances(N,0);
	
	// Create a vector to store dads
	vector<int> dads(N,0);
	
	// Create a vector to store number of dads for each node
	vector<long> ndads(N,1);

	// Mark the current node as visited and enqueue it
	visited[startNode] = true;
	q.push(startNode);

	// Iterate over the queue
	while (!q.empty()) {
		// Dequeue a vertex from queue and print it
		int currentNode = q.front();
		q.pop();
		// cout << currentNode << " ";

		// Get all adjacent vertices of the dequeued vertex
		// currentNode If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int neighbor : adjList[currentNode]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
				distances[neighbor] = distances[currentNode] + 1;
				dads[neighbor] = currentNode;
			}else{
				// vuol dire che è gia stato visitato, e quindi ha un padre, se le distanze dei padri sono uguali allora *2
				if(distances[dads[neighbor]] == distances[currentNode]){
					ndads[neighbor]++;
				}
			}
		}
	}
	
	for (int i = 0; i < ndads.size(); i++){
		ntrees = ((ntrees % 1000000007) * (ndads[i] % 1000000007)) % 1000000007;
	}
	
	res.dist = distances;
	res.dad = dads;
	res.ntrees = ntrees;
	return res;
}

int numero_passi(vector<vector<int>> archi, int numero_archi, int nodi){
	int passi = 0;
	int current_node = 0;
	
	do{ //gestire i casi che ho già visitato
		for (int i = 0; i < numero_archi; i++){
			if(archi[i][0] == current_node){
				current_node = archi[i][1];
				passi++;
			}
			if(current_node == 0 && i!=0){
				break;
			}
		}
	}while(passi % 2 == 0);
	
	return passi;
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
		//printVector(archi);
		int n_passi = numero_passi(archi, numero_archi, nodi);
		cout << "NUMERO PASSI TOTALI: " << n_passi << endl;
	}
	//printVector(archi);
}