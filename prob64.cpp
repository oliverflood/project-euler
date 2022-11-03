#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>

using namespace std;
#define ll long long

// some funcs
bool is_square(int n);
int period_len(vector<int> v);
vector<int> sub_v(vector<int> v, int size);
void print_vv(vector<vector<int>> continued_fractions, int size);


// how irrational frac is stored
struct frac {
	int irrational_squared;
	int numerator;
	int denominator;
};


// approximate a weird fraction struct 
long double approx_frac(frac x) {
	return ((sqrt(x.irrational_squared)+x.numerator)/x.denominator);
}


// number of continued frac parts to calculate
#define SIZE 1000

/*
Improvements that should be done:
-The program should only calculate as many digits are needed to
 tile the cont frac list, this should work as long as you generate
 enough arbitrary digits at the start to make sure you don't
 think the period is very short
-Similar to above but the 2k size is very brute force and
 arbitrary
*/

int main() {
	vector<vector<int>> continued_fractions;

	for (int n = 2; n <= 10000; ++n)
	{
		// making sure n is irrational
		if (is_square(n))
			continue;

		// array to hold values of a in continued fraction
		vector<int> cont_frac;

		// floor of our irrational
		int a = sqrt(n);

		// held in fraction struct with irrational+rational all over rational denom
		frac fx;
		fx.irrational_squared = n;
		fx.numerator = 0;
		fx.denominator = 1;


		for (int i = 0; i < SIZE; ++i)
		{
			// remaking our new fraction for a certain iteration
			frac new_fx;

			// lots of algebra for calculating parts of our new fraction struct
			new_fx.irrational_squared = fx.irrational_squared;
			new_fx.numerator = (-(fx.numerator-(fx.denominator*a)));
			new_fx.denominator = (fx.irrational_squared - pow((fx.numerator-(fx.denominator*a)), 2))/(fx.denominator);

			// get our new floor and add it to continued frac
			a = approx_frac(new_fx);
			cont_frac.push_back(a);

			// prepare for another iteration
			fx = new_fx;
		}

		continued_fractions.push_back(cont_frac);
	}

	// calculating the final answer
	int ans = 0;
	int max = 0;
	for (int i = 0; i < continued_fractions.size(); ++i)
	{
		if (period_len(continued_fractions[i]) % 2 == 1) {
			ans++;
		}
		if (period_len(continued_fractions[i]) > max)
			max = period_len(continued_fractions[i]);
	}

	cout << "max: " << max << endl;
	cout << "total odd period fracs N <= 10,000: " << ans << endl;
}



bool is_square(int n) {
	if (sqrt(n) == floor(sqrt(n)))
		return true;
	return false;
}

vector<int> sub_v(vector<int> v, int size) {
	vector<int> ans;
	for (int i = 0; i < size; ++i)
	{
		ans.push_back(v[i]);
	}
	return ans;
}

// calc the period of a continued frac list
int period_len(vector<int> v) {

	for (int i = 1; i <= v.size()/2; i++)
	{
		bool rep = true;
		vector<int> sub_vector = sub_v(v, i);

		// check if the sub vector tiles the full vector
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] != sub_vector[j%sub_vector.size()]) {
				rep = false;
			}
		}

		if (rep) {
			return i;
		}
	}

	return -1;
}

void print_vv(vector<vector<int>> continued_fractions, int size) {

	for (int i = 0; i < size; ++i)
	{
		cout << i << ": " << " ";
		for (int j = 0; j < continued_fractions[i].size(); ++j)
		{
			cout << continued_fractions[i][j] << " ";
		}
		cout << "   " << "len: " << period_len(continued_fractions[i]) << endl;
	}
}