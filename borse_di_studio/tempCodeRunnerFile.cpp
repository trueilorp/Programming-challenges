#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
ofstream outputFile("output.txt"); 

void stampa(int n){
    if (n==1){
        for (int i=1; i<=n/2; i++){
            outputFile << n-i << " " << n-(n-i) << endl;
        }
    }else{        
        //outputFile << stampa(n-1);
    }
}

int main(){
    ifstream file("input.txt");
    string line;
    getline(file, line);
    int n = stoi(line); // n is budget  

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            outputFile << i << " " << n-(n-i) << endl;
        }            
    }
}