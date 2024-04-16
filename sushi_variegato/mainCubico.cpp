#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int taglia(int n, int tagliere[]) {
	int combinations [n] = {0};
	combinations[0] = 1;
	bool plus = true;
	for (int i = 1; i < n; i++){
		for (int j = i; j >= 0; j--){
			for (int k = j+1; k <= i; k++){
				if (tagliere[j] == tagliere[k]){
					plus = false;
					break; // Non faccio niente
				}
			}
			if (plus){
				if(j>0){
					combinations[i] = combinations[i] + combinations[j-1];
				}else{
					combinations[i]++;					
				}
			}else{
				plus = true;
				break;
			}			
		}
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
	outputFile << taglia(n, tagliere); // Passa l'array di interi alla funzione taglia

	return 0;
}
