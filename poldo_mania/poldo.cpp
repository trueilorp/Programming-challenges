#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
const int SIZE = 10000;

void printArray(vector<int> array){
	int n = array.size();
	for (int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
}

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

int dieta_poldo_pref(vector<int> numbers){
	int n = numbers.size();
	vector<int> tails;
	tails.push_back(numbers[0]); 
	int final_index = 1;
	
	for (int i = 1; i < n; i++) {
		if (numbers[i] > tails.back()) {
			tails.push_back(numbers[i]);
			final_index = i;
		} else {
			int index = binary_search(tails, numbers[i]);
			tails[index] = numbers[i];
			final_index = index;
		}
	}
	
	return final_index;
}

int dieta_poldo_suff(vector<int> numbers){
	int n = numbers.size();
	// Giro l'array, metto i numeri negativi e cerco sempre la crescente
	reverse(numbers.begin(), numbers.end());
	for (int i = 0; i < n; i++){
		numbers[i] = numbers[i] * -1;
	}
	
	vector<int> tails;
	tails.push_back(numbers[0]); 
	int final_index = 1;
	
	for (int i = 1; i < n; i++) {
		if (numbers[i] > tails.back()) {
			tails.push_back(numbers[i]);
			final_index = i;
		} else {
			int index = binary_search(tails, numbers[i]);
			tails[index] = numbers[i];
			final_index = index+1;
		}
	}
	return final_index;
}

vector<int> poldoMania(int n, vector<int> panini){
	vector<int> result (n,-1);
	
	for (int i = 0; i < n; i++){
		vector<int> prefix(panini.begin(), panini.begin() + i + 1);
		vector<int> suffix(panini.begin() + i, panini.end());
		int result_pre = dieta_poldo_pref(prefix);
		int result_suf = dieta_poldo_suff(suffix);
		cout << result_pre << " " << result_suf << endl;
		result[i] = result_pre + result_suf - 1;
	}
	return result;
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
		printArray(result);
		cout << endl;
	}

	return 0;
}