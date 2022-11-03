#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

long long factorial(long long num) {
	long long ans = 1;
	for (int i = 1; i <= num; ++i)
	{
		ans *= i;
	}
	return ans;
}

bool facdigit(long long num) {
	string s = to_string(num);
	long long ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += factorial(s[i]-'0');
	}
	return (ans == num);
}

int main() {
	
	long long sum = 0;

	// range is just a guess
	for (int i = 3; i < 10000000; ++i)
	{
		if (facdigit(i)) {
			sum += i;
		}
	}
	

	cout << sum << endl;
}
