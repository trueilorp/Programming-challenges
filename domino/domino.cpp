#include <iostream>
#include <vector>
#include <cmath> // Per abs()

using namespace std;

void printVector(const vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i < vec.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

vector<int> sumArr(int n, const vector<int>& h) {
	vector<int> sum_arr(n);
	for (int i = 0; i < n; ++i) {
		sum_arr[i] = h[i] + i;
	}
	return sum_arr;
}

void solve(int n, vector<int>& h, int& single_rise_val, int& single_rise_index, vector<int>& distributed_rise_new_h) {
	
	distributed_rise_new_h = h;

	vector<int> arrOfSum = sumArr(n, h);
	int current_index_to_hit = arrOfSum[0];
	
	bool aggiornato = false;
	int i = 0;
	while (current_index_to_hit < n) {
		if (arrOfSum[i] > current_index_to_hit) {
			current_index_to_hit = arrOfSum[i];
		}
		
		if (current_index_to_hit == n) {
			break;
		}
		
		if (i == current_index_to_hit - 1) {
			if (!aggiornato) {
				single_rise_index = i;
				aggiornato = true;
			}
			// Cambio l'altezza della differenza + 1
			int add = abs(arrOfSum[i] - current_index_to_hit) + 1;
			distributed_rise_new_h[i] += add;
			single_rise_val += add;
		}
		
		i++;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;

		vector<int> h(n);
		for (int i = 0; i < n; ++i) {
			cin >> h[i];
		}

		int single_rise_val = 0, single_rise_index = 0;
		vector<int> distributed_rise_new_h(n);

		solve(n, h, single_rise_val, single_rise_index, distributed_rise_new_h);

		cout << single_rise_val << " " << single_rise_index << endl;
		printVector(distributed_rise_new_h);
	}

	return 0;
}
