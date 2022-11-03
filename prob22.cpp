#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;

bool compare_names(string name1, string name2) {
	for (int i = 0; i < min(name1.size(), name2.size()); ++i)
	{
		if (name1.at(i) < name2.at(i)) {
			return true;
		}
		else if (name1.at(i) > name2.at(i)) {
			return false;
		}
	}

	// in case of tie return shorter name
	return (name1.size() < name2.size() ? 1 : 0);
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

void print(vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		cout << endl;
	}
	cout << endl;
}

int namescore(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans += s[i]-'A'+1;
	}
	return ans;
}

long long score(vector<string> v) {
	long long ans = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		ans += (i+1) * namescore(v[i]);
	}
	return ans;
}

int main() {
	ifstream myfile("names.txt");
	string input;
	myfile >> input;

	vector<string> names = split_string(input, ",");

	for (int i = 0; i < names.size(); ++i)
	{
		names[i] = trim_string(names[i]);
	}

	sort(names.begin(), names.end(), compare_names);

	print(names);

	cout << "total score: " << score(names) << endl;
}
