#include <iostream>
#include <math.h>
#include <string>

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
	long long ans = 2;
	for (int i = 3; i < 2000000; i+=2)
	{
		if (isprime(i)) {
			ans += i;
		}
	}
	cout << "ans: " << ans << endl;
}
