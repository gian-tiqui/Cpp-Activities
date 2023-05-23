#include<iostream>
#include<Windows.h>
#include<vector>
#include<ctime>
#include <stdlib.h>

using namespace std;

struct Meow {
	
	int hour, min, sec;
	
	Meow(int hour, int min, int sec) {
		this->hour = hour;
		this->min = min;
		this->sec = sec;
	}
	
};

void print_bx(string border, int len) {
	
	for (int i = 0; i < len; i+=3)
		cout<<border<<"  ";
		
}

void print_by(string border, int len) {
	
	cout<<"\n"<<border;
	
	for (int i = 1; i < len - 2; i++) 
		cout<<" ";
		
	cout<<border<<"\n";
}

void print_y(int len) {
	
	for (int i = 0; i < len; i++) 
		cout<<"\n";
	
}

void add_space(int len) {
	
	for (int i = 0; i < len; i++)
		cout<<" ";
		
}

int main(){

	bool False = true;
	vector<Meow> v;

	while (False) {
		system("CLS");
		time_t curr_t = time(NULL);
		tm *tm_l = localtime(&curr_t);
		int hour = tm_l->tm_hour, min = tm_l->tm_min, sec = tm_l->tm_sec;
		Meow t(hour, min, sec);
		v.push_back(t);
		
		print_y(5);
		print_bx("=", 25);
		print_y(1);
		print_by("=", 26);
		print_by("=", 26);
		cout<<"\t"<<t.hour<<":"<<t.min<<":"<<t.sec;
		print_by("=", 26);
		print_by("=", 26);
		print_y(1);
		print_bx("=", 25);
		sleep(1);
	}
	
}
