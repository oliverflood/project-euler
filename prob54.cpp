#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define ll long long

// done
int check_value(vector<string> hand, char c) {
	for (int i = 0; i < hand.size(); ++i)
	{
		if (hand[i].at(0) == c) {
			return i;
		}
	}
	return -1;
}

// done
bool flush(vector<string> hand) {
	char c = hand[0].at(1);
	for (int i = 0; i < hand.size(); ++i)
	{
		if (hand[i].at(1) != c) {
			return false;
		}
	}
	return true;
}

// done
bool royal(vector<string> hand) {
	vector<char> temp = {'T', 'J', 'Q', 'K', 'A'};

	if (!flush(hand)) {
		return false;
	}

	for (int i = 0; i < temp.size(); ++i)
	{
		if (check_value(hand, temp[i]) == -1)
			return false;
	}
	return true;
}

// done
bool straight(vector<int> vhand) {
	sort(vhand.begin(), vhand.end());

	for (int i = 0; i < vhand.size()-1; ++i)
	{
		if (vhand[i] != vhand[i+1]-1) {
			return false;
		}
	}
	return true;
}

// // not done
// bool x_of_a_kind(int x, vector<int> hand) {
// 	// vhand
// 	sort(hand.begin(), hand.end());
// 	int current = hand[0];
// 	int count = 0;
// 	for (int i = 0; i < hand.size(); ++i)
// 	{
// 		if (current = hand[i]) {
// 			count++;
// 		}
// 		else {
// 			count = 0;
// 		}
// 		if (count == x)
// 			return true;
// 	}
// 	return false;
// }

bool contains(vector<int> v, int e) {
	if (find(v.begin(), v.end(), e) != v.end())
		return true;
	return false;
}

int pos(vector<int> v, int e) {
	if (find(v.begin(), v.end(), e) != v.end())
		return (find(v.begin(), v.end(), e)-v.begin());
	return -1;
}

// freq count of cards
vector<int> freq_count(vector<int> vhand) {
	vector<int> ans;
	vector<int> seen;

	for (int i = 0; i < vhand.size(); ++i)
	{
		if (contains(seen, vhand[i])) {
			ans[pos(seen, vhand[i])] += 1;
		}
		else {
			seen.push_back(vhand[i]);
			ans.push_back(1);
		}
	}
	
	return ans;
}

vector<int> create_values(vector<string> hand) {
	vector<int> ans;
	vector<char> temp = {'T', 'J', 'Q', 'K', 'A'};

	for (int i = 0; i < hand.size(); ++i)
	{
		if (hand[i].at(0) <= '9' && hand[i].at(0) >= '2')
			ans.push_back(hand[i].at(0)-'0');
		else {
			ans.push_back(10+(find(temp.begin(), temp.end(), hand[i].at(0))-temp.begin()));
		}
	}

	return ans;
}

// true if p1 wins, untested but should be done
bool tiebreak(vector<int> p1_values, vector<int> p2_values) {
	sort(p1_values.begin(), p1_values.end());
	sort(p2_values.begin(), p2_values.end());

	// need to look at highest card in largest group, then work down
	vector<int> ans1;
	vector<int> seen1;

	for (int i = 0; i < p1_values.size(); ++i)
	{
		if (contains(seen1, p1_values[i])) {
			ans1[pos(seen1, p1_values[i])] += 1;
		}
		else {
			seen1.push_back(p1_values[i]);
			ans1.push_back(1);
		}
	}

	vector<int> ans2;
	vector<int> seen2;

	for (int i = 0; i < p2_values.size(); ++i)
	{
		if (contains(seen2, p2_values[i])) {
			ans2[pos(seen2, p2_values[i])] += 1;
		}
		else {
			seen2.push_back(p2_values[i]);
			ans2.push_back(1);
		}
	}

	// checks all the random tiebreak stuff too lazy to comment 

	// if both have 4
	if (contains(ans1, 4) && contains(ans2, 4)) {
		if (seen1[pos(ans1, 4)] > seen2[pos(ans2, 4)]) {
			return true;
		}
		else if (seen1[pos(ans1, 4)] < seen2[pos(ans2, 4)]) {
			return false;
		}
	}

	// if both have 3
	if (contains(ans1, 3) && contains(ans2, 3)) {
		if (seen1[pos(ans1, 3)] > seen2[pos(ans2, 3)]) {
			return true;
		}
		else if (seen1[pos(ans1, 3)] < seen2[pos(ans2, 3)]) {
			return false;
		}
	}

	// if both have 2
	if (contains(ans1, 2) && contains(ans2, 2)) {
		if (seen1[pos(ans1, 2)] > seen2[pos(ans2, 2)]) {
			return true;
		}
		else if (seen1[pos(ans1, 2)] < seen2[pos(ans2, 2)]) {
			return false;
		}
	} 
	// end of bullshit


	// good shit
	for (int i = 4; i >= 0; i--)
	{
		if (p1_values[i] > p2_values[i])
			return true;
		if (p2_values[i] > p1_values[i])
			return false;
	}

	cout << "We should never have this happen..." << endl;
	exit(1);
}

bool highest_card(vector<int> p1_values, vector<int> p2_values) {
	sort(p1_values.begin(), p1_values.end());
	sort(p2_values.begin(), p2_values.end());

	// good shit
	for (int i = 4; i >= 0; i--)
	{
		if (p1_values[i] > p2_values[i])
			return true;
		if (p2_values[i] > p1_values[i])
			return false;
	}

	cout << "We should never have this happen..." << endl;
	exit(1);
}

bool two_pairs(vector<int> freq) {
	if (contains(freq, 2)) {
		freq.erase(freq.begin()+pos(freq, 2));
		if (contains(freq, 2)) {
			return true;
		}
	}
	return false;
}

void printv(vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}

bool p1win(vector<string> hand) {
	// hands
	vector<string> p1(hand.begin(), hand.begin()+5);
	vector<string> p2(hand.begin()+5, hand.end());

	cout << endl;
	cout << "  ";
	printv(p1);
	cout << "    ";
	printv(p2);
	cout << endl; 

	vector<int> p1_values = create_values(p1);
	vector<int> p2_values = create_values(p2);

	vector<int> p1_freq = freq_count(p1_values);
	vector<int> p2_freq = freq_count(p2_values);


	// royal flush
	if (royal(p1) && royal(p2)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (royal(p1)) {
		return true;
	}
	else if (royal(p2)) {
		return false;
	}

	// straight flush
	if (straight(p1_values) && straight(p2_values) && flush(p1) && flush(p2)) {
		return highest_card(p1_values, p2_values);
	}
	else if (straight(p1_values) && flush(p1)) {
		return true;
	}
	else if (straight(p2_values) && flush(p2)) {
		return false;
	}

	// four of a kind
	if (contains(p1_freq, 4) && contains(p2_freq, 4)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (contains(p1_freq, 4)) {
		return true;
	}
	else if (contains(p2_freq, 4)) {
		return false;
	}

	// full house
	if (contains(p1_freq, 3) && contains(p1_freq, 2) && contains(p2_freq, 3) && contains(p2_freq, 2)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (contains(p1_freq, 3) && contains(p1_freq, 2)) {
		return true;
	}
	else if (contains(p2_freq, 3) && contains(p2_freq, 2)) {
		return false;
	}

	// flush
	if (flush(p1) && flush(p2)) { // flush can be determined later
		return highest_card(p1_values, p2_values);
	}
	else if (flush(p1)) {
		return true;
	}
	else if (flush(p2)) {
		return false;
	}

	// straight
	if (straight(p1_values) && straight(p2_values)) {
		return highest_card(p1_values, p2_values);
	}
	else if (straight(p1_values)) {
		return true;
	}
	else if (straight(p2_values)) {
		return false;
	}

	// three of a kind
	if (contains(p1_freq, 3) && contains(p2_freq, 3)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (contains(p1_freq, 3)) {
		return true;
	}
	else if (contains(p2_freq, 3)) {
		return false;
	}

	// two pairs
	if (two_pairs(p1_freq) && two_pairs(p2_freq)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (two_pairs(p1_freq)) {
		return true;
	}
	else if (two_pairs(p2_freq)) {
		return false;
	}

	// one pair
	if (contains(p1_freq, 2) && contains(p2_freq, 2)) {
		return tiebreak(p1_values, p2_values);
	}
	else if (contains(p1_freq, 2)) {
		return true;
	}
	else if (contains(p2_freq, 2)) {
		return false;
	}

	// highest card
	return tiebreak(p1_values, p2_values);


}

void printv(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}



int main() {
	
	ifstream poker;
	poker.open("poker.txt");

	vector<vector<string>> hands;

	while (!poker.eof()) {
		vector<string> temp;
		for (int i = 0; i < 10; ++i)
		{
			string s;
			poker >> s;
			temp.push_back(s);
		}
		hands.push_back(temp);
	}

	int final_ans = 0;

	//hands = {{"5H", "5C", "6S", "7S", "KD", "2C", "3S", "8S", "8D", "TD"}};

	for (int i = 0; i < hands.size(); ++i)
	{
		cout << "i: " << i << "   ";
		printv(hands[i]);
		cout << "   result: p " << abs(p1win(hands[i])-2) << " win" << endl;
		if (p1win(hands[i])) {
			final_ans++;
		}
	}

	// vector<int> hand = {4,4,5,5,5};


	// printv(hand);
	// printv(freq_count(hand));




	cout << "ans: " << final_ans << endl << endl;

	vector<int> x1 = {2,4,5,6,7};
	vector<int> x2 = {3,4,5,6,7};

	cout << tiebreak(x1, x2) << endl;
}

//351 wrong

