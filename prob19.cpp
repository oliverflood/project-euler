#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
	
	int month_day_counts[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = 0;
	int mday = 0;
	int year = 1900;
	int weekday = 0;
	int ans = 0; 

	while (year < 2001) {
		// ensure its leap year or not 
		// (dont have to do this here but idk i just wanna)
		month_day_counts[1] = 28; // assume no leap year
		if (year % 4 == 0) {
			if (year % 100 != 0) {
				month_day_counts[1] = 29; // leap year!
			}
			else if (year % 400 == 0) {
				month_day_counts[1] = 29; // leap year!
			}
		}

		// the check for sunday on 1st of month
		if ((weekday == 6) && (mday == 0) && (year >= 1901)) {
			ans++; // first sunday of the week from 1901 to end of 2000
		}

		// increments and changes
		weekday = (weekday+1) % 7;
		mday++;
		// deal with months
		if (mday == month_day_counts[month]) {
			mday = 0;
			month++;
			// deal with years
			if (month == 12) { // incremented past december
				year++;
				month = 0;
			}
		}
	}

	cout << "Sundays on first day of months: " << ans << endl;
}
