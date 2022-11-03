#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

bool pandigital(string s) {
	for (int i = 1; i < 9; ++i)
	{
		if (s.find(to_string(i)) == string::npos) {
			return false;
		}
	}
	return true;
}

bool isprime(ll num) {
	if (num <= 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	for (ll i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}

ll permutation(int n, int address) {
	vector<int> digits;
	for (int i = 1; i <= n; ++i)
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

	string s = "";

	for (int i = 0; i < ans.size(); ++i)
	{
		s = s + to_string(ans[i]);
	}

	return stoll(s);
}

int main() {
	
	for (int a = 9; a >= 2; --a)
	{
		for (int i = factorial(a); i >= 0; --i)
		{
			if (isprime(permutation(a, i))) {
				cout << "ans: " << 	permutation(a, i) << endl;
				exit(1);
			}
		}
	}

}
