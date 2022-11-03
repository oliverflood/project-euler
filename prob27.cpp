#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ll long long

bool isprime(long long num) {
	if (num < 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	if (num == 1) {
		return false;
	}
	for (int i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int sequence(int a, int b) {
	int c = 0;

	while (true) {
		//cout << (isprime(pow(c, 2) + (a*(c)) + b)) << "  " << c << "  " << (pow(c, 2) + (a*(c)) + b) << endl;
		if (!isprime(pow(c, 2) + (a*(c)) + b)) {
			break;
		}
		c++;
	}

	return c;
}

int main() {
	vector<int> primes;

	ll ans = 0;

	int af;
	int bf;

	for (int i = 1; i < 1000; ++i)
	{
		if (isprime(i)) {
			cout << i << endl;
			primes.push_back(i);
			//primes.push_back(-i);
		}
	}




	//ans = sequence(-79, 1601);

	for (int a = -999; a < 1000; ++a)
	{
		for (int b = 0; b < primes.size(); ++b)
		{
			long long temp = sequence(a, primes[b]);
			if (temp > ans) {
				cout << "new " << temp << endl;
				ans = temp;
				af = a;
				bf = primes[b];
			}
		}
	}

	cout << "product: " << (af*bf) << "  a: " << af << "   b: " << bf << "  ans: " << ans << endl;
}


//-60939

// -10329

//-3171