#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

int count(int total_left, int coin, vector<int> choices) {
	int ans = 0;
	if (total_left == 0) {
		return 1;
	}
	else {
		for (int i = 0; i < choices.size(); ++i)
		{
			if (choices[i] <= coin) {
				if (choices[i] <= total_left) {
					ans += count(total_left-choices[i], choices[i], choices);
				}
			}
		}
	}
	return ans;
}

int main() {

	//vector<int> coins = {10, 5, 2, 1};
	vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};

	cout << count(200, 200, coins) << endl;
}

// 72161