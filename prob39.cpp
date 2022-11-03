#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
#define ll long long

int main() {
	vector<int> visited(1001, 0);

	for (int i = 1; i < 1000; ++i)
	{
		for (int k = i; k < 1000; ++k)
		{
			if ((double)sqrt(pow(i, 2)+pow(k, 2)) == (int)sqrt(pow(i, 2)+pow(k, 2))) {
				//cout << i << " " << k << " " << sqrt(pow(i, 2)+pow(k, 2)) << endl;
				if (i+k+(int)sqrt(pow(i, 2)+pow(k, 2)) <= 1000) {
					visited[i+k+(int)sqrt(pow(i, 2)+pow(k, 2))] += 1;
				}
			}
		}
	}

	int ans = 0;
	int index = 0;

	for (int i = 1; i < visited.size(); ++i)
	{
		if (visited[i] > ans) {
			ans = visited[i];
			index = i;
		}
	}

	cout << "ans: " << ans << "  perimiter: " << index << endl;
	cout << "t: " << visited[120] << endl;

}

