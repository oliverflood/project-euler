#include <iostream>
#include <math.h>

using namespace std;

bool isprime(long long num) {
	for (int i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void factor(long long num) {
	if (isprime(num)) {
		cout << num << endl;
	}

	for (int i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0) {
			cout << i << endl;
			factor(num / i);
			break;
		}
	}
}

int main() {
	long long input;
	cout << "Give a number: " << endl;
	cin >> input;

	cout << isprime(input) << endl;
	cout << "factoring..." << endl;
	factor(input);
}


// int *p = &a; is good

// int *p;
// p = &a; is good
// *p = &a; is stupid, type mismatch error


/*

int **p2;
int *p;
int x = 420;

p2 = &p;
p = &x;

cout << x << *p << **p2 << endl;

*/

