#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

int value(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += s.at(i)-'A'+1;
	}
	return ans;
}

bool is_triangle(int n) {
	vector<int> t;
	int c = 0;
	for (int i = 1; i < 20; ++i)
	{
		c += i;
		t.push_back(c);
		cout << c << " ";
	}
	cout << endl;

	if (find(t.begin(), t.end(), n) != t.end()) {
		return true;
	}
	return false;
}

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

string trim_string(string s) {
	return s.substr(1, s.size()-2);
}

int main() {
	ifstream myfile("words.txt");
	string s;
	myfile >> s;
	vector<string> words = split_string(s, ",");
	

	int ans = 0;

	for (int i = 0; i < words.size(); ++i) {
		s = trim_string(words[i]);
		cout << s << " " << value(s) << endl;
		if (is_triangle(value(s))) {
			ans++;
		}
	}


	cout << "ans: " << ans << endl;
}
