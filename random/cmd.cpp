#include<iostream>

using namespace std;

void change_nums(int n[]) {
	for (int i = 0, j = 100; i < 5; i++, j+=100) n[i] = j; 
}

void change_nums2(int *n) {
	for (int i = 100; i <= 500; i+=100, n++) *n = i;
}

int main(){

	int nums[5] = {1, 2, 3, 4, 5};
	
	change_nums(nums);
	
	for (int i : nums) cout<<i<<endl;
	
	
	change_nums2(nums);
	
	for (int i : nums) cout<<i<<endl;
	
	return 0;
}
