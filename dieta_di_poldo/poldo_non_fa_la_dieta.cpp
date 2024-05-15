#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int N = 1000000;

// int poldo_mania(int n, vector<int> numbers){
// 	vector<int> tails;
	
// 	for (int num : numbers) {
// 		auto it = lower_bound(tails.begin(), tails.end(), num);
// 		if (it == tails.end()) {
// 			tails.push_back(num);
// 		} else {
// 			*it = num;
// 		}
// 	}
// 	return tails.size();
// }

int dieta_poldo(int n, int* numbers){
	if (n==1 || n==0){
		return 1;
	}else{
		if(numbers[n-1] < numbers[n-2]){
			return dieta_poldo(n-1, numbers);
		}else{
			return 1 + max(dieta_poldo(n-1, numbers), dieta_poldo(n-2, numbers));
		}
	}
}

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Errore nell'apertura del file." << endl;
		return 1;
	}

	int N;
	inputFile >> N;

	if (N <= 0) {
		cerr << "Il numero di panini deve essere maggiore di zero." << endl;
		inputFile.close();
		return 1;
	}

	// Uso di un array dinamico per memorizzare i pesi dei panini
	int* panini = new int[N];
	
	for (int i = 0; i < N; ++i) {
		inputFile >> panini[i];
	}

	inputFile.close();
	
	ofstream outputFile("output.txt");
	if (!outputFile.is_open()) {
		cerr << "Errore nell'apertura del file output.txt." << endl;
		delete[] panini;
		return 1;
	}
	
	outputFile << dieta_poldo(N, panini);

	// Rilascio della memoria allocata
	delete[] panini;

	return 0;
}
