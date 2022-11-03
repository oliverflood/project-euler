#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define ll long long

void printv(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int sum(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum;
}

// works good
bool link(int a, int b) {
	string as = to_string(a);
	string bs = to_string(b);

	if (as.length() != 4 || bs.length() != 4) {
		exit(1);
		cout << "FUCK!" << endl;
	}

	//assume both are 4 digit nums
	if (as.substr(2, 2) == bs.substr(0, 2))
		return true;
	return false;

}

vector<vector<int>> v_without(vector<vector<int>> nums, int index) {
	nums.erase(nums.begin()+index);
	return nums;
}

bool contains(vector<int> v, int e) {
	if (find(v.begin(), v.end(), e) != v.end())
		return true;
	return false;
}

int pos(vector<int> v, int e) {
	if (find(v.begin(), v.end(), e) != v.end())
		return (find(v.begin(), v.end(), e)-v.begin());
	return -1;
}

void traverse(vector<vector<vector<pair<int, int>>>> graph, vector<vector<int>> nums, int i, int j, int k, vector<pair<int, int>> visited) {
	visited.push_back(graph[i][j][k]);

	if (visited.size() == 6 && ) {
		cout << "WINNER WINNER CHICKEN DINNER" << endl;
		exit(1);
	}

	for (int a = 0; a < graph[i][j][k].size(); ++a)
	{
		traverse(graph, graph[i][j][k])
	}
}

int main() {	
	vector<vector<int>> nums;

	// triangle through octagonal
	for (int inc = 1; inc <= 6; ++inc)
	{
		vector<int> temp;
		nums.push_back(temp);

		int count = 1;
		int subinc = 1;
		while (count <= 9999) // i never reaches 9000
		{
			if (count >= 1000) {
				nums[inc-1].push_back(count);
			}
			subinc += inc;
			count += subinc;
		}	
	}
	// now nums is a vector of 6 vectors which are the tri-oct nums

	// check and store all possible connections in a DAG

	// which vector in graph its in corresponds to num group
	// the first & second elements in pair correspond to i and j in nums[i][j]
	vector<vector<vector<pair<int, int>>>> graph;
	for (int i = 0; i < nums.size(); ++i)
	{
		vector<vector<pair<int, int>>> temp;
		for (int j = 0; j < nums[i].size(); ++j)
		{
			vector<pair<int, int>> t2;
			temp.push_back(t2);  // "allocating memory"
		}
		graph.push_back(temp);
	}

	for (int i = 0; i < nums.size(); ++i)
 	{
		for (int j = 0; j < nums.size(); ++j)
		{
			if (i == j) {
				continue; // I think this works to make sure i != j
			}
			for (int a = 0; a < nums[i].size(); ++a)
			{
				for (int b = 0; b < nums[j].size(); ++b)
				{
					if (link(nums[i][a], nums[j][b])) {
						graph[i][a].push_back(pair<int,int>(j, b));
					}
				}
			}
		}
	}

	// check one groups connections to see if any traverse all 6 groups


	for (int i = 0; i < graph[0].size(); ++i)
	{
		
	}


}



//bindex = big index = index of nums to start looking 
// void recurse(vector<vector<int>> nums, vector<int> list) {
// 	if (nums.size() == 0) {
// 		if (link(list[list.size()-1], list[0])) {
// 			printv(list);
// 			cout << endl;
// 			cout << "ans: " << sum(list) << endl;
// 			exit(0);
// 		}
// 		else {
// 			return;
// 		}
// 	}

// 	for (int i = 0; i < nums.size(); ++i)
// 	{
// 		for (int j = 0; j < nums.size(); ++j)
// 		{
// 			if (i == j) {
// 				continue;
// 			}
// 			for (int a = 0; a < nums[i].size(); ++a)
// 			{
// 				for (int b = 0; b < nums[j].size(); ++b)
// 				{
// 					if (link(nums[i][a], nums[j][b])) {
// 						list.push_back(nums[i][a]);
// 						recurse(v_without(nums, i), list);
// 					}
// 					if (link(nums[j][b], nums[i][a])) {
// 						list.push_back(nums[j][b]);
// 						recurse(v_without(nums, j), list);
// 					}
// 				}
// 			}
// 		}
// 	}
// }