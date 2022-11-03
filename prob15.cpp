#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	cout << "give num: ";
	cin >> num;

	vector<long long> a1, a2, a3;

	for (int i = 0; i < num+1; ++i)
	{
		a1.push_back(1);
		a2.push_back(1);
	}

	for (int i = 0; i < num; ++i)
	{
		for (int i = 1; i < a2.size(); ++i)
		{
			a2[i] = a1[i] + a2[i-1];
		}
		a1 = a2;
	}
	
	cout << "ans: " << a2[num] << endl;
}