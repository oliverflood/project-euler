#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

string snip(string s) {
	if (s.size() <= 10)
		return s;
	s = s.substr(s.size()-10, 10);
	return s;
}

ll power(ll n) {
	string ans = snip(to_string(n*n));

	if (n == 1)
		return 1;
	if (n == 2)
		return 4;


	for (int i = 0; i < n-2; ++i)
	{
		ll next = n*stoll(ans);

		ans = snip(to_string(next));

		//ans = snip(to_string(stoi(ans) + stoi(str)));
		//cout << "ans: " << ans << endl;
	}

	return stoll(ans);
}

int main() {
	ll ans = 0;

	for (int i = 1; i <= 1000; ++i)
	{
		ans += power(i);
		ans = stoll(snip(to_string(ans)));
	}
	
	cout << ans << endl;
}
