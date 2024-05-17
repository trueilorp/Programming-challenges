#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
const int SIZE = 10000;

int findMax(int *numbers, int n)
{
	int max_value = numbers[0];
	for (int i = 1; i < n; ++i)
	{
		if (numbers[i] > max_value)
		{
			max_value = numbers[i];
		}
	}
	return max_value;
}

int dieta_poldo(int n, int *numbers)
{
	int *counters = new int[n];
	// Inizializzo gli tutti gli elementi a 1
	for (int i = 0; i < n; ++i)
	{
		counters[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		int max_parz = 0;
		for (int k = i - 1; k >= 0; k--)
		{
			if (numbers[k] > numbers[i])
			{
				max_parz = max(counters[k], max_parz);
			}
		}
		counters[i] += max_parz;
	}
	return findMax(counters, n);
}

int main()
{
	ifstream inputFile("input.txt");

	int N;
	inputFile >> N;

	int *panini = new int[N];

	for (int i = 0; i < N; ++i)
	{
		inputFile >> panini[i];
	}

	inputFile.close();

	ofstream outputFile("output.txt");

	if (N == 0)
	{
		outputFile << N;
	}
	if (N == 1)
	{
		outputFile << N;
	}
	outputFile << dieta_poldo(N, panini);

	// Rilascio della memoria allocata
	delete[] panini;

	return 0;
}
