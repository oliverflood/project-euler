#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;

string sum(string num1, string num2) {
	vector<int> ans;


	int sum = 0;
	for (int d = 0; d < max(num1.size(), num2.size()); ++d)
	{
		if (d < num1.size()) {
			sum += num1.at(num1.size()-d-1)-'0';
		}
		if (d < num2.size()) {
			sum += num2.at(num2.size()-d-1)-'0';
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

int main() {
	string f1 = "1";
	string f2 = "2";

	int count = 2;
	while (f2.size() != 1000) {
		string temp = f2;
		f2 = sum(f1, f2);
		f1 = temp;
		count++;
	}

	cout << f2 << endl;
	cout << "count: " << count << endl;
}
//4781
//4782?