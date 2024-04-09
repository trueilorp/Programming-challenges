#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
ofstream outputFile("output.txt"); 

int stampa(int n, int i, int ris){
    if (i==n){
        return i;
    }else{     
        for (int j=1; j<=n; j++){
            return 1 + stampa(n, i+1, ris);
        }        
    }
}

int main(){
    ifstream file("input.txt");
    string line;
    getline(file, line);
    int n = stoi(line); // n is budget  
    cout << stampa(n,1,0);
}