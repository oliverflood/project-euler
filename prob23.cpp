#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;

#define MAX 28123

// technically proper divisor sum
int divisor_sum(int n) {
	if (n == 1 || n == 2) {return 1;}
	int sum = 1;
	for (int i = 2; i < n; ++i) // inefficient
	{
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

bool is_abundant(int n) {
	if (divisor_sum(n) > n) {
		return true;
	}
	return false;
}

int main() {
	vector<bool> v(MAX+1, 0);
	vector<int> abundant_numbers;

	for (int i = 1; i <= MAX; ++i)
	{
		if (is_abundant(i)) {
			abundant_numbers.push_back(i);
		}
	}

	for (int i = 0; i < abundant_numbers.size(); ++i)
	{
		for (int j = 0; j < abundant_numbers.size(); ++j)
		{
			if (abundant_numbers[i]+abundant_numbers[j] < v.size()) {
				v[abundant_numbers[i]+abundant_numbers[j]] = 1;
			}
		}
	}

	// for (int i = 0; i < abundant_numbers.size(); ++i)
	// {
	// 	cout << abundant_numbers[i] << endl;
	// }

	cout << v.size() << endl;
	long long ans = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (!v[i]) {
			cout << i << endl;
			ans += i;
		}
	}

	cout << "test" << endl << endl;
	cout << is_abundant(MAX) << endl;
	cout << v[MAX];
	cout << endl << endl;
	cout << "ans: " << ans << endl;

	cout << "abundant_numbers: " << endl;
	for (int i = 0; i < 28; ++i)
	{
		cout << abundant_numbers[i] << endl;
	}
}
// not 4177821