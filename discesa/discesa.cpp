#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
vector<int> values;
vector<vector<int>> arrays;
vector<int> maxs;

void applyMax(int z){
    z++;
    int length = arrays[z].size();
    for (int i=0; i<length; i++){
        arrays[z][i] += maxs[i];
    }
}

void discesaMassima(int height){
    int i=0, j=1;
    for (int z=0; z<height; z++){
        int length = arrays[z].size();
        while(j<length){
            if(arrays[z][i] > arrays[z][j]){
                maxs.push_back(arrays[z][i]);
            }else{
                maxs.push_back(arrays[z][j]);
            }
            i++;
            j++;
        }
        applyMax(z);
        maxs.clear();
        i=0;
        j=1;
    }
}

int main(){
    ifstream file("input.txt");
    string line;
    getline(file, line);
    int n = stoi(line); // n is the height of the tree 

    while (getline(file, line)) {
        istringstream lineStream(line);
        vector<int> array;
        int num;
        while (lineStream >> num) {
            array.push_back(num);
        }
        arrays.insert(arrays.begin(), array); 
    }

    discesaMassima(n);
    int ris = arrays[n-1][0];
    ofstream outputFile("output.txt");
    outputFile << ris;
}
