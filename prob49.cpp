#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>

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

bool samedigits(string s1, string s2, string s3) {

	for (int i = 0; i < s1.size(); ++i)
	{
		if (s2.find(s1.substr(i, 1)) == string::npos || s3.find(s1.substr(i, 1)) == string::npos) {
			return false;
		}
		s2.erase(s2.begin() + s2.find(s1.substr(i, 1)));
		s3.erase(s3.begin() + s3.find(s1.substr(i, 1)));
	}
	return true;
}

int main() {
	vector<int> primes;

	for (int i = 1001; i <= 9999; i+=2)
	{
		if (isprime(i)) {
			primes.push_back(i);
		}
	}

	for (int a = 0; a < primes.size(); ++a)
	{
		for (int b = a+1; b < primes.size(); ++b)
		{
			int c = (primes[b]-primes[a])+primes[b];
			if (c > 9999) {
				break;
			}
			if (isprime(c)) {
				if (samedigits(to_string(primes[a]), to_string(primes[b]), to_string(c))) {
					cout << primes[a] << primes[b] << c << endl;
				}
			}
		}
	}

	//cout << endl << endl << samedigits("9343", "9403", "9463");

}
