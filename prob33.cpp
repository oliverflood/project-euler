#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

int main() {
	
	int num = 1;
	int denom = 1;

	for (int j = 1; j <= 9; ++j)
	{
		for (int i = 1; i <= 9; ++i) 
		{
			for (int k = 1; k <= 9; ++k) 
			{
				if ((double)i/j == (double)(i*10+k)/(j*10+k) && (double)i/j < 1.0) {
					cout << (i*10+k) << " / " << (j*10+k) << endl;
					num *= (i*10+k);
					denom *= (j*10+k);
				}
				if ((double)i/j == (double)(i*10+k)/(j+k*10) && (double)i/j < 1.0) {
					cout << (i*10+k) << " / " << (j+k*10) << endl;
					num *= (i*10+k);
					denom *= (j+k*10);
				}
				if ((double)i/j == (double)(i+k*10)/(j*10+k) && (double)i/j < 1.0) {
					cout << (i+k*10) << " / " << (j*10+k) << endl;
					num *= (i+k*10);
					denom *= (j*10+k);
				}
			}
		}
	}

	cout << num << " / " << denom << endl;
}
