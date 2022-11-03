#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define ll long long

struct node;

struct node {
	int num;
	int group;
	vector<node*> pointers;
};

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



int pos(vector<int> v, int e) {
	if (find(v.begin(), v.end(), e) != v.end())
		return (find(v.begin(), v.end(), e)-v.begin());
	return -1;
}

// void traverse(vector<vector<vector<pair<int, int>>>> graph, vector<vector<int>> nums, int i, int j, int k, vector<pair<int, int>> visited) {
// 	visited.push_back(graph[i][j][k]);

// 	if (visited.size() == 6 && ) {
// 		cout << "WINNER WINNER CHICKEN DINNER" << endl;
// 		exit(1);
// 	}

// 	for (int a = 0; a < graph[i][j][k].size(); ++a)
// 	{
// 		traverse(graph, graph[i][j][k])
// 	}
// }

vector<node> v_with(vector<node> v, node e) {
	v.push_back(e);
	return v;
}

bool contains(vector<node> v, int e) {
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].group == e) {
			return true;
		}
	}
	return false;
}

void traverse(vector<vector<node>> graph, node n, vector<node> visited) {
	visited.push_back(n);


	//if (visited.size() == 6) {
	if (visited.size() == 6 && link(visited[visited.size()-1].num, visited[0].num)) {
		cout << "winner" << endl;

		int sum = 0;

		for (int i = 0; i < visited.size(); ++i)
		{
			cout << (visited[i].group) << " " << (visited[i].num) << endl;
			sum += visited[i].num;
		}

		cout << "FINAL SUM: " << sum << endl << endl;

		for (int i = 0; i < visited[visited.size()-1].pointers.size(); ++i)
		{
			node temp = *visited[visited.size()-1].pointers[i];
			cout << "p " << temp.group << " " << temp.num << endl;
		}
		// cout << "visited: " << endl;
		// for (int i = 0; i < visited.size(); ++i)
		// {
		// 	cout << visited[i].num << " ";
		// }

		// cout << "\ntest: " << endl;
		
		// node temp = *visited[visited.size()-1].pointers[4];
		
		// cout << temp.group << " " << temp.num << endl;
		// cout << contains(visited, temp.group) << endl;

		cout << endl << endl;
		//exit(0);
	}

	for (int i = 0; i < n.pointers.size(); ++i)
	{
		node temp = *n.pointers[i];
		if (!contains(visited, temp.group))
			traverse(graph, temp, visited);
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



	vector<vector<node>> graph;

	for (int i = 0; i < nums.size(); ++i)
	{
		vector<node> temp;
		graph.push_back(temp);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[i].size(); ++j)
		{
			node n1;
			n1.num = nums[i][j];
			n1.group = i;
			graph[i].push_back(n1);
		}
	}

	for (int i = 0; i < graph.size(); ++i) // 6
 	{
		for (int j = 0; j < graph.size(); ++j) // 6
		{
			if (i != j) {
				for (int a = 0; a < graph[i].size(); ++a)
				{
					for (int b = 0; b < graph[j].size(); ++b)
					{
						if (link(graph[i][a].num, graph[j][b].num)) {
							// graph[i][a].push_back(pair<int,int>(j, b));
							graph[i][a].pointers.push_back(&graph[j][b]);
						}
					}
				}
			}
		}
	}


	vector<node> visited;
	for (int i = 0; i < graph[0].size(); ++i)
	{
		traverse(graph, graph[0][i], visited);
	}


	// for (int i = 0; i < graph.size(); ++i)
	// {
	// 	for (int j = 0; j < graph[i].size(); ++j)
	// 	{
	// 		//traverse(graph, graph[i][j], visited);
	// 		cout << i << " " << graph[i][j].num << endl;
	// 	}
	// 	cout << endl << endl;
	// }


	// vector<vector<vector<pair<int, int>>>> graph;
	// for (int i = 0; i < nums.size(); ++i)
	// {
	// 	vector<vector<pair<int, int>>> temp;
	// 	for (int j = 0; j < nums[i].size(); ++j)
	// 	{
	// 		vector<pair<int, int>> t2;
	// 		temp.push_back(t2);  // "allocating memory"
	// 	}
	// 	graph.push_back(temp);
	// }

	// for (int i = 0; i < nums.size(); ++i)
 // 	{
	// 	for (int j = 0; j < nums.size(); ++j)
	// 	{
	// 		if (i == j) {
	// 			continue; // I think this works to make sure i != j
	// 		}
	// 		for (int a = 0; a < nums[i].size(); ++a)
	// 		{
	// 			for (int b = 0; b < nums[j].size(); ++b)
	// 			{
	// 				if (link(nums[i][a], nums[j][b])) {
	// 					graph[i][a].push_back(pair<int,int>(j, b));
	// 				}
	// 			}
	// 		}
	// 	}
	// }



	// node n1;
	// n1.num = 2222;
	// n1.group = 0;

	// node n2;
	// n2.num = 2248;
	// n2.group = 0;

	// n1.pointers.push_back(&n2);

	// node temp = *n1.pointers[0];

	// cout << (temp.num) << endl;





}
