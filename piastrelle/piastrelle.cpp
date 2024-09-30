// #include <iostream>
// #include <cassert>

// using namespace std;

// #define MAX_LENGTH 25
// long long piastrellature[MAX_LENGTH];

// long long piastrelle(int n){
// 	if (n <= 2){
// 		return n;
// 	}else{
// 		return piastrelle(n-1) + piastrelle(n-2);
// 	} 
// }

// long long piastrelleEff(long n){
// 	piastrellature[1] = 1;
// 	piastrellature[2] = 2;
// 	for (int i=3; i<=n; i++){
// 		piastrellature[i] = piastrellature[i-1] + piastrellature[i-2];
// 		cout << piastrellature[i] << " ";
// 	}
// 	return piastrellature[n];
// }

// int main(){
// 	long n;
// 	cin >> n;
// 	cout << piastrelleEff(n);
// 	return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 25
long long piastrellature[MAX_LENGTH];

long long nPiastrellature(long n){
	piastrellature[1] = 1;
	piastrellature[2] = 2;
	for (int i=3; i<=n; i++){
		piastrellature[i] = piastrellature[i-1] + piastrellature[i-2];
	}
	return piastrellature[n];
}

void calculateRanking(int u, vector<string> ranking, vector<string> ris) {
	for (int i = 0; i < u; i++){
		for (int j = 0; j < ris.size(); j++){
			if(ranking[i] == ris[j]){
				cout << j << endl;
				break;
			}
		}
	}
}

void calculateUnRanking(int u, vector<int> unranking, vector<string> ris) {
	for (int i = 0; i < u; i++){
		int rank_id = unranking[i];
		cout << ris[rank_id] << endl;
	}
}

void generateTileArrangements(vector<string>& arrangements, string current, int n) {
	if (n == 0) {
		arrangements.push_back(current);
		return;
	}

	generateTileArrangements(arrangements, current + "[]", n - 1);
	if (n >= 2) {
		generateTileArrangements(arrangements, current + "[--]", n - 2);
	}
}

int main(){
	int n_instances;
	cin >> n_instances;  // Read from standard input
	
	for (int i = 0; i < n_instances; i++){
	
		int n, c, r, u;  // Convert the input to an integer
		vector<int> inputs;
		for (int i = 0; i < 4; i++){
			cin >> inputs[i];
		}
		
		n = inputs[0];
		c = inputs[1];
		r = inputs[2];
		u = inputs[3];
		
		vector<string> ranking;
		vector<int> unranking;
		
		if(r != 0){
			for (int i = 0; i < r; i++){
				string x;
				cin >> x;
				ranking.push_back(x);
			}
		}
		
		if(u != 0){
			for (int i = 0; i < u; i++){
				int y;
				cin >> y;
				unranking.push_back(y);
			}
		}
		
		if(c == 1){
			cout << nPiastrellature(n);  // Call your piastrelle function (assuming it's implemented elsewhere)
		}
		
		vector<string> ris;
		generateTileArrangements(ris, "", n);  // Generate the tile arrangements (assuming the function is implemented elsewhere)
		sort(ris.begin(), ris.end(), greater<string>());  // Sort in descending order
		
		if(r != 0){
			calculateRanking(r, ranking, ris);
		}
		
		if(u != 0){
			calculateUnRanking(u, unranking, ris);
		}
	}
	
	return 0;
}