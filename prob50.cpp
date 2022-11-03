#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long
#define SIZE 1000000

bool isprime(ll num) {
	if (num <= 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	for (ll i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<int> primes = {2};
	ll count = 0;

	int c = 0;
	for (int i = 3; i < SIZE; i+=2)
	{
		if (isprime(i)) {
			primes.push_back(i);
			count += i;
		}
		if (count > SIZE) {
			break;
		}
	}

	vector<ll> sums;

	for (int l = primes.size()-1; l >= 1; --l)
	{
		for (int i = 0; i <= primes.size()-1-l; ++i)
		{
			ll sum = accumulate(primes.begin()+i, primes.begin()+i+l, 0);
			// if (sum == 83) {
			// 	for (int a = i; a < i+l; ++a)
			// 	{
			// 		cout << primes[a] << " ";

			// 	}
			// 	cout << endl;
			// }
			// cout << i << " " << i+l << "  " << sum << endl;
			if (isprime(sum))
				sums.push_back(sum);
		}
	}

	ll ans = 0;
	for (int i = 0; i < sums.size(); ++i)
	{
		if (sums[i] > ans) 
			ans = sums[i];
	}

	cout << "ans: " << ans << endl;

}

/*
#define SIZE 1000000

bool isprime(ll num) {
	if (num <= 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	for (ll i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> primes;
int longest;
ll bigans;

ll recurse(int start, int end, ll sum) {
	// for (int i = start; i <= end; ++i)
	// {
	// 	cout << primes[i] << " ";
	// }
	// cout << endl;
	// cout << "sum: " << sum << endl;

	if (isprime(sum)) {
		// cout << "ans: " << sum << endl;
		// cout << (end-start) << endl;
		if (end-start > longest) {
			longest = end-start;
			bigans = sum;
		}
		return (end-start);
	}
	if (end-start > 6) { //terrible code
		if (start == end || start > end) {
			return 0;
		}
		return max(recurse(start, end-1, sum - primes[end]),recurse(start+1, end, sum - primes[start]));
	}
}

int main() {
	primes = {2};
	ll count = 0;
	longest = 0;

	for (int i = 3; i < SIZE; i+=2)
	{
		if (isprime(i)) {
			primes.push_back(i);
			count += i;
			//cout << i << endl;
		}
		if (count > SIZE) {
			break;
		}
	}

	cout << "psize: " << primes.size() << endl;

	//cout << "ans: " << recurse(0, primes.size()-1, accumulate(primes.begin(), primes.end(), 0));
	cout << "longest: " << longest+1 << endl;
	cout << "final ans: " << bigans << endl;

	//trying simplest solution first

	// for (int l = primes.size(); l >= 21; --l)
	// {
	// 	cout << l << endl;
	// 	for (int i = 0; i <= primes.size()-l; ++i)
	// 	{
	// 		if (isprime(accumulate(primes.begin()+i, primes.begin()+i+l, 0))) {
	// 			cout << "ans: " << accumulate(primes.begin()+i, primes.begin()+i+l, 0) << endl;
	// 			exit(69);
	// 		}
	// 	}
	// }

	//cout << primes.size() << endl;
}
*/