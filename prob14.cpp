#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define M 1000000

int collatz(int num, vector<bool> &visited) {
	int ans = 1;
	long long n = num;
	while (n > 1) {
		if (n % 2 == 0) {
			n = (n/2);
		}
		else {
			n = (n*3) + 1;
		}
		ans++;

		if (n > 1 && n < visited.size()-1) {
			visited[n] = 1;
		}
	}
	return ans;
}

int main() {
	vector<bool> visited;
	int ans = 0;
	int actual = 0;

	for (int i = 0; i < M; ++i)
	{
		visited.push_back(false);
	}
	visited[1] = 1;

	// cout << "size: " << visited.size() << endl;
	// cout << "test: " << collatz(13, visited) << endl;

	vector<int> answers;
	int count = 0;

	for (int i = M-1; i > 1; --i)
	{
		if (i % (M/10) == 0) {
			cout << i << endl;
		}

		if (true) {//!visited[i]
			count++;
			int temp = collatz(i, visited);
			answers.push_back(temp);
			if (temp > ans) {
				ans = temp;
				actual = i;
				cout << "new answer: " << ans << " " << actual << endl;
			}
		}
		// not needed
		visited[i] = 1;
	}

	sort(answers.begin(), answers.end());
	for (int i = answers.size()-10; i < answers.size(); ++i)
	{
		cout << answers[i] << endl;
	}


	cout << "Count: " << count << endl;
	cout << "Longest sequence: " << ans << endl;
	cout << "Number which produced it: " << actual << endl;
}

