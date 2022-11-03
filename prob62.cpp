#include<iostream>
#include <bits/stdc++.h>


using namespace std;

bool is_perm(string a, string b) {
	if (a.length() != b.length()) {
		return false;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		if (b.length() == 0)
			return true;
		if (b.find(a.at(i)) == string::npos) {
			return false;
		}
		else {
			b.erase(b.begin()+b.find(a.at(i)));
		}
	}
	return true;
}

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

int main() {
	
	vector<string> cubes;
	for (int i = 1; i < 10000; ++i)
	{
		cubes.push_back(power(i, 3));
	}

	for (int i = 0; i < cubes.size(); ++i)
	{
		int count = 1;
		for (int k = 0; k < cubes.size(); ++k)
		{
			if (i != k) {
				if (is_perm(cubes[i], cubes[k])) {
					count++;
					if (count == 5) {
						cout << "ans: " << cubes[i] << "  " << cubes[k] << endl;
					}
				}
			}
		}
	}

}