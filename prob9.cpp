#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

int main() {
	for (int a = 1; a < 500; ++a)
	{
		for (int b = 1; b < 500; ++b)
		{
			double c = sqrt(pow(a, 2) + pow(b,2));
			if (a+b+c == 1000) {
				cout << a << " " << b << " " << c << endl;
				cout << "ans: " << std::fixed << a*b*c << endl;
			}
		}
	}
}
