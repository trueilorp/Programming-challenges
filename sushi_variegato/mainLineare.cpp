#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX_SIZE = 1000;

int taglia(int N, int V[]) {
	int combinations[MAX_SIZE];
	int last_seen[MAX_SIZE];
	int prefixSum[MAX_SIZE];
	int curr_back = -1;

	for (int i = 0; i < MAX_SIZE; i++) {
		last_seen[i] = -1;
	}

	combinations[0] = 1;
	last_seen[V[0]] = 0;
	prefixSum[0] = 1;

	for (int i = 1; i < N; i++) {
		curr_back = max(last_seen[V[i]], curr_back);

		if (curr_back < 0) {
			combinations[i] = (prefixSum[i - 1] + 1) % 1000000007;
		} else if (curr_back == 0) {
			combinations[i] = prefixSum[i - 1] % 1000000007;
		} else {
			combinations[i] = (prefixSum[i - 1]  - prefixSum[max(curr_back - 1, 0)] + 1000000007) % 1000000007;
		}
		prefixSum[i] = (combinations[i] + prefixSum[i - 1]) % 1000000007;
		last_seen[V[i]] = i;
	}

	return combinations[N - 1];
}


int tagliaFinal(int, int[]);
int tagliaFinal(int N, int V[]) {
    int combinations[MAX_SIZE + 1] = { 0 };
    int last_seen[MAX_SIZE];
    int prefixSum[MAX_SIZE + 2] = { 0 };
    bool canSum = true;
    int curr_back = -1;

    for (int i = 0; i < MAX_SIZE; i++) {
        last_seen[i] = 0;
    }

    combinations[0] = 1;
    prefixSum[0] = 0;
    prefixSum[1] = 1;

    for (int i = 1; i <= N; i++) {
        curr_back = max(last_seen[V[i - 1]] - 1, curr_back);

        combinations[i] = (prefixSum[i] - prefixSum[curr_back + 1] + 1000000007) % 1000000007;

        prefixSum[i + 1] = (combinations[i] + prefixSum[i]) % 1000000007;

        last_seen[V[i - 1]] = i;
    }

    return combinations[N];
}

int main() {
	ifstream file("input.txt");
	int n;
	file >> n; // Leggi la lunghezza dell'array

	int tagliere[n]; // Allocazione di un array di dimensione n

	for (int i = 0; i < n; ++i) {
		file >> tagliere[i]; // Leggi gli elementi dell'array uno per uno
	}
	
	file.close();
	
	ofstream outputFile("output.txt");
	cout << tagliaFinal(n, tagliere); // Passa l'array di interi alla funzione taglia

	return 0;
}