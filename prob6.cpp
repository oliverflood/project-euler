#include <iostream>
#include <math.h>
#include <string>

using namespace std;

long long sum(long long n) {
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += pow(i, 2);
	}
	return ans;
}

int main() {
	cout << "ans:" << endl;
	cout << fixed << pow(5050, 2) - sum(100) << endl;
}
