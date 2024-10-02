#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

int DEBUG_LEVEL = 0;

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

vector<int> get_doomed(vector<string>& guelfis, int n) {
	vector<int> doomed(n, 0);  // Replace with the actual logic
	countsWB counts_white_black = countWhiteBlack(n, guelfis); 
	
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
	return doomed;
}

vector<int> save_Ryan(vector<string>& guelfis, int n, int soldato_ryan_index) {
	vector<int> plan4Ryan(n, 0);  // Replace with the actual logic

	plan4Ryan[soldato_ryan_index] = -1;
	countsWB counts_white_black = countWhiteBlack(n, guelfis);
	
	vector<vector<int>> guelfis_befor = counts_white_black.counts_before;
	vector<vector<int>> guelfis_after = counts_white_black.counts_after;
	int nBlackBefor = guelfis_befor[0][soldato_ryan_index];
	int nWhiteBefor = guelfis_befor[1][soldato_ryan_index];
	int nBlackAfter = guelfis_after[0][soldato_ryan_index];
	int nWhiteAfter = guelfis_after[1][soldato_ryan_index];
	
	int time_limit_sx = nBlackBefor;
	int current_time_sx = 0;
	int jump = 1;
	
	// Inserisco gli O per i Defunti
	for (int i = 0; i < n; i++){
		if(guelfis[i] == "D"){
			plan4Ryan[i] = 0;
		}
	}
	
	// Scorro l'array a sx		
	while (current_time_sx != time_limit_sx){
		for (int i = soldato_ryan_index - 1; i >= jump; i--){
			if((guelfis[i] != "-") && (guelfis[i - jump] != "-") && (guelfis[i] != "D") && (guelfis[i - jump] != "D")){
				if(guelfis[i] != guelfis[i - jump]){
					current_time_sx++;
					plan4Ryan[i] = current_time_sx;
					plan4Ryan[i - jump] = current_time_sx;
					guelfis[i] = "-";
					guelfis[i - jump] = "-";
				}
			}
		}
		jump++;
	}
	
	jump = 1;
	int current_time_dx = current_time_sx;
	int time_limit_dx = nBlackAfter + current_time_sx;
	
	// Scorro l'array a dx
	while (current_time_dx != time_limit_dx){
		for (int i = soldato_ryan_index + 1; i < n - jump; i++){
			if((guelfis[i] != "-") && (guelfis[i + jump] != "-") && (guelfis[i] != "D") && (guelfis[i + jump] != "D")){
				if(guelfis[i] != guelfis[i + jump]){
					current_time_dx++;
					plan4Ryan[i] = current_time_dx;
					plan4Ryan[i + jump] = current_time_dx;
					guelfis[i] = "-";
					guelfis[i + jump] = "-";
				}
			}
		}
		jump++;
	}
	
	return plan4Ryan;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		if (DEBUG_LEVEL > 0) {
			cerr << "#\n# Testcase " << t << ":" << endl;
		}

		int n;
		cin >> n;
		vector<string> c(n);
		
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
			assert(c[i] == "B" || c[i] == "N" || c[i] == "D");
		}
		
		int y;
		cin >> y;

		if (DEBUG_LEVEL > 1) {
			cerr << "# n=" << n << ", y=" << y << "\n# c=";
			for (auto& el : c) {
				cerr << el << " ";
			}
			cerr << endl;
		}

		vector<int> doomed = get_doomed(c, n);
		// vector<int> plan4Ryan(n);
		// for (int i = 0; i < n; i++){
		// 	plan4Ryan[i] = i+1;
		// }
		
		vector<int> plan4Ryan = save_Ryan(c, n, y);
		
		ostream* fouts[] = {&cout};
		if (DEBUG_LEVEL > 1) {
			fouts[0] = &cerr;
			fouts[1] = &cout;
		}

		for (auto& fout : fouts) {
			for (int val : doomed) {
				*fout << val << " ";
			}
			*fout << endl;

			for (const auto& str : c) {
				*fout << str << " ";
			}
			*fout << endl;

			for (int val : plan4Ryan) {
				*fout << val << " ";
			}
			*fout << endl;
		}
		
		doomed.clear();
		plan4Ryan.clear();
		
	}

	return 0;
}