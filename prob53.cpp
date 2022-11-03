#include <bits/stdc++.h>

using namespace std;

#define ll float
#define SIZE 1000000

/*
23 choose 10
23*22...*11

23!/(10!13!)

*/

bool overmillion(ll n, ll r) {
	ll ans = 1;
	ll n_minus_r = n-r;

	if (r > n_minus_r) {
		ll temp = r;
		r = n_minus_r;
		n_minus_r = temp;
	}

	for (int i = r+1; i <= n; ++i)
	{

		// cout << " ans *= " << i << endl;
		// cout << " ans /= " << ((n-r)+1) << endl;
		ans *= i;
		ans /= (n-i)+1;
		//cout << " " <<  ans << endl;

		if (ans >= SIZE) {
			return true;
		}
	}

	return false;
}

int main() {
	int count = 0;
	
	for (int n = 1; n <= 100; ++n)
	{
		for (int r = 1; r <= n; ++r)
		{
			cout << "n: " << n << "   r: " << r << endl;
			if (overmillion(n, r)) {
				count++;
			}
			cout << endl << endl;
		}
	}

	cout << "ans: " << count << endl;
}

/*


r = [1, n]

n = [1, 100]


*/