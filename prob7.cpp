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
	long long n = 1;
	long long prime_count = 0;
	while(true) {
		if (isprime(n)) {
			prime_count++;
			cout << prime_count << " " << n << endl;
		}
		if (prime_count == 10001) {
			break;
		}
		n++;
	}
}
