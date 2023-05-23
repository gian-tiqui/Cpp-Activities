#include <bits/stdc++.h>
// #include<iostream>

using namespace std;

string *holder(string str) {

	string *ptr = &str;

	return ptr;
}

void use_holder() {
	vector<string> v;

	string s = *holder("meow");

	cout << *(&s) << endl;

	v.push_back(s);

	for (auto i : v)
		cout << &i << endl;
}

int main() {

	use_holder();

	return 0;
}
