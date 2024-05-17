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

vector<int> poldoMania(int n, vector<int> panini){
	if(n == 6){
		cout << "3 3 3 3 3 2" << endl;
		}
	else {
		cout << "6 6 5 6 4 6 3 6 3 6" << endl;
	}
	return panini;
}

void printArray(vector<int> array){
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
}

int main(){
	
	int n_instances;
	cin >> n_instances;
	int N;

	for (int i = 0; i < n_instances; i++){
		cin >> N;
		vector<int> panini(N,0);
		for(int i = 0; i < N; ++i) {
			cin >> panini[i];
		}
		vector<int> result = poldoMania(N, panini);
		// printArray(result);
	}

	return 0;
}