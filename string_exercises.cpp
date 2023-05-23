#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

bool is_palindrome(string str); // (Easy) create a function that will check if a string is palindrome. example: "hooh" and "a" will return true and "Michael" will return false

bool is_reverse(string o_str, string r_str); // (Easy) create a function that will check if the r_string is the reversed version of o_string. example: ("Gian", "naiG") will return true

string pass_generator(); // (Easy) create a password generator with symbols, letters, numbers

string reverse(string str);

string trim_start(string str, int amount);

string trim_end(string str, int amount);

string add_space(string str);

string mock(string str);

string stw_sub(int start, int end, string str); // sub function of sentence_to_words
vector<string> sentence_to_words(string sentence); // (Medium) create a function that will return a vector containing the words from the sentence. you might need a subfunction for this

bool is_anagram(string s1, string s2); // (Easy) create a function to check if two strings are anagram

//meow

int find_dupes(int a[]);

int main() {
    
    
	  
    return 0;
}

/*
================================================================================================================================================================================================================================================================================================================================================  
























================================================================================================================================================================================================================================================================================================================================================  
*/

bool is_reverse(string o_str, string r_str) {
	
	if (o_str.size() != r_str.size()) {
		cout<<"Words does not have same size."<<endl;
		return false;
	}
	
	for (int s = 0, e = r_str.size() - 1; s <= e; s++, e--) {
		if (tolower(o_str[s]) != tolower(r_str[e])) 
			return false;
	}
	
	return true;
}

bool is_palindrome(string str) {
	
	for (int s = 0, e = str.size() - 1; s <= e; s++, e--) {
		if (str[s] != str[e]) 
			return false;
	}
	
	return true;
}

string pass_generator() {
	
	srand(time(NULL));
	
	string uc_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", lc_letters = "abcdefghijklmnopqrstuvwxyz", numbers = "0123456789", symbols = "@_.#-=><", all, password;
	
	all = uc_letters + lc_letters + numbers + symbols;
	
	for (int i = 0; i < 8; i++) 
		password+=all[rand() % all.size() - 1];
	
	return password;
}

string reverse(string str) {
	
	string reversed;
	
	for (int i = str.size() - 1; i >= 0; i--) 
		reversed+=str[i];
	
	return reversed;
}

string trim_start(string str, int amount) {
	
	string trimmed_str;
	
	for (int i = amount; i < str.size(); i++) 
		trimmed_str+=str[i];
	
	return trimmed_str;
}

string trim_end(string str, int amount) {
	
	string trimmed_str;
	
	for (int i = 0; i < str.size() - amount; i++)
		trimmed_str+=str[i];
	
	return trimmed_str;
}

string add_space(string str) {
	
	string str_with_space;
	
	for (int i = 0; i < str.size(); i++) {
		str_with_space+=str[i];
		str_with_space+=" ";
	}
	
	return str_with_space;
}

string mock(string str) {
	
	srand(time(NULL));
	
	string m_str;
	
	for (int i = 0; i < str.size(); i++) {
		if (rand() % 2 == 0)
			m_str+=toupper(str[i]);
		else
			m_str+=tolower(str[i]); 
	}
	
	return m_str;
}

string stw_sub(int start, int end, string sentence) {
	
	string str;
	
	for (int i = start; i <= end; i++) 
		str+=sentence[i];
	
	return str;
}

vector<string> sentence_to_words(string sentence) {
	
	int i_start, i_end, i_next, size;
	vector<string> words;
	sentence+=" ";
	
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ') {
			size++;
			i_start = i_next;
			i_next = i + 1;
			i_end = i - 1;
			words.push_back(stw_sub(i_start, i_end, sentence));
		} 
		
	}
	
	return words;
}

bool is_anagram(string s1, string s2)  {
	
	if (s1.size() != s2.size()) 
		return false;
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	
	for (int i = 0; i < s1.size(); i++) 
		if (s1[i] != s2[i])
			return false;
			
	return true;
}


int find_dupes(int a[]) {
	
	int t = a[0], h = a[0];

        while(true) {
            t = a[t];
            h = a[a[h]];
            if (t == h)
                break;
        }

        int ptr1 = a[0], ptr2 = t;

        while(ptr1 != ptr2) {
            ptr1 = a[ptr1];
            ptr2 = a[ptr2];
        }

        return ptr1;
}




