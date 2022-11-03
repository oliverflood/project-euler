#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;
#define ll long long

bool digitsum(ll num) {
	ll ans = 0;
	string n = to_string(num);
	for (int i = 0; i < n.size(); ++i)
	{
		ans += pow((n.at(i)-'0'), 5);
	}

	return (ans == num);
}

int main() {
	ll sum = 0;

	//conjuecture: go to 100k
	for (int i = 2; i < 100000; ++i)
	{
		if (digitsum(i)) {
			cout << i << endl;
			sum += i;
		}
	}

	cout << "ans: " << sum << endl << endl;


	vector<string> a;
	a = new string(13);

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << endl;
	}

}
