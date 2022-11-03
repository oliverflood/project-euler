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

ll rotate(ll num) { // 123 -> 312
	string s = to_string(num);
	string s1 = s.substr(s.size()-1, 1);
	s.erase(s.size()-1, 1);
	s = s1 + s;
	return stoll(s);
}

bool prime_rotations(ll num) {

	for (int i = 0; i < to_string(num).size(); ++i)
	{
		if (!isprime(num)) {
			return false;
		}
		num = rotate(num);
	}

	return true;
}

int main() {
	int count = 0;

	for (int i = 2; i < 1000000; ++i)
	{
		if (prime_rotations(i)) {
			count++;
		}
	}

	cout << count << endl;
}
