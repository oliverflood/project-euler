#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int num_divisors(int n) {
	int ans = 0;	
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0) {
			ans += 2;
			if (i == sqrt(n) && (n % (int)sqrt(n) == 0)) {
				ans--;
			}
		}
	}
	return ans;
}

int main() {
	int triangle = 0;
	//cout << "d: " << 7/2 << endl;

	for (int i = 1; i < 100000; ++i)
	{
		triangle += i;
		if (i % 1000 == 0) {
			cout << i << " " << triangle << " " << num_divisors(triangle) << endl;
		}
		if (num_divisors(triangle) > 500) {
			cout << "ans: " << triangle << endl;
			break;
		}
	}
}
