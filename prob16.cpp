#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

string sum(string num1, string num2) {
	vector<int> ans;

	if (num1.size() > num2.size()) {
		for (int i = 0; i < num1.size()-num2.size(); ++i)
		{
			num2 = "0" + num2;
		}
	}
	else if (num2.size() > num1.size()) {
		for (int i = 0; i < num2.size()-num1.size(); ++i)
		{
			num1 = "0" + num1;
		}
	}

	int sum = 0;
	for (int d = num1.size()-1; d >= 0; --d)
	{
		sum += num1.at(d)-'0';
		sum += num2.at(d)-'0';

		ans.push_back(sum % 10);
		sum = sum / 10;
	}
	ans.push_back(sum);
	if (sum > 9) {
		cout << "FUCK" << endl;
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

int main() {
	string a = "1";
	for (int i = 0; i < 1000; ++i)
	{
		a = sum(a, a);
		cout << a << endl;
	}


	cout << "ans: " << digitCount(a);
}
