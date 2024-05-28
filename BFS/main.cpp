#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef struct result
{
	vector<int> dist;
	vector<int> dad;
	int ntrees = 1;
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

// Function to perform Breadth First Search on a graph
// represented using adjacency list
result bfs(int N, vector<vector<int>> adjList, int startNode)
{
	result res;
	
	// Create a vector for mark the visited nodes
	vector<bool> visited(N,false);
	
	// Create a queue for BFS
	queue<int> q;
	
	// Create a vector to store the distances
	vector<int> distances(N,0);
	
	// Create a vector to store dads
	vector<int> dads(N,0);

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
			}
		}
	}
	res.dist = distances;
	res.dad = dads;
	res.ntrees = 0;
	return res;
}

// Funzione che risolve il problema (questa è solo un placeholder, la logica reale deve essere implementata)
void solve(int n, const vector<vector<int>> out_nei) {
	// Implementa la tua logica qui
	result res = bfs(n, out_nei, 0);
	vector<int> dist = res.dist;
	vector<int> dads = res.dad;
	int num_BFStrees = res.ntrees; // Placeholder value
	
	// Output placeholder (stampa l'output reale in base alla logica della funzione)
	cout << "Distances: ";
	for (int d : dist) {
		cout << d << " ";
	}
	cout << endl;

	cout << "Dads: ";
	for (int d : dads) {
		cout << d << " ";
	}
	cout << endl;

	cout << "Number of BFS trees: " << num_BFStrees << endl;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> out_nei(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			out_nei[u].push_back(v);
		}
		solve(n, out_nei);
	}
	return 0;
}