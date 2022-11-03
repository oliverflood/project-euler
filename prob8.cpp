#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream myfile("prob8.txt");
	string text;
	getline(myfile, text);
	int n;

	cout << text << endl;
	cout << "give num: ";
	cin >> n;

	long long ans = 0;
	for (int i = 0; i < text.length()-n+1; ++i)
	{
		long long temp = 1;
		for (int k = i; k < i+n; ++k)
		{
			temp *= text.at(k)-'0';
		}
		if (temp > ans) {
			ans = temp;
		}
	}

	cout << "ans: " << ans << endl;
}
