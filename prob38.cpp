#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

bool pandigital(string s) {
	for (int i = 1; i < 9; ++i)
	{
		if (s.find(to_string(i)) == string::npos) {
			return false;
		}
	}
	return true;
}

string product(int num) {
	string s = "";
	int c = 1;
	while (s.size() < 9) {
		s = s + to_string(num*c);
		c++;
	}
	return s;
}

int main() {
	int ans;

	for (int i = 1; i < 9999; ++i)
	{
		string p = product(i);
		if (pandigital(p)) {
			cout << i << "  " << product(i) << endl;
			if (stoll(p) > ans) {
				ans = stoll(p);
			}
		}	
	}

	cout << "ans: " << ans;
}

// make list of all 9 digit pandigitals
