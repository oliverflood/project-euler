#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define ll long long
#define SIZE 100000

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

int main() {
	ll prime_count = 0;
	ll total_count = 0;	
	
	ll current_num = 1;

	for (int c = 2; c < SIZE; c+=2)
	{
		for (int i = 0; i < 4; ++i)
		{
			current_num += c;
			if (isprime(current_num)) {
				prime_count++;
			}
			total_count++;

		}
		if ((float)prime_count/(float)total_count < 0.1) {
			cout << "ans: " << c+1 << endl;
			break;
		}
	}
}
