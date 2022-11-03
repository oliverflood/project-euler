#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
	ifstream myfile("triangle.txt");
	cout << "triangle" << endl;

	vector<vector<int>> triangle;

	for (int i = 1; i <= 100; ++i)
	{
		vector<int> temp;
		for (int k = 0; k < i; ++k)
		{
			int num;
			myfile >> num;
			temp.push_back(num);
		}
		triangle.push_back(temp);
	}

	reverse(triangle.begin(), triangle.end());

	for (int i = 0; i < triangle.size(); ++i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			cout << triangle[i][j] << " ";
			for (int k = 0; k < 4-to_string(triangle[i][j]).size(); ++k)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 1; i < triangle.size(); ++i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j+1]);
		}
	}

	for (int i = 0; i < triangle.size(); ++i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			cout << triangle[i][j] << " ";
			for (int k = 0; k < 4-to_string(triangle[i][j]).size(); ++k)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
