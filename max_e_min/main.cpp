#include <iostream>
#include <sstream>
#include <vector>

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

int main() {
    vector<int> numbers;

    // Leggi i numeri da cin
    cout << "Inserisci una sequenza di numeri: ";
    cin >> numbers;

    // Stampa i numeri
    cout << "I numeri inseriti sono: " << numbers << endl;

    return 0;
}
