#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

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

vector<int> invertNegateArray(vector<int> numbers){
	int n = numbers.size();
	reverse(numbers.begin(), numbers.end());
	for (int i = 0; i < n; i++){
		numbers[i] = numbers[i] * -1;
	}
	return numbers;	
}

vector<int> dieta_poldo(vector<int> numbers){
	int n = numbers.size();
	vector<int> diete(n,0);
	vector<int> tails;
	tails.push_back(numbers[0]); 
	diete[0] = 1;
	
	for (int i = 1; i < n; i++) {
		if (numbers[i] > tails.back()) {
			tails.push_back(numbers[i]);
			diete[i] = tails.size(); //indice di dove scrivo in tails (+1 per lo shift dell'array) 
		} else {
			int index = binary_search(tails, numbers[i]);
			tails[index] = numbers[i];
			diete[i] = index + 1; // (+1 per lo shift dell'array) 
		}
	}	
	return diete;
}

vector<int> poldoMania(int n, vector<int> panini){
	vector<int> result (n,-1);
	vector<int> result_pre = dieta_poldo(panini);
	vector<int> result_suf = dieta_poldo(invertNegateArray(panini));
	reverse(result_suf.begin(), result_suf.end());
	for (int i = 0; i < n; i++){
		//cout << result_suf[i] << " ";
		result[i] = result_pre[i] + result_suf[i] - 1;
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