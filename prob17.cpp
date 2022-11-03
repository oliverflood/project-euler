#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int count_letters(int num) {
	string n = to_string(num);
	int ans = 0;
	vector<int> ones = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3};
	vector<int> teens ={6, 6, 8, 8, 7, 7, 9, 8, 8};
	vector<int> tens = {3, 6, 6, 5, 5, 5, 7, 6, 6}; // includes ten, twenty...etc

	if (num == 1000) {
		return 11;
	}

	// getting the hundreds place
	// remember: 100, 200 etc have no "and"
	if (num >= 100) {
		ans += ones[(num/100)-1];
		ans += 7; // "hundred"
		if (num % 100 != 0) {
			ans += 3;
		}
		else {
			return ans;
		}

		num = num % 100; // done with first digit
	}
	
	if (num >= 20) {
		ans += tens[(num/10)-1]; // twenty, thirty, etc
		if (num % 10 == 0) {
			return ans;
		}

		num = num % 10; // done with second digit
		ans += ones[num-1];
	}
	else if (num >= 11) {
		ans += teens[num-11]; // teens
	}
	else {
		ans += ones[num-1];
	}
	return ans;
}

int main() {

	int ans = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		cout << i << " " << count_letters(i) << endl;
		ans += count_letters(i);
	}

	cout << "ans: " << ans << endl;



}


// one, two, three, four, five, six, seven, eight, nine, ten
// eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty
// twenty one
// twenty two
// etc
// thirty, fourty, fifty, sixty, seventy, eighty, ninety
// one hundred (and) 
// two hundred (ans) etc
// nine hundred

// (only used once)
// one thousand