#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define ll long long

bool is_square(ll n) {
	return pow((ll)sqrt(n), 2) == n;
}

ll global = 1;

ll get_lowest_x(ll d) {
	if (is_square(d))
 		return -1;
	ll n = 1;

	while (true) {
		// if (n%1000 == 0) {
		// 	cout << n << endl;
		// }

		if (n > 5897926000) {
			return -1;
		}

		if (is_square(d * pow(n, 2) + 1)) {
			//cout << "n: " << n << endl;
			return sqrt(d * pow(n, 2) + 1);
		}
		n++;
	}
}

// ll get_lowest_x(ll d, ll squares[10000]) {
// 	if (is_square(d))
// 		return -1;
// 	for (int i = 0; i < 10000; ++i)
// 	{
// 		if (is_square(d*squares[i]+1)){
// 			// cout << "test: " << d*squares[i]+1 << endl;
// 			return d;
// 		}
// 	}
// 	return -1;
// }

vector<ll> prime_factors(ll n) {

	vector<ll> ans;
	if (n == 1)
		return ans;

	while (n % 2 == 0)
	{
		ans.push_back(2);
		n = n/2;
	}

	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			ans.push_back(i);
			n = n/i;
		}
	}

	if (n > 2)
	ans.push_back(2);
}


int main() {

	ll ans = 0;
	ll best_d = 0;

	//get_lowest_x(61);

	//cout << sqrt(9542750001) << endl;

	// for (ll i = 2; i <= 1000; ++i)
	// {
	// 	if (!is_square(i)) {
	// 		ll new_ans = get_lowest_x(i);
	// 		cout << "D: " << i << "    " << new_ans << endl << endl;

	// 		if (new_ans > ans) {
	// 			ans = new_ans;
	// 			best_d = i;
	// 		}
	// 	}
	// }

	// cout << "151: " << get_lowest_x(151) << endl;
	// cout << "241: " << get_lowest_x(241) << endl;
	// cout << "581: " << get_lowest_x(581) << endl;
	// cout << "604: " << get_lowest_x(604) << endl;
	// cout << "607: " << get_lowest_x(607) << endl;
	// cout << "617: " << get_lowest_x(617) << endl;
	// cout << "778: " << get_lowest_x(778) << endl;

	// cout << "ans: " << ans << endl; 
	// cout << "best_d: " << best_d << endl;


	// for (int i = 0; i < 20; ++i)
	// {
	// 	cout << i << "  " << i*8 << endl;
	// }

	// ll squares[10000];

	// for (int i = 0; i < 10000; ++i)
	// {
	// 	squares[i] = (i+1)*(i+1);
	// }

	for (int i = 1; i < 40; ++i)
	{
		ll lowest_x = get_lowest_x(i);
		cout << "D: " << i << "    x: " << lowest_x << "   ";

		vector<ll> p = prime_factors(lowest_x);
		// sort(p.begin(), p.end());

		for (int i = 0; i < p.size(); ++i)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	cout << "D: " << (997) << "    x: " << get_lowest_x(997) << endl;

	// cout << "D: " << (7*7*31) << "    x: " << get_lowest_x(7*7*31) << endl;

	// cout << "D: " << (13) << "    x: " << get_lowest_x(13) << endl;
	// cout << "D: " << (3*3*13) << "    x: " << get_lowest_x(3*3*13) << endl;



}


// not 779
// not 778