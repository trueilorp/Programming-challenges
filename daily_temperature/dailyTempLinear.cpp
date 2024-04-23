#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 101;

#include <vector>
#include <stack>

vector<int> dailyTemperatures(const vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> answer(n, 0);
	stack<int> stack;

	for (int i = 0; i < n; ++i) {
		while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
			int prevIndex = stack.top();
			stack.pop();
			answer[prevIndex] = i - prevIndex;
		}
		stack.push(i);
	}

	return answer;
}

int main() {
	vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> result = dailyTemperatures(temp);
	int size = result.size();
	
	// Stampa dei risultati
	cout << "Risultati: ";
	for (int i = 0; i < size; i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}