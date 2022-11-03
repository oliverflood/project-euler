#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool isprime(long long num) {
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

vector<int> coprimes(int num) {
	vector<int> ans;
	for (int i = 1; i < num; ++i)
	{
		if (__gcd(i, num) == 1) {
			ans.push_back(i);
		}
	}
	return ans;
}

int carmichael(int num) {
	vector<int> c = coprimes(num);

	for (int i = 1; i < num; ++i)
	{
		bool t = true;
		for (int k = 0; k < c.size(); ++k)
		{
			if ((long long)pow(c[k], i) % num != 1) {
				t = false;
			}
		}
		if (t) {
			return i;
		}
	}
	return -1;
}

int main() {
	for (int i = 1; i < 40; ++i)
	{
		cout << i << ": " << carmichael(i) << ":   ";
		vector<int> c = coprimes(i);
		for (int k = 0; k < c.size(); ++k)
		{
			cout << c[k] << " ";
		}
		cout << endl;
		// cout << i << " " << carmichael(i) << endl;
	}

	cout << endl << endl << endl << __gcd(15, 70) << endl;
}

// 983
// THIS PROGRAM'S CARMICHAEL FUNCTION DOESN'T WORK
// https://en.wikipedia.org/wiki/Carmichael_function#Computing_%CE%BB(n)_with_Carmichael's_theorem
// ^do this here or something
// this problem was hard