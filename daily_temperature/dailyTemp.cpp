#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> ris(temperatures.size(), 0); // Inizializza il vettore dei risultati con dimensione uguale a quello delle temperature

	for (int i = 0; i < temperatures.size() - 1; i++) {
		int day_to_wait = 0;
		for (int j = i + 1; j < temperatures.size(); j++) {
			if (temperatures[j] > temperatures[i]) {
				day_to_wait++;
				ris[i] = day_to_wait;
				break;
			} else {
				day_to_wait++;
			}
		}
	}
	return ris;
}

int main() {
	vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73}; // Creazione di un vettore di interi

	vector<int> result = dailyTemperatures(temp); // Chiamata alla funzione per ottenere i risultati

	// Stampa dei risultati
	cout << "Risultati: ";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}