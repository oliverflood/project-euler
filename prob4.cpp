#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool is_palindrome(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.length()/2; ++i)
	{
		if (s.at(i) != s.at(s.length()-1-i)) {
			return false;
		}
	}
	return true;
}

bool two_three_factors(int n) {
	for (int i = 111; i <= 999; ++i)
	{
		if (n % i == 0) {
			if (to_string(n / i).length() == 3) {
				return true;
			}
		}
	}
	return false;
}


int main() {
	for (int i = 999*999; i >= 111*111; --i)
	{
		if (is_palindrome(i)) {
			if (two_three_factors(i)) {
				cout << i << endl;
				break;
			}
		}
	}
}

/*

There are two distinct areas of memory called the stack and the heap

Stack- limited size chunk of larger blob of system memory
Relatively small, about 8MB
If you run out of memory -> stack overflow
Allocated in contiguous block duing compile time
Known as static memory
Stores local/global variables, constants, values declared in a program's functions
Functions have their own stack frame
Functions which are called are put on the stack
No memory issues I think

Heap- comprises essentially all the rest of system memory
Heap is larger and determined by RAM and faster
Heap memory is allocated at runtime in random order


*/