#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX_SIZE = 1000000;

int taglia(int n, int tagliere []) {
	int* combinations = new int[MAX_SIZE];
	int* last_seen = new int[MAX_SIZE];
	int* sum_prefix = new int[MAX_SIZE];
	int current_back;
	
	current_back = 1;
	combinations[0] = 1;	
	sum_prefix[0] = 1;
	
	for (int i = 1; i < n; i++){
		last_seen[tagliere[i]] = i;
		cout << last_seen[tagliere[i]] << endl;
		current_back = max(current_back, last_seen[tagliere[i]]);
		combinations[i] = sum_prefix[i] - sum_prefix[current_back-1];
		sum_prefix[i] = sum_prefix[i-1] + combinations[i];
		cout << sum_prefix[i] << endl;
		cout << endl;
	}
	return combinations[n-1];
}

int main() {
	ifstream file("input.txt");
	int n;
	file >> n; // Leggi la lunghezza dell'array

	int* tagliere = new int[n]; // Allocazione di un array di dimensione n

	for (int i = 0; i < n; ++i) {
		file >> tagliere[i]; // Leggi gli elementi dell'array uno per uno
	}
	
	file.close();

	ofstream outputFile("output.txt");
	cout << taglia(n, tagliere); // Passa l'array di interi alla funzione taglia

	return 0;
}
