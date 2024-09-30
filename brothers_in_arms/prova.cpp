#include <iostream>

int main() {
	int n = 4; // Numero di righe
	int m = 2; // Numero di colonne (4x2)

	// Allocazione dinamica per una matrice 4x2
	int** counts_before = new int*[n];  // Array di puntatori (righe)
	for (int i = 0; i < n; i++) {
		counts_before[i] = new int[m];  // Allocare 2 colonne per ogni riga
	}

	// Inizializzare la matrice con valori di esempio
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			counts_before[i][j] = i + j;  // Logica di esempio: somma di i + j
		}
	}

	// Stampare la matrice 4x2
	std::cout << "La matrice counts_before è:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << counts_before[i][j] << " ";  // Stampa ogni elemento
		}
		std::cout << std::endl;  // Nuova riga dopo ogni riga della matrice
	}

	// Liberare la memoria allocata dinamicamente
	for (int i = 0; i < n; i++) {
		delete[] counts_before[i];  // Libera le colonne di ogni riga
	}
	delete[] counts_before;  // Libera l'array di puntatori

	return 0;
}
