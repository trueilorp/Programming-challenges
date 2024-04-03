#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    vector<vector<int>> triangle(n);

    // Reading the triangle
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1); // Resize the vector for the current row
        cout << "Enter " << (i + 1) << " integers for row " << (i + 1) << ": ";
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    // Outputting the triangle (just to verify)
    cout << "Triangle:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
