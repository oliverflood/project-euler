#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

bool ispalindrome(ll num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.at(i) != s.at(s.size()-1-i)) {
			return false;
		}
	}
	return true;
}

vector<bool> dec_to_bin(ll num) {
	vector<bool> bin;
	while (num != 0) {
		if (num % 2 == 0) {
			bin.push_back(0);
		}
		else {
			bin.push_back(1);
			num--;
		}
		num /= 2;
	}
	return bin;
}

bool doublepal(ll num) {
	vector<bool> temp = dec_to_bin(num);
	for (int i = 0; i < temp.size(); ++i)
	{
		if (temp[i] != temp[temp.size()-1-i]) {
			return false;
		}
	}
	return (ispalindrome(num));
}

int main() {

	ll sum = 0;
	
	for (int i = 1; i < 1000000; ++i)
	{
		if (ispalindrome(i)) {
			if (doublepal(i)) {
				sum += i;
			}
		}
	}

	cout << sum << endl;
	cout << ispalindrome(1) << endl;

}
