#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

struct countsWB
{
	vector<vector<int>> counts_before;
	vector<vector<int>> counts_after;
};

void printMatrix(int n, vector<vector<int>>& result, string s){
	cout << s << endl;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << result[i][j] << " ";  // Print each element with a space
		}
		cout << endl;  // New line at the end of each row
	}
}

void printArray(int n, vector<int>& array){
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";  // Print each element with a space
	}
	cout << endl;  // New line at the end of each row
}

countsWB countWhiteBlack(int n, vector<string>& guelfis) {
	countsWB counts;
	counts.counts_before.resize(2, vector<int>(n, 0)); 
	counts.counts_after.resize(2, vector<int>(n, 0));

	int count_white = -1;
	int count_black = -1;

	for (int i = 0; i < n; i++) {
		counts.counts_before[0][i] = count_black + 1;
		counts.counts_before[1][i] = count_white + 1;
		if(guelfis[i] == "N"){ // incremento i neri
			count_black++;
		}else if (guelfis[i] == "D"){
			counts.counts_before[0][i] = -1;
			counts.counts_before[1][i] = -1;
		}else{ // incrementi i bianchi
			count_white++;
		}
	}
	
	count_white = -1;
	count_black = -1;

	for (int i = n-1; i >= 0; i--) {
		counts.counts_after[0][i] = count_black + 1;
		counts.counts_after[1][i] = count_white + 1;
		if(guelfis[i] == "N"){ // incremento i neri
			count_black++;
		}else if (guelfis[i] == "D"){
			counts.counts_after[0][i] = -1;
			counts.counts_after[1][i] = -1;
		}else{ // incrementi i bianchi
			count_white++;
		}
	}
	
	return counts;
}

void get_doomed(vector<string>& guelfis, int n){
	vector<int> doomed(n);
	countsWB counts_white_black = countWhiteBlack(n, guelfis); 
	
	printMatrix(n, counts_white_black.counts_before, "BEFORE");
	printMatrix(n, counts_white_black.counts_after, "AFTER");
	
	cout << endl << endl;
	for (int i = 0; i < n; i++){
		if(guelfis[i] == "D"){
			doomed[i] = 1;
		}else{
			if( (counts_white_black.counts_before[0][i] == counts_white_black.counts_before[1][i]) && 
				(counts_white_black.counts_after[0][i] == counts_white_black.counts_after[1][i]) ){
				doomed[i] = 0;
			}else{
				doomed[i] = 1;
			}
		}
	}
	
	printArray(n, doomed);	
}

int main(){
	int n_instances;
	cin >> n_instances;
	for (int i = 0; i < n_instances; i++){
		int n, soldato_ryan;
		cin >> n;
		vector<string> guelfis(n);
		for (int i = 0; i < n; i++){
			cin >> guelfis[i];
		}
		cin >> soldato_ryan;
		get_doomed(guelfis,n);
		
		// Print guelfis
		for (int i = 0; i < n; i++) {
			cout << guelfis[i] << " "; 
		}
		cout << endl; 
	}		
	return 0;
}
