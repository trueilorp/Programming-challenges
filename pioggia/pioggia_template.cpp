#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// Funzione che risolve il problema
pair<long long, vector<int>> solve(int n, const vector<int>& H) {
	vector<int> A(n);  // Array per il nuovo panorama delle altezze
	long long Q = 0;   // Quantità totale di acqua intrappolata

	vector<int> mfl(n);  // Massimo da sinistra
	vector<int> mfr(n);  // Massimo da destra

	// Riempimento dell'array mfl (massimi da sinistra)
	mfl[0] = H[0];
	for (int i = 1; i < n; ++i) {
		mfl[i] = max(mfl[i - 1], H[i]);
	}

	// Riempimento dell'array mfr (massimi da destra)
	mfr[n - 1] = H[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		mfr[i] = max(mfr[i + 1], H[i]);
	}

	// Calcolo dell'acqua intrappolata e del nuovo panorama
	for (int i = 0; i < n; ++i) {
		A[i] = min(mfl[i], mfr[i]);
		Q += A[i] - H[i];
	}

	return {Q, A};
}

int main(int argc, char* argv[]) {
	int debug_level = 0;
	if (argc == 2) {
		debug_level = atoi(argv[1]);
	}

	int T;  // Numero di test case
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		if (debug_level > 0) {
			cerr << "#\n# Testcase " << t << ":\n";
		}

		int n;  // Lunghezza del vettore H
		cin >> n;
		assert(1 <= n && n <= 1000000);

		vector<int> H(n);  // Vettore delle altezze
		for (int i = 0; i < n; ++i) {
			cin >> H[i];
			assert(H[i] >= 0);
		}

		if (debug_level > 1) {
			cerr << "# n=" << n << "\n# H=";
			for (int i = 0; i < n; ++i) {
				cerr << H[i] << " ";
			}
			cerr << "\n";
		}

		// Chiamata alla funzione solve
		auto [Q, A] = solve(n, H);

		if (debug_level > 2) {
			cerr << "# Q=" << Q << ", A=";
			for (int i = 0; i < n; ++i) {
				cerr << A[i] << " ";
			}
			cerr << "\n";
		}

		// Output dei risultati
		cout << Q << "\n";
		for (int i = 0; i < n; ++i) {
			cout << A[i];
			if (i < n - 1) {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
