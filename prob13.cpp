#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool isprime(long long num) {
	if (num == 2) {
		return true;
	}
	if (num == 1) {
		return false;
	}
	for (int i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ifstream myfile("prob13.txt");
	vector<string> input;

	for (int i = 0; i < 100; ++i)
	{
		string temp;
		myfile >> temp;
		//cout << temp << endl;
		input.push_back(temp);
	}

	vector<int> ans;

	int sum = 0;
	for (int d = 49; d >= 0; --d)
	{
		for (int i = 0; i < input.size(); ++i)
		{
			cout << input[i].at(d)-'0' << endl;
			sum += input[i].at(d)-'0';
		}
		
		ans.push_back(sum % 10);
		cout << "pushed " << sum % 10 << endl;
		cout << "saved " << sum / 10 << endl;
		sum = sum / 10;
		// for (int i = to_string(sum).size()-1; i >= 0; --i)
		// {
		// 	arr[d+i] += (to_string(sum).at(i)-'0');
		// }
	}
	ans.push_back(sum);
	cout << "final sum " << sum << endl;

	cout << "ans: " << ans.size() << endl;

	for (int i = ans.size()-1; i >= 0; --i)
	{
		cout << ans[i];
	}
}
