#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <regex>
#include <thread>
#include <random>
#include <array> 
#include <map> 
#include <unordered_map>
#include <forward_list>
#include <list> 
#include <queue> 
#include <stack> 
#include <vector> 
#include <set> 
#include <unordered_set>

using namespace std;

int main(){

	cout<<endl<<endl<<"--------------------    Map     --------------------------"<<endl<<endl;
	
	/*

   Map(Dictionary) 
   
   Methods:
   
   insert(pair<data type, data type>(value, value))
   first (key), .second (value of the key)
   
	*/
	
	map<string, list<string>> people;
	
	list<string> lang1 {"c", "java", "python"};
	list<string> lang2 {"c++", "c#", "javascript"};
	
	people.insert(pair<string, list<string>>("Gian", lang1));
	people.insert(pair<string, list<string>>("Kianna", lang2));
	
	for (auto name : people){
		cout<<name.first<<" - ";
		for (auto lang : name.second){
			cout<<lang<<", ";
		}
		cout<<endl;
	}
		
	cout<<endl<<endl<<"--------------------   Stack    --------------------------"<<endl<<endl;
	
	/*  

	Stack follow the rule - Last in, first out, last come, first serve
	
	Methods: 
	
	empty 
	push
	pop
	top
	
	*/
	
	stack<int> nums;
	
	if (nums.empty()) cout<<"Stack is empty"<<endl;
	else cout<<"Stack is not empty"<<endl;
	
	for (int x = 1; x <= 5; x++){
		cout<<"Pushing "<<x<<" to stack."<<endl;
		nums.push(x);
	}
	
	string isEmpty = (nums.empty()) ? "yes" : "no";
	
	cout<<"is stack empty: "<<isEmpty<<endl;
	
	cout<<"size of stack: "<<nums.size()<<endl;
	
	nums.pop();
	nums.pop();
	
	cout<<"size of stack after two pop(): "<<nums.size()<<endl;
	
	//Use top() with pop() to print the stack
	while (!(nums.empty())){
		cout<<nums.top()<<endl;
		nums.pop();
	}
	
	/*
	
	using list library we can declare list<data type> which is considered as doubly linked list
	
	Methods:
	
	assign
	front
	back
	empty
	max_size
	clear
	insert
	emplace
	push_back
	pop_back
	push_front
	pop_front
	reverse
	sort
	merge
	splice
	unique -> removes dups if and only if the two nodes are adjacent unless sort() is used
	remove_if
	resize
	
	*/
	
	cout<<"doubly linked list (map library)"<<endl;
	
	list<int> l = {2, 4, 6, 8, 10};
	
	for (auto iterator = l.begin(); iterator != l.end(); iterator++) cout<<*iterator<<endl;
	
	cout<<endl<<endl<<"--------------------   Vector  --------------------------"<<endl<<endl;
	
	/* incomplete
	
	Vector is similar to arrays wherein you can access elements through an index
	though a vector is dynamic unlike an array wherein the size is fixed.
	
	Methods:
	
	push_back 
	pop_back
	max_size - max num of e that can be added to a vector
	capacity - how many elements you can add to a vector before resizing
	resize(new size)
	at() - same like vector[index]
	front - first element
	back - last element
	clear
	insert(index, element you want to add)
	erase(index)
	
	*/
	
	vector<int> n;
	
	for (int x = 1; x <= 5; x++) n.push_back(x);
	
	//we can use iterators aside from ranged loops, loops
	for (auto iterator = n.begin(); iterator != n.end(); iterator++) {
		//*it = 20; if we use cbegin(), cend(), the iterator will be constant
		cout<<*iterator<<endl; //value
		cout<<&iterator<<endl; //address of iterator
		cout<<&(*iterator)<<endl; //address of element
	}
	
	auto ite = n.begin();
	
	cout<<*(ite + 2);
	
	cout<<endl<<endl<<"--------------------   Queue   --------------------------"<<endl<<endl;
	
	/*
	Queue follows the rule first in, first out unlike stacks wherein the last element gets
	removed first.
	
	Methods:
	
	push
	pop
	front
	back
	
	*/
	
	queue<int> q;
	
	cout<<"Size of queue before pushing: "<<q.size()<<endl;
	
	for (int x = 1; x <= 6; x++){
		cout<<"Pushing "<<x<<" to queue"<<endl;
		q.push(x);
	}
	
	cout<<"Size of queue after 6 pushes: "<<q.size()<<endl;
	
	q.pop();
	q.pop();
	
	cout<<"Size of queue after 2 pops: "<<q.size()<<endl;
	
	cout<<"Queue:"<<endl;
	
	
	
	
	
	cout<<endl<<endl<<"--------------------    Set    --------------------------"<<endl<<endl;
	
	/*
	Set is like a map which only contains elements that will be ordered in ascending 
	it also removes the duplicate elements in the set.
	
	Methods:
	
	insert
	erase
	find(element)
	*/
	
	set<string> s;
	s.insert("C++");
	s.insert("Javascript");
	s.insert("C#");
	s.insert("Sql");
	s.insert("Java");
	s.insert("Python");
	s.insert("Kotlin");
	s.insert("Swift");
	s.insert("C++");
	s.insert("C");
	
	cout<<"Set: "<<endl;
	for (auto iterator = s.begin(); iterator != s.end(); iterator++) cout<<*iterator<<endl;
	
	cout<<"Check if C++ exists: ";
	
	if (s.find("C++") == s.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	
	cout<<"After deleting C++: ";
	
	s.erase("C++");
	
	if (s.find("C++") == s.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	
	return 0;
}
