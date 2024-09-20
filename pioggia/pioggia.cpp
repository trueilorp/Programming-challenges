#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

vector<int> findMaxLeft(const vector<int>& H, int n){
	vector<int> maxArray(n);
	int max = H[0];
	maxArray[0] = max;
	
	for (int i = 1; i < n; i++){
		if(H[i] > max){
			max = H[i];
			maxArray[i] = max;
		}else{
			maxArray[i] = max;
		}
	} 

	return maxArray;
}

vector<int> findMaxRight(const vector<int>& H, int n){
	vector<int> maxArray(n);
	int max = H[n-1];
	maxArray[n-1] = max;
	
	for (int i = n-2; i >= 0; i--){
		if(H[i] > max){
			max = H[i];
			maxArray[i] = max;
		}else{
			maxArray[i] = max;
		}
	} 

	return maxArray;
}

void solve(int n, const vector<int>& H, int& Q, vector<int>& A) {
	vector<int> leftMax = findMaxLeft(H, n);
	vector<int> rightMax = findMaxRight(H, n);
	
	for (int i = 0; i < n; i++){
		if(leftMax[i] < rightMax[i]){
			A.push_back(leftMax[i]);
			if(H[i] != A[i]){
				Q += abs(H[i] - A[i]);
			}
		}else{
			A.push_back(rightMax[i]);
			if(H[i] != A[i]){
				Q += abs(H[i] - A[i]);
			}
		}
	}
}

int main(int argc, char** argv) {
	int debug_level = 0;
	if (argc == 2) {
		debug_level = atoi(argv[1]);  // Convert argument to integer
	}
	
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		if (debug_level > 0) {
			cerr << "#" << endl << "# Testcase " << t << ":" << endl;
		}
		
		int n;
		cin >> n;
		assert(1 <= n && n <= 1000000);
		
		vector<int> H(n);
		for (int i = 0; i < n; ++i) {
			cin >> H[i];
			assert(H[i] >= 0);
		}
		
		if (debug_level > 1) {
			cerr << "# n=" << n << endl;
			cerr << "# H=[";
			for (int i = 0; i < n; ++i) {
				cerr << H[i] << (i < n - 1 ? ", " : "");
			}
			cerr << "]" << endl;
		}
		
		int Q = 0;
		vector<int> A;
		solve(n, H, Q, A);
		
		if (debug_level > 2) {
			cerr << "# Q=" << Q << ", A=[";
			for (int i = 0; i < n; ++i) {
				cerr << A[i] << (i < n - 1 ? ", " : "");
			}
			cerr << "]" << endl;
		}
		
		cout << Q << endl;
		for (int i = 0; i < n; ++i) {
			cout << A[i] << (i < n - 1 ? " " : "\n");
		}
	}
	
	return 0;
}
