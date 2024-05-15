#include <iostream>
#include <vector>

using namespace std;
const int N = 1000000;

vector<int> poldo_mania(int n, vector<int> numbers){
	int count = 1;
	vector<int> last_seen(N, 0);
	vector<int> result(n, 0);
	
	for (int i = 0; i < n; i++){
		if(numbers[i] > numbers[0]){
			count++;
			last_seen[numbers[i]] = count;
		}
	}
	
	result[0] = count;
	
	count = 0;
	for (int i = 1; i < n; i++){
		if (last_seen[numbers[i]] != 0){
				result[i] = last_seen[numbers[i]];
				break;
		}
		for (int j = 0; j < n; j++){
			if(numbers[j] > numbers[i]){
				count++;
				result[i] = count;
				last_seen[numbers[i]] = true;
			}
		}
	}
	return result;	
}

int main() {
	int n;
	cin >> n; // Leggi il primo numero da input e memorizzalo in n
	
	vector<int> numbers(n); // Crea un vettore di dimensione n
	
	// Leggi n numeri dalla seconda riga di input e memorizzali nel vettore
	for(int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
	
	// Stampa il valore di n e la lista di numeri
	// cout << "n: " << n << endl;
	// cout << "Numeri: ";
	// for(int i = 0; i < n; ++i) {
	// 	cout << numbers[i] << " ";
	// }
	
	cout << endl;
	
	vector<int> result = poldo_mania(n, numbers);
	for(int i = 0; i < n; ++i) {
		cout << result[i] << " ";
	}
	
	return 0;
}