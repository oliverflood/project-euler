#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int divisor_sum(int n) {
	int sum = 1;
	for (int i = 2; i < sqrt(n)+1; ++i)
	{
		if (n % i == 0) {
			sum += i;
			if (i != sqrt(n)) {
				sum += n / i;
			}
		}
	}
	return sum;
}

int main() {

	int ans = 0;
	for (int i = 1; i < 10000; ++i)
	{
		if (i == divisor_sum(divisor_sum(i)) && i != divisor_sum(i)) {
			cout << i << " " << divisor_sum(i) << endl;
			ans += i;
		}
	}

	cout << "ans: " << ans << endl;
}
