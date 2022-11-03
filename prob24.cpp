#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}

vector<int> permutation(int n, int address) {
	vector<int> digits;
	for (int i = 0; i < n; ++i)
	{
		digits.push_back(i);
	}
	n--;

	vector<int> ans;
	int current = 0;
	int count = 0;
	while (true) {
		if (current + factorial(n) >= address) {
			ans.push_back(digits[count]);
			digits.erase(digits.begin()+count);
			count = 0;
			n--;
			if (n == 0) {
				ans.push_back(digits[0]);
				break;
			}
			continue;
		}
		current += factorial(n);
		count++;
	}

	return ans;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
	}
	cout << endl;
}

int main() {

	vector<int> ans = permutation(10, 1000000);
	print(ans);

	// for (int i = 1; i <= 24; ++i)
	// {
	// 	vector<int> ans = permutation(4, i);
	// 	print(ans);
	// }
}
