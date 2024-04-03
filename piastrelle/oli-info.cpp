#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 25
long long piastrellature[MAX_LENGTH];

long long piastrelle(long n){
    piastrellature[1] = 1;
    piastrellature[2] = 2;
    for (int i=3; i<=n; i++){
        piastrellature[i] = piastrellature[i-1] + piastrellature[i-2];
    }
    return piastrellature[n];
}

void generateTileArrangements(vector<string>& arrangements, string current, int n) {
    if (n == 0) {
        arrangements.push_back(current);
        return;
    }

    generateTileArrangements(arrangements, current + "[O]", n - 1);
    if (n >= 2) {
        generateTileArrangements(arrangements, current + "[OOOO]", n - 2);
    }
}

int main(){
    ifstream file("input.txt");
    string line;
    getline(file, line);
    int n = stoi(line);
    int combinazioni = piastrelle(n);

    vector<string> ris;
    generateTileArrangements(ris, "", n);
    sort(ris.begin(), ris.end(), greater<string>());
    
    ofstream outputFile("output.txt");
    for (const auto& arrangement : ris) {
        outputFile << arrangement << std::endl;
    }
    
    return 0;
}