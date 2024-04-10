#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

ostream &operator << (ostream &out, const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

istream &operator >> (istream &in, vector<int> &vec) {
    // scan line of text 
    string line;
    getline(in, line);

    // convert line of text into a new input stream
    istringstream is(line);
    
    // convert new input stream into array
    int value;
    while (is >> value)
        vec.push_back(value);

    return in;
}

int findNum(vector<int> numbers){
    int ris=-1;
    bool check = false;
    for (int i = 0; i < numbers.size(); i++){
        for (int j = 0; j < numbers.size(); j++){
            if(j < i){ // If j is less than i
                if((numbers[i] >= numbers[j]) && (check == false)){
                    ris = i;
                }else{
                    check = true;
                }
            }else{ // If j is greater than or equal to i
                if((numbers[j] >= numbers[i]) && (check == false)){
                    ris = i;
                }
                else{
                    check = true;
                }
            }
        }
        if (check == false){
            return ris;
        }else{
            check = false;
            ris = -1;
        }
    }
    return -1;
}

int main() {
    vector<int> numbers;

    ifstream file("input.txt");
    ofstream outputFile("output.txt");
    string line;

    while (getline(file, line)) {
        istringstream lineStream(line);
        int num;
        while (lineStream >> num) {
            numbers.push_back(num);
        }
        int ris = findNum(numbers);
        outputFile << ris << endl;
        numbers.clear();
    }
    
    return 0;
}
