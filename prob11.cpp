#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int product(vector<vector<int>> grid, vector<int> inc, int x, int y, int n) {
	int ans = grid[y][x];
	for (int i = 1; i < n; ++i)
	{
		if (x+inc[0]*i >= 0 && x+inc[0]*i < grid[0].size()) {
			if (y+inc[1]*i >= 0 && y+inc[1]*i < grid.size()) {
				ans *= grid[y+inc[1]*i][x+inc[0]*i];
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	return ans;
}

void print_grid(vector<vector<int>> grid) {
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int k = 0; k < grid[i].size(); ++k)
		{
			cout << (to_string(grid[i][k]).size() < 2? "0" : "") << grid[i][k] << " ";
		}
		cout << endl;
	}
}

int main() {
	ifstream myfile("prob11.txt");
	vector<vector<int>> grid;
	for (int i = 0; i < 20; ++i)
	{
		vector<int> temp;
		grid.push_back(temp);
		for (int k = 0; k < 20; ++k)
		{
			int n;
			myfile >> n;
			grid[i].push_back(n);
		}
	}

	print_grid(grid);

	int n = 4;
	vector<vector<int>> inc = {{1, 0},{0, 1},{1,1},{-1,1}};

	// for (int i = 0; i < 4; ++i)
	// {
	// 	cout << "ans: " << product(grid, inc[i], 0, 0, n) << endl;
	// }
	
	long long ans = 0;
	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[y].size(); ++x)
		{
			for (int i = 0; i < 4; ++i)
			{
				if (product(grid, inc[i], x, y, n) > ans) {
					ans = product(grid, inc[i], x, y, n);
				}
			}
		}
	}

	cout << "ans: " << ans; 
}
