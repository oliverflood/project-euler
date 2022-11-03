#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define SIZE 1000000

vector<ll> primes;

bool isprime(ll num) {
	if (num <= 1)
		return false;
	if (num == 2)
		return true;

	for (ll i = 2; i < sqrt(num) + 1; ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void slaughter(vector<ll> &v, ll e) {
	auto loc = find(v.begin(), v.end(), e);

	if (loc != v.end()) 
		v.erase(loc);
}

vector<int> rem(vector<int> v, int i) {
	v.erase(v.begin()+i);
	return v;
}

void combos(vector<vector<int>> &combinations, vector<int> v, string prime) {
	char check = prime.at(v[0]);
	
	combinations.push_back(v);

	if (v.size() > 1) {
		for (int i = 0; i < v.size(); ++i)
		{
			combos(combinations, rem(v, i), prime);
		}
	}
}

ll replace_at_indexes(ll prime, vector<int> indexes, int d) {
	string p_str = to_string(prime);
	char check = p_str.at(indexes[0]);
	for (int i = 0; i < indexes.size(); ++i)
	{
		if (d == 0 && i == 0) 
			return 4; ////////////////////////////////////////////////////////////////////////////
		p_str.at(indexes[i]) = d+'0';
	}
	return stoll(p_str);
}

int digit_index(ll num, int digit) {
	string s = to_string(num);
	string d = to_string(digit);

	if (s.find_first_of(d) != string::npos)
		return (s.size() - s.find_first_of(d) - 1);
	return -1;
}

int count_family(ll prime, vector<int> indexes) {
	int count = 0;

	for (int d = 0; d <= 9; ++d)
	{
		if (isprime(replace_at_indexes(prime, indexes, d))) {
			// /cout << replace_at_indexes(prime, indexes, d) << endl;
			count++;
		}
	}

	return count;
}

void kill_family(ll prime, vector<int> indexes) {
	for (int d = 0; d <= 9; ++d)
	{
		if (isprime(replace_at_indexes(prime, indexes, d)))
			slaughter(primes, replace_at_indexes(prime, indexes, d));
	}
}

int max_of_prime(ll prime, int check_char) {
	vector<vector<int>> combinations;
	vector<int> indexes;
	for (int i = 0; i < to_string(prime).size(); ++i)
	{
		if (to_string(prime).at(i) == check_char+'0')
			indexes.push_back(i);
	}
	if (indexes.size() == 0) {
		return 0;
	}
	combos(combinations, indexes, to_string(prime));

	// combinations now complete


	int max = 0;
	for (int i = 0; i < combinations.size(); ++i)
	{
		if (count_family(prime, combinations[i]) > max) {
			max = count_family(prime, combinations[i]);
			// if (max == 8) {
			// 	cout <<"MAX IS 8" << endl;
			// 	for (int j = 0; j < combinations[i].size(); ++j)
			// 	{
			// 		cout << combinations[i][j] << endl;
			// 	}
			// 	cout << endl;
			// }
		}
	}
	// for (int i = 0; i < combinations.size(); ++i)
	// {
	// 	kill_family(prime, combinations[i]);
	// }

	return max;
}

vector<int> get_indexes(ll p, int i) {
	vector<int> indexes;

	for (int k = 0; k < to_string(p).size(); ++k)
	{
		if (digit_index(p, i) != -1) {
			indexes.push_back(digit_index(p, i));
			p += pow(10, digit_index(p, i));
		}
	}

	return indexes;
}

bool contains(string prime, string c) {
	if (prime.find(c) != string::npos)
		return true;
	return false;
}

#define COUNT 8

int main() {

	cout << "hi";

	for (int i = 11; i <= SIZE; i+=2)
	{
		if (i-1 % 1000 == 0) {
			cout << i << endl;
		}
		string s = to_string(i);
		if (isprime(i) && (contains(s, "0") || contains(s, "1") || contains(s, "2"))){
			for (int j = 0; j <= 2; ++j)
			{
				//cout << i << "  " << max_of_prime(i, j) << endl;
				if (max_of_prime(i, j) >= COUNT) {
					cout << "ans: " << i << endl;
					//exit(1);
				}
			}
		}
	}

	// for (int i = 3; i < SIZE; i+=2)
	// {
	// 	if (isprime(i) && max_of_prime(i) >= COUNT) {
	// 		cout << "ans: " << i << endl;
	// 		break;
	// 	}
	// }
}

// wrong ans: 997651
// 111109


/*

999109
333109







// best reason not to do a terrible solution and then think you gotta stick to it:

/*
void combos(vector<int> &combinations, vector<int> indexes) {
	ll increment = 0;
	for (int i = 0; i < indexes.size(); ++i)
	{
		increment += pow(10, indexes[i]);
	}
	combinations.push_back(increment);

	if (indexes.size() > 1) {
		for (int i = 0; i < indexes.size(); ++i)
		{
			combos(combinations, rem(indexes, i));
		}
	}
}

vector<int> get_indexes(ll p, int i) {
	vector<int> indexes;

	for (int k = 0; k < to_string(p).size(); ++k)
	{
		if (digit_index(p, i) != -1) {
			indexes.push_back(digit_index(p, i));
			p += pow(10, digit_index(p, i));
		}
	}

	return indexes;
}

int count_replacements(ll p, int i) {
	vector<int> combinations; // combinations is a vector of increments
	int count;

	vector<int> indexes = get_indexes(p, i);

	combos(combinations, indexes);

	for (int b = 0; b < combinations.size(); ++b)
	{
		//cout << "combo #" << b << ": " << combinations[b] << endl;
		count = 0;
		int temp_p = p;
		for (int m = 0; m < 10; ++m)
		{
			//cout << " i: " << i << endl;
			//cout << "temp_p: " << (temp_p+((combinations[b]*(m))%(combinations[b]*(10-i)))) << endl;
			//temp_p = ((combinations[b]*(m+i))%(combinations[b]*10));
			if (isprime(temp_p + ((combinations[b]*(m))%(combinations[b]*(10-i))))) {
				//cout << "prime: " << temp_p << endl;
				count++;
			}
		}
		if (count >= 8) {
			cout << "ans: " << p << endl;
			// /exit(1);
		}
	}
}

void check_prime(vector<ll> primes, ll p) {
	for (int i = 0; i <= 2; ++i)
	{
		if (digit_index(p, i) != -1) {
			//cout << p << " " << i << endl;
			count_replacements(p, i);
		}
	}
}

int main() {
	
	vector<ll> primes;

	for (int i = 11; i < SIZE; i+=2)
	{
		if (isprime(i))
			primes.push_back(i);
	}

	for (int i = 0; i < primes.size(); ++i)
	{
		check_prime(primes, primes[i]);
		//slaughter(primes, primes[i]);
		//cout << primes[i] << endl;
	}


	//check_prime(primes, 103);

	//check_prime(primes, 92227);

	// vector<int> temp = get_indexes(506003, 0);
	// for (int i = 0; i < temp.size(); ++i)
	// {
	// 	cout << temp[i] << endl;
	// }

	// vector<int> c;
	// combos(c, temp);

	// for (int i = 0; i < c.size(); ++i)
	// {
	// 	//cout << "   " << to_string(c[i]).size() << endl;
	// 	for (int k = 0; k < (5-to_string(c[i]).size()); ++k)
	// 	{
	// 		cout << "0";
	// 	}
	// 	cout << c[i] << endl;
	// }

}


*/