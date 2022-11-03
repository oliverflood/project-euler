#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}

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

ll permutation(int n, int address) {
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

	string s = "";

	for (int i = 0; i < ans.size(); ++i)
	{
		s = s + to_string(ans[i]);
	}

	return stoll(s);
}

bool divisible(ll num) {
	string s = to_string(num);
	vector<int> primes = {2,3,5,7,11,13,17};

	for (int i = 1; i <= 7; ++i)
	{
		// cout << stoi(s.substr(i, 3)) << " % " << primes[i-1] << endl;
		if (stoi(s.substr(i, 3)) % primes[i-1] != 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ll ans = 0;
	ll sum = 0;

	for (int i = 0; i <= factorial(10); ++i)
	{
		if (permutation(10, i) == 1406357289) {
			cout << "WOWWW " << permutation(10, i) << endl;
		}
		if (divisible(permutation(10, i))) {
			ans++;
			sum += permutation(10, i);
			cout << permutation(10, i) << endl;
		}
	}

	//cout << divisible(1406357289);

	cout << "ans: " << ans << endl;
	cout << "sum: " << sum << endl;
	
}
