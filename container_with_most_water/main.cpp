#include <iostream>
#include <vector>
#include <random>

using namespace std;
const int N = 1000;

int max_water(vector<int> heights){
	
}

int main(){
	
	int size = N;
	vector<int> heights(size, 0);
	
	random_device rd; 
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);

	for(int i = 0; i < size; ++i) {
		heights[i] = distrib(gen);
		// cout << heights[i] << " ";
	}
	
	int result = max_water(heights);
	cout << result;
	return 0;
}