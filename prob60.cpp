#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

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

bool remarkable(vector<ll> v) {
	for (int i = 0; i < v.size()-1; ++i)
	{
		for (int j = i+1; j < v.size(); ++j)
		{
			if (j != i) {
				if (!isprime(stoll(to_string(v[i]) + to_string(v[j])))) {
					return false;
				}
				if (!isprime(stoll(to_string(v[j]) + to_string(v[i])))) {
					return false;
				}
			}
		}
	}
	return true;
}

#define SIZE 10000
int main() {
	
	vector<ll> primes;

	for (int i = 3; i < SIZE; ++i)
	{
		if (isprime(i)) {
			primes.push_back(i);
		}
	}

	// probably could be improved...

	for (int a = 0; a < primes.size(); ++a)
	{
		for (int b = a+1; b < primes.size(); ++b)
		{
			vector<ll> temp = {primes[a], primes[b]};
			if (!remarkable(temp)) {
				continue;
			}
			for (int c = b+1; c < primes.size(); ++c)
			{
				vector<ll> temp = {primes[a], primes[b], primes[c]};
				if (!remarkable(temp)) {
					continue;
				}
				for (int d = c+1; d < primes.size(); ++d)
				{
					vector<ll> temp = {primes[a], primes[b], primes[c], primes[d]};
					if (!remarkable(temp)) {
						continue;
					}
					for (int e = d+1; e < primes.size(); ++e) 
					{
						//cout << primes[a] << " " << primes[b] << " " << primes[c] << " " << primes[d] << " " << primes[e] << endl;
						vector<ll> temp = {primes[a], primes[b], primes[c], primes[d], primes[e]};
						if (remarkable(temp)) {
							cout << "ans: " << (primes[a]+primes[b]+primes[c]+primes[d]+primes[e]) << endl;
							cout << primes[a] << " " << primes[b] << " " << primes[c] << " " << primes[d] << " " << primes[e] << endl;
						}
					}
				}
			}
		}
	}
}
