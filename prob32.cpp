#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

bool pandigital_triple(int a, int b, int c) {
	string s = to_string(a) + to_string(b) + to_string(c);

	for (int i = 1; i <= 9; ++i)
	{
		if (s.find_first_of('0'+i) == string::npos) {
			return false;
		}
	}

	return true;
}

bool pandigital_product(int num) {
	// technically only needs to run up to sqrt(num)
	
	for (int i = 1; i <= num; ++i) 
	{
		if (num % i == 0) {
			if (pandigital_triple(num, i, num / i)) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int n = 0;
	int ans = 0;

	for (int i = 1111; i <= 9999; ++i)
	{
		if (pandigital_product(i)) {
			n++;
			ans += i;
		}
	}

	cout << n << endl;
	cout << ans << endl;
}
