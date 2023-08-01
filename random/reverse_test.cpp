#include<iostream>

using namespace std;

void reverse(int arr[], int start, int end);

int main(){

	int arr[5] = {5, 3, 4, 1, 2};
	
	for(int i = 0; i < 5; i++)
		cout<<arr[i]<<endl;
	
	return 0;
}

void reverse(int arr[], int start, int end) {
	
	if(start <= end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		
		reverse(arr, start + 1, end - 1);
	} else
		return;
	
}