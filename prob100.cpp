#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

string sum(string num1, int count) {
	vector<int> ans;

	int sum = 0;
	for (int d = num1.size()-1; d >= 0; --d)
	{
		for (int i = 0; i < count; ++i)
		{
			sum += num1.at(d)-'0';
		}

		ans.push_back(sum % 10);
		sum = sum / 10;
	}

	for (int i = to_string(sum).size()-1; i >= 0; --i)
	{
		ans.push_back(to_string(sum).at(i)-'0');
	}

	reverse(ans.begin(), ans.end());
	string final = "";
	while (ans[0] == 0) {
		ans.erase(ans.begin());
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		final = final + to_string(ans[i]);
	}

	return final;
}

int digitCount(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += s.at(i) - '0';
	}
	return ans;
}

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

string power(int anum, int num) {
	string a = to_string(anum);
	for (int i = 1; i < num; ++i)
	{
		a = sum(a, anum);
		//cout << i << "  a: " << a << endl;
		//cout << a << endl;
	}
	return a;
}

bool divisorpair(long long num) {
	return (floor(sqrt(num))*(floor(sqrt(num))+1) == num);
}


//PRIME factors
vector<ll> factors(ll num) {
	vector<ll> ans;
	// for (int i = 1; i <= num; ++i)
	// {//can be faster lol
	// 	if (num % i == 0 && isprime(i)) {
	// 		ans.push_back(i);
	// 	}
	// }

	while(true) {
		if (isprime(num)) {
			ans.push_back(num);
			break;
		}
		for (ll i = 2; i < num; ++i)
		{
			if (num % i == 0) {
				ans.push_back(i);
				num = num / i;
				break;
			}
		}
	}
	return ans;
}

void kill_two(vector<ll> &v) {
	for (ll i = 0; i < v.size(); ++i)
	{
		if (v[i] == 2) {
			v.erase(v.begin()+i);
			break;
		}
	}
}


// very weird and specific because I'm lazy
vector<ll> combine(vector<ll> v1, vector<ll> v2) {
	vector<ll> ans;
	
	for (ll i = 0; i < v1.size(); ++i)
	{
		ans.push_back(v1[i]);
	}
	for (ll i = 0; i < v2.size(); ++i)
	{
		ans.push_back(v2[i]);
	}
	//vector<ll> ans(s.begin(), s.end());
	kill_two(ans);

	sort(ans.begin(), ans.end());
	return(ans);
}

int main() {

	// for (int i = 2; i < 1000; i+=2)
	// {
	// 	//int i = 21;
	// 	long long B = (i)*(i-1);  // = 21*20 = 420
	// 	if (divisorpair(B/2)) {   // 2B = 2*420 = 840
	// 		cout << "b: " << i << "   b-1:" << (i-1) << "   a: " << floor(sqrt(B/2)) << "   a-1:" << (floor(sqrt(B/2)) +1) << endl;
	// 	}
	// }

	// vector<ll> temp = factors(420);

	// for (int i = 0; i < temp.size(); ++i)
	// {
	// 	cout << temp[i] << endl;
	// }

	vector<ll> factorsA;
	vector<ll> temp;
	
	for (ll b = pow(10, 12)+1; b < pow(10, 12) + pow(10, 4); b++)
	{
		factorsA = combine(factors(b), factors(b-1)); // B is guaranteed to be even
		ll sizeA = factorsA.size();
		// if (factorsA[sizeA/2] == factorsA[(sizeA/2)-1]+1) {
		// 	cout << "b: " << b << "   b-1: " << (b-1) << "    a: " << factorsA[sizeA/2] << "    a-1: " << factorsA[(sizeA/2)-1] << endl;
			
		// 	cout << endl;
		// }


		// cout << "b: " << b << "    ";
		// for (int i = 0; i < factorsA.size(); ++i)
		// {
		// 	cout << " " << factorsA[i];
		// }
		// cout << endl;

		if (b % 100 == 0) {
			cout << b << endl;
		}

		if (factorsA.size() % 2 == 0) {
			if (abs((factorsA[sizeA/2] * factorsA[(sizeA/2)-1])-(factorsA[(sizeA/2)-2] * factorsA[(sizeA/2)+1])) == 1) {
				cout << "b: " << b << "   b-1: " << (b-1) << "    a: " << (factorsA[(sizeA/2)-2] * factorsA[(sizeA/2)+1]) << "    a-1: " << (factorsA[sizeA/2] * factorsA[(sizeA/2)-1]) << endl;
			}
		}

	}

}
