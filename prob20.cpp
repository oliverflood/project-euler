#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

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

string factorial(int num) {
	string a = "1";
	for (int i = 1; i < 100; ++i)
	{
		a = sum(a, i+1);
		//cout << a << endl;
	}
	return a;
}

int main() {


	
	cout << factorial(100) << endl;	

	cout << "ans: " << digitCount(factorial(100));
}
