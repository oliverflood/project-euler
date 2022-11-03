#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

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

bool truncatable(ll num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); ++i)
	{
		string substring = s.substr(i);
		//cout << substring << endl;
		if (!isprime(stol(substring))) {
			return false;
		}
	}
	for (int i = 0; i < s.size(); ++i)
	{
		string substring = s.substr(0, s.size()-i);
		//cout << substring << endl;
		if (!isprime(stol(substring))) {
			return false;
		}
	}
	return true;
}

int main() {
//300073
	ll sum = 0;
	int count = 0;

	for (int i = 9; i < 1000000; i+=2)
	{
		if (isprime(i) && truncatable(i)) {
			sum += i;
			cout << i << endl;
			count++;
		}
	}

	cout << sum << endl;
	cout << count << endl;

}
