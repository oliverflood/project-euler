#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

bool palindrome (string s) {
	int size = s.size();

	for (int i = 0; i < s.size(); ++i)
	{
		if (s.at(i) != s.at(size-1-i))
			return false;
	}

	return true;
}

string vtos(vector<int> v) {
	string s = "";
	for (int i = 0; i < v.size(); ++i)
	{
		s += to_string(v[i]);
	}
	return s;
}

string add(string s1, string s2) {
	vector<int> v;
	for (int i = 0; i < max(s1.size(), s2.size())+1; ++i)
	{
		v.push_back(0);
	}

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	//cout << s1 << "  " << s2 << "   " << max(s1.size(), s2.size()) << endl;

	int carry = 0;
	for (int i = 0; i < max(s1.size(), s2.size()); i++)
	{
		int add = carry;
		carry = 0;
		if (i < s1.size()) {
			add += s1.at(i)-'0';
		}
		if (i < s2.size()) {
			add += s2.at(i)-'0';
		}

		carry = add/10;
		v[i] = add%10;
		//cout << "i:" << i << "   carry: " << carry << "   add: " << add << endl;
	}
	if (carry != 0)
		v[v.size()-1] = carry;
	else 
		v.erase(v.begin()+v.size()-1);
	//v.end() works too i think
	// last digit if there is one

	reverse(v.begin(), v.end());

	return vtos(v); // very dumb but gets rid of leading zeroes lol
}

// lychrel means it never becomes a palindrome
// returns true if num is a lychrel
bool lychrel(ll num) {
	string s = to_string(num);
	for (int i = 0; i < 50; ++i)
	{
		string rev = s;
		reverse(rev.begin(), rev.end());
		//cout << " s: " << s << "   rev: " << rev << "   ";
		s = add(s, rev);

		//cout << s << "   " << i << endl;

		if (palindrome(s)) {
			//cout << s << "  " << i << endl;
			return false;
		}
	}
	return true;
}

int main() {
	// 10k is given
	int count = 0;

	for (int i = 1; i < 10000; ++i)
	{
		if (lychrel(i))
			count++;
	}

	cout << "there are " << count << " lychrel numbers below 10k" << endl;

}
