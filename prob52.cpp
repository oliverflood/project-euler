#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool samedigits(ll a, ll b) {
	string sa = to_string(a);
	string sb = to_string(b);

	for (int i = 0; i < sa.size(); ++i)
	{
		if (sb.find(sa.substr(i, 1)) == string::npos) {
			return false;
		}
		else {
			sb.erase(sb.find(sa.substr(i, 1)), 1);
		}
	}
	return true;
}

bool compare_six(ll x) {
	for (int i = 2; i <= 6; ++i)
	{
		if (!samedigits(x, i*x)) 
			return false;
	}
	return true;
}

#define SIZE 10000000

int main() {
	for (int i = 1; i < SIZE; ++i)
	{
		if (compare_six(i)) {
			cout << "ans: " << i << endl;
			break;
		}
	}
}