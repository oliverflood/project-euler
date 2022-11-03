#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

bool pentagonal(ll n) {

	int a = ceil((double)sqrt(((n*2)/3)));
	if ((int)((a*(3*a-1))/2) == n) {
		return true;
	}
	return false;
}

int main() {
	vector<ll> pentas;

	for (int i = 1; i < 10000; ++i)
	{
		pentas.push_back(i*(3*i-1)/2);
	}

	for (int i = 0; i < 20; ++i)
	{
		cout << pentas[i] << endl;
	}

	for (int b = 1; b < pentas.size(); ++b)
	{
		bool kill = false;
		for (int a = b-1; a >= 0; --a)
		{
			if (pentagonal(pentas[a]+pentas[b]) && pentagonal(pentas[b]-pentas[a])) {
				cout << pentas[b] << " " << pentas[a] << " " << (pentas[b]-pentas[a]) << endl;
				kill = true;
				break;
			}
		}
		if (kill) {
			break;
		}
	}

}
