#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define ll long long

// some funcs
bool is_square(int n);
int period_len(vector<int> v);
vector<int> sub_v(vector<int> v, int size);
void print_vv(vector<vector<int>> continued_fractions, int size);

/*

2  1
1  2 
2  3  x
1  4
1  5
4  6  x
1  7  
1  8
6  9  x
1  10
1  11
8  12 x

*/

struct frac {
	string num;
	string denom;
};

int digitCount(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += s.at(i) - '0';
	}
	return ans;
}

string sum2(string num1, string num2) {
	vector<int> ans;

	for (int i = 0; i < max(num1.size(), num2.size()); ++i)
	{
		ans.push_back(0);
	}

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());




	int extra = 0;
	for (int i = 0; i < max(num1.size(), num2.size()); ++i)
	{
		int little_total = extra;
		if (i < num1.size()) {
			little_total += num1.at(i)-'0';
		}
		if (i < num2.size()) {
			little_total += num2.at(i)-'0';
		}
		extra = little_total/10;
		little_total = little_total%10;
		ans[i] = little_total;
	}


	reverse(ans.begin(), ans.end());
	string final = "";

	//if (extra != 0) {
	ans.insert(ans.begin(), extra);
	//}

	while (ans[0] == 0) {
		ans.erase(ans.begin());
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		final = final + to_string(ans[i]);
	}
	
	// cout << " extra " << extra << endl;
	// for (int i = 0; i < ans.size(); ++i)
	// {
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;

	// if (extra != 0)
	// 	return (to_string(extra*10) + final);

	return final;
}


string sum(string num1, int count) {
	if (count == 1) {
		return num1;
	}

	string save = num1;
	for (int i = 0; i < count-1; ++i)
	{
		num1 = sum2(num1, save);
		//cout << i << "  " << num1 << endl;
	}

	return num1;
}



int main() {
	ll nth = 100;

	ll n = 1;

	frac fx;
	fx.num = "1";

	if (nth % 3 == 0) {
		fx.denom = to_string(n*2/3);
	}
	else {
		fx.denom = "1";
	}
	
	for (int i = nth-1; i > 1; --i)
	{
		//cout << i << endl;
		n = 1;
		if (i % 3 == 0) {
			n = (i*2)/3;
		}

		//string temp2 = sum(fx.denom, n);
		// cout << fx.denom << " " << n << endl;
		// cout << temp2 << endl;
		string n_s = sum(fx.denom, n);

		fx.num = sum2(fx.num, sum(fx.denom, n));

		string temp = fx.num;
		fx.num = fx.denom;
		fx.denom = temp;
		
		cout << fx.num << " / " << fx.denom << endl << endl;
	}

	fx.num = sum2(sum(fx.denom, 2), fx.num);

	cout << fx.num << " / " << fx.denom << endl;


	cout << "\n\n\n" << "final numerator: " << fx.num << endl;
	cout << "\nfinal ans: " << digitCount(fx.num) << endl;


	//cout << sum("11111", 1231) << endl;

}
// 244 wrong
// 244


bool is_square(int n) {
	if (sqrt(n) == floor(sqrt(n)))
		return true;
	return false;
}

vector<int> sub_v(vector<int> v, int size) {
	vector<int> ans;
	for (int i = 0; i < size; ++i)
	{
		ans.push_back(v[i]);
	}
	return ans;
}

// calc the period of a continued frac list
int period_len(vector<int> v) {

	for (int i = 1; i <= v.size()/2; i++)
	{
		bool rep = true;
		vector<int> sub_vector = sub_v(v, i);

		// check if the sub vector tiles the full vector
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] != sub_vector[j%sub_vector.size()]) {
				rep = false;
			}
		}

		if (rep) {
			return i;
		}
	}

	return -1;
}

void print_vv(vector<vector<int>> continued_fractions, int size) {

	for (int i = 0; i < size; ++i)
	{
		cout << i << ": " << " ";
		for (int j = 0; j < continued_fractions[i].size(); ++j)
		{
			cout << continued_fractions[i][j] << " ";
		}
		cout << "   " << "len: " << period_len(continued_fractions[i]) << endl;
	}
}