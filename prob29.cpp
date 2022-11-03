// #include <iostream>
// #include <bits/stdc++.h>
// #include <vector>
// #include <fstream>
// #include <iomanip>
// #include <algorithm>
// #include <set>

// using namespace std;
// #define ll long long

// bool isprime(long long num) {
// 	if (num < 1) {
// 		return false;
// 	}
// 	if (num == 2) {
// 		return true;
// 	}
// 	if (num == 1) {
// 		return false;
// 	}
// 	for (int i = 2; i < sqrt(num) + 1; ++i)
// 	{
// 		if (num % i == 0) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

// vector<int> factor(int num) {
// 	vector<int> ans;
// 	for (int i = 1; i <= num; ++i)
// 	{
// 		if (num % i == 0) {
// 			ans.push_back(i);
// 		}
// 	}
// 	return ans;
// }

// void mark(vector<vector<bool>> &visited, int a, int b) {
// 	vector<int> f = factor(b);

// 	cout << "mark " << "  a: " << a << "   b: " << b << endl;

// 	for (int i = 0; i < f.size(); ++i) // -1 to exclude final number
// 	{
// 		if (pow(a, b/f[i]) <= 100 && f[i] != b && f[i] != 1) { // exclude 2^1^8 and 2^8^1
// 			cout << "  " << (pow(a, b/f[i])-2) << " " << (f[i]-2) << endl;
// 			visited[pow(a, b/f[i])-2][f[i]-2] = true; // -2 bcuz array size
// 		}
// 	}
// }

// int count_zeroes(vector<vector<bool>> v) {
// 	int count = 0;

// 	for (int i = 0; i < v.size(); ++i)
// 	{
// 		for (int j = 0; j < v[i].size(); ++j)
// 		{
// 			cout << v[i][j];
// 			if (!v[i][j]) {
// 				count++;
// 			}
// 		}
// 		cout << endl;
// 	}

// 	return count;
// }

// int main() {
// 	vector<vector<bool>> visited;

// 	for (int i = 2; i <= 100; ++i)
// 	{
// 		vector<bool> temp;
// 		for (int k = 2; k <= 100; ++k)
// 		{
// 			temp.push_back(false);
// 		}
// 		visited.push_back(temp);
// 	}
// 	// index with visited[a][b] where a^b

// 	int count = 0;
// 	for (int a = 2; a <= 100; ++a) // should work if you go in order from lowest
// 	{
// 		for (int b = 2; b <= 100; ++b)
// 		{
// 			if (!visited[a-2][b-2]) { // -2 bcuz array size
// 				cout << a << " " << b << endl;
// 				mark(visited, a, b);
// 				count++;
// 			}
// 		}
// 	}

// 	//cout << visited.size() << endl;

// 	cout << "ans: " << count_zeroes(visited) << endl;

// 	for (int i = 1; i < 20; ++i)
// 	{
// 		vector<int> temp = factor(i);
// 		cout << i << ":  ";
// 		for (int j = 0; j < temp.size(); ++j)
// 		{
// 			cout << temp[j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	cout << endl << "count: " << count << endl;
// }


#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

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

	set<string> s;

	for (int a = 2; a <= 100; ++a) 
	{
		for (int b = 2; b <= 100; ++b)
		{
			s.insert(power(a, b));
		}
	}

	cout << "ans: " << s.size() << endl;

}
