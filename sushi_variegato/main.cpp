#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numeroTagliAux(int n, int i, int tagliere[]) {
    if (i == n) {
        return 1;
    } else {
        if (tagliere[i] == tagliere[i + 1]) {
            return 2 * numeroTagliAux(n, i + 1, tagliere);
        } else {
            return numeroTagliAux(n, i + 1, tagliere);
        }
    }
}

int taglia(int n, int tagliere[]) {
    return numeroTagliAux(n, 0, tagliere); // Inizia da 0 invece di 1
}

int main() {
    ifstream file("input.txt");
    int n;
    file >> n; // Leggi la lunghezza dell'array

    int* tagliere = new int[n]; // Allocazione di un array di dimensione n

    for (int i = 0; i < n; ++i) {
        file >> tagliere[i]; // Leggi gli elementi dell'array uno per uno
    }

    file.close();

    ofstream outputFile("output.txt");
    outputFile << taglia(n, tagliere); // Passa l'array di interi alla funzione taglia


    return 0;
}
