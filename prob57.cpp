#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define ll long long

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

int main() {
	
	string num = "1";
	string denom = "2";

	ll ans = 0;

	for (int i = 0; i < 1000; ++i)
	{
		cout << add(num, denom) << " " << denom << endl;
		if (add(num, denom).size() > denom.size()) {
			ans++;
		}

		//add extra 2
		num = add(num, denom);
		num = add(num, denom);

		//flip num and denom
		string temp = num;
		num = denom;
		denom = temp;
	}

	cout << "ans: " << ans << endl;
}

// not 317, 256