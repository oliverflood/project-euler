#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

int champerowne(int n) {
	int index = 1;
	int c = 1;

	while (true) {
		if (index == n) {
			string s = to_string(c);
			return (s.at(0)-'0');
		}
		if (index > n) {
			//cout << "t: " << (c-1) << endl;
			string s = to_string(c-1);
			return (s.at(index-n)-'0');
		}
		index += to_string(c).size();
		c++;
	}
}

int main() {
	
	cout << champerowne(1) << endl;
	cout << champerowne(12) << endl;
	cout << champerowne(17) << endl;

	ll ans = 1;
	for (int i = 0; i <= 6; ++i)
	{
		ans *= champerowne(pow(10, i));
		cout << pow(10, i) << "  " << champerowne(pow(10, i)) << endl;
	}

	cout << "ans: " << ans << endl;

}

