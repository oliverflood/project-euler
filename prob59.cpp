#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define ll long long

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}

vector<int> permutation(int n, int address) {
	vector<int> digits;
	for (int i = 0; i < n; ++i)
	{
		digits.push_back(i);
	}
	n--;

	vector<int> ans;
	int current = 0;
	int count = 0;
	while (true) {
		if (current + factorial(n) >= address) {
			ans.push_back(digits[count]);
			digits.erase(digits.begin()+count);
			count = 0;
			n--;
			if (n == 0) {
				ans.push_back(digits[0]);
				break;
			}
			continue;
		}
		current += factorial(n);
		count++;
	}

	return ans;
}

vector<vector<int>> permutations;

vector<string> split_string(string s, string delimiter) {
	vector<string> result;
	int increment = 0;

	int found = s.find_first_of(delimiter, increment);
	while (found != string::npos) {
		result.push_back(s.substr(increment, found-increment));
		increment = found + 1;
		found = s.find_first_of(delimiter, increment);
	}
	result.push_back(s.substr(increment, s.size()-increment));

	return result;
}

vector<int> vstovi(vector<string> v) {
	vector<int> ans;
	for (int i = 0; i < v.size(); ++i)
	{
		ans.push_back(stoi(v[i]));
	}
	return ans;
}

vector<string> decode(vector<int> message, int a, int b, int c) {
	vector<int> indexes = {a, b, c};

	vector<string> ans;

	for (int i = 0; i < permutations.size(); ++i)
	{
		vector<int> current_p = permutations[i];
		a = indexes[current_p[0]];
		b = indexes[current_p[1]];
		c = indexes[current_p[2]];
		string s = "";

		for (int i = 0; i < message.size(); i+=3)
		{
			s += (char)(a^message[i]);
			s += (char)(b^message[i+1]);
			s += (char)(c^message[i+2]);
		}

		ans.push_back(s);
	}

	return ans;
}

int sum_ascii(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += (int)s.at(i);
	}
	return ans;
}

int main() {
	fstream myfile;
	myfile.open("cipher.txt");

	string s;
	myfile >> s;

	for (int i = 0; i < factorial(3); ++i)
	{
		permutations.push_back(permutation(3, i));
		//cout << permutations[i][0] << " " << permutations[i][1] << " " << permutations[i][2] << endl;
	}

	vector<int> v = vstovi(split_string(s, ","));

	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << v[i] << " ";
	// }

	cout << v.size() << endl;

	for (int a = 'a'; a <= 'z'; ++a)
	{
		for (int b = 'a'; b <= 'z'; ++b) 
		{
			for (int c = 'a'; c <= 'z'; ++c) 
			{
				vector<string> temp = decode(v, a, b, c);
				for (int i = 0; i < temp.size(); ++i)
				{
					if (temp[i].find("the") != string::npos && temp[i].find("and") != string::npos && temp[i].find("of") != string::npos && temp[i].find("that") != string::npos) {
						cout << temp[i] << endl;
						cout << "sum: " << sum_ascii(temp[i]) << endl;
						cout << "key: " << ((char)a) << " " << ((char)b) << " "<< ((char)c) << endl << endl;
					}
				}
			}
		}
	}

}
