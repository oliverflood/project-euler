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

bool psquare(ll num) {
	for (int i = 1; i < (int)sqrt(num); ++i)
	{
		//cout << " num: " << num << "  i: " << i << "   x: " << (num-pow(i, 2)) << endl;
		if (isprime(num-2*pow(i, 2))) {
			return true;
		}
	}
	return false;
}

int main() {
	
	for (int i = 9; i < 100000; i+=2)
	{
		if (!isprime(i) && !psquare(i)) {
			cout << i << endl;
			break;
		}
	}

}
