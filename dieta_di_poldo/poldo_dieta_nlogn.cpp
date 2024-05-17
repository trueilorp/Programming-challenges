#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
const int SIZE = 10000;

int calc_dim(vector<int> array){
	int length = 0;
	int size = array.size();
	for (int i = 0; i < size; i++){
		if(array[i] != -1){
			length++;
		}
	}
	return length;		
}

int binary_search(vector<int>& vec, int target) {
	int left = 0;
	int right = calc_dim(vec) - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (vec[mid] == target) {
			return mid + 1;
		} else if (vec[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	return left; // Elemento non trovato, restituire l'indice del primo elemento maggiore di target
}

int dieta_poldo(int n, vector<int> numbers)
{
	vector<int> heads(n,-1);

	heads[0] = numbers[0];
	int index_fin = 0;
	for (int i = 0; i < n; i++){
		int index = binary_search(heads, numbers[i]);
		heads[index] = numbers[i];
		index_fin = index;
	}
	return index_fin+1;
}

int main(){
	ifstream inputFile("input.txt");

	int N;
	inputFile >> N;

	vector<int> panini(N,0);

	for (int i = 0; i < N; ++i){
		inputFile >> panini[i];
	}

	inputFile.close();
	ofstream outputFile("output.txt");
	
	cout << panini[0];

	if (N == 0){
		outputFile << N;
	}
	if (N == 1){
		outputFile << N;
	}
	outputFile << dieta_poldo(N, panini);

	return 0;
}
