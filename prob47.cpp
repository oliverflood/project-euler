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

vector<int> prime_factorize(int n) {
	vector<int> pfactors;

	while (true) {
		for (int i = 2; i <= n; ++i)
		{
			if (isprime(i)) {
				if (n % i == 0) {
					n = n/i;
					pfactors.push_back(i);
					break;
				}
			}
		}
		if (isprime(n)) {
			pfactors.push_back(n);
			break;
		}
		if (n == 1) {
			break;
		}
	}

	set<int> kill;
	for (int i = 0; i < pfactors.size(); ++i)
	{
		kill.insert(pfactors[i]);
	}

	vector<int> ans(kill.begin(), kill.end());

	return ans;
}

int prime_factor_count(int n) {
    vector<int> factors;

    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n/i;
        }
    }

    if (n > 2) 
    	factors.push_back(n);

    set<int> kill;
	for (int i = 0; i < factors.size(); ++i)
	{
		kill.insert(factors[i]);
	}

	vector<int> ans(kill.begin(), kill.end());

	return ans.size();
}

int main() {
	
	vector<int> test;

	test = prime_factorize(9871);

	for (int i = 3; i < 999999; ++i)
	{
		// cout << i << "    "; 
		// if (prime_factor_count(i) == 3) {
		// 	cout << "### ";
		// }
		for (int a = 0; a < 4; ++a)
		{
			int s = prime_factor_count(i+a);
			if (s != 4) {
				break;
			}
			if (a==3) {
				cout << i << endl;
				exit(1);	
			}
		}
	}
}
