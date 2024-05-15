#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

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
			return max(dieta_poldo(n-1, numbers), dieta_poldo(n-2, numbers));
		}else{
			return 1 + dieta_poldo(n-1, numbers);			
		}
	}
}

int dieta_poldo_iter(int n, int* numbers){
	int ris = 1;
	int parz_ris = 1;
	for (int i = 0; i < n; i++){
		int max_parz = numbers[i];
		for (int j = i+1; j < n; j++){
			if(numbers[j] < max_parz){
				parz_ris++;
				max_parz = numbers[j];
			}
		}
		if(parz_ris > ris){
			ris = parz_ris;
		}
		parz_ris = 1;
	}
	return ris;
}

int main() {
	ifstream inputFile("input.txt");

	int N;
	inputFile >> N;

	int* panini = new int[N];
	
	for (int i = 0; i < N; ++i) {
		inputFile >> panini[i];
	}

	inputFile.close();
	
	ofstream outputFile("output.txt");
	
	if(N == 0){
		outputFile << N;
	}
	if(N == 1){
		outputFile << N;
	}
	outputFile << dieta_poldo_iter(N, panini);

	// Rilascio della memoria allocata
	delete[] panini;

	return 0;
}
