#include <iostream>
#include <vector>

using namespace std;

int orderOfLargestPlusSignAux(int n, vector<vector<int>>& mines, int order) {
	if (n < 3){
		return order;
	}else{
		if(){  // sulla croce ci sono degli zeri, ricorsione indietro e basta
			order = 0;
			return orderOfLargestPlusSignAux(n-1, mines, order);
		}else{ // conta 1
			return orderOfLargestPlusSignAux(n-1, mines, order+1);
		}
		
	}
}
	
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
	orderOfLargestPlusSignAux(n, mines, 0);
}
	
int main(){
	int n = 5;
	vector<vector<int>> mines;
	mines.push_back([4,2]);
	
	
}