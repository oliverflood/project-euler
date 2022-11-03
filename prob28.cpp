#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ll long long
#define SIZE 1001

int main() {
	ll ans = 1;
	ll current = 1;

	// probably can be simplified nicely but I'm lazy
	for (int n = 1; n <= (SIZE-1)/2; ++n)
	{
		ans += 4*current + 20*n;
		current += 8*n;
	}

	cout << "ans: " << ans << endl;
}
