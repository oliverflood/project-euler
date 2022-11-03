#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

bool triangle(ll n) {
	ll a = floor(sqrt(n*2));
	cout << "  n: " << n << "  a: " << a << endl;
	if ((ll)(a*(a+1)/2) == n) {
		return true;
	}
	return false;
}

bool pentagonal(ll n) {
	ll a = ceil((double)sqrt(((n*2)/3)));
	if ((ll)((a*(3*a-1))/2) == n) {
		return true;
	}
	return false;
}

int main() {
	ll hex;
	int c = 0;

	// cout << pentagonal(40755) << " " << triangle(40755) << endl;

	// for (int i = 0; i < 100; ++i)
	// {
	// 	if (triangle(i)) {
	// 		cout << i << endl;
	// 	}
	// }

	for (int i = 1; i < 100000; ++i)
	{
		hex = i*(2*i-1);
		if (triangle(hex) && pentagonal(hex)) {
			cout << hex << endl;
			if (c) {
				break;
			}
			c++;
		}
	}

}
