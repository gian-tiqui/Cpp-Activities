#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

bool find_dupes(vector<int> v, int t);

int main() {
	
	srand(time(NULL));
	
	map<string, vector<string>> deck;
	vector<string> spades, diamonds, clubs, hearts;
	vector<string> my_cards, n;
	vector<int> nums_c, nums_n;
	vector<string> cover;
	
	n.push_back("Ace");
	n.push_back("2");
	n.push_back("3");
	n.push_back("4");
	n.push_back("5");
	n.push_back("6");
	n.push_back("7");
	n.push_back("8");
	n.push_back("9");
	n.push_back("10");
	n.push_back("Jack");
	n.push_back("Queen");
	n.push_back("King");
	
	for(int i = 0; i < n.size(); i++) {
		spades.push_back(n[i]);
		diamonds.push_back(n[i]);
		clubs.push_back(n[i]);
		hearts.push_back(n[i]);
	}
	
	deck.insert(pair<string, vector<string>>("Spades", spades));
	deck.insert(pair<string, vector<string>>("Diamonds", diamonds));
	deck.insert(pair<string, vector<string>>("Clubs", clubs));
	deck.insert(pair<string, vector<string>>("Hearts", hearts));
	
	cout<<"Deck: \n";
	
	for (auto i: deck) {
		cout<<i.first<<": ";
		for (auto j: i.second) 
			cout<<j<<" ";
		cout<<"\n";
	}
	
	int amount;
	
	cout<<"enter amount (max 8, min 4): ";
	cin>>amount;
	
	if(amount >= 4 && amount <= 8) {
		
		for(auto i: deck) 
			cover.push_back(i.first);
		
		for(int i = 0; i < amount; i++) {
			int random_n = rand() % 13;
		
			if (find_dupes(nums_n, random_n)) 
				i--;
			else 
				nums_n.push_back(random_n);	
		}
		
		for(int i = 0; i < amount; i++) {
			int random_n = rand() % 4;
			
			nums_c.push_back(random_n);
		}                          
		
		for(int i = 0; i < amount; i++) 
			my_cards.push_back(n[nums_n[i]] + " of " + cover.at(nums_c[i]));

		for(auto i: my_cards)
			cout<<i<<"\n";
	}
	
}

bool find_dupes(vector<int> v, int t) {
	
	sort(v.begin(), v.end());
	
	for (int i: v) 
		if (i == t)
			return true;
	
	return false;
}
