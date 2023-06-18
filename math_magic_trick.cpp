// Example program
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

#define SET_COUNT 15

using namespace std;

int numberSet[5][SET_COUNT] = {
    //Set A
    {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29},
    //Set B
    {2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30},
    //Set C
    {4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30},
    //Set D
    {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30},
    //Set E
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
};

int arrangement[5];

bool isWithinSet(int set[5], int number);
void generateRandomNumbers();
bool isNumberInSet(int setIndex);
int getUsersNumber();

int main() {
    char input; bool isRunning = true;
   
    do {
        cout << "Welcome to the Math Magic Trick Program..." << endl;
    	cout << "Think of a number from 1 to 30, then I am going to show you random sets of numbers." << endl;
	    cout << "Please tell me if your number is within the set I provide." << endl;
	    cout << "Please enter any alphanumeric character to proceed...";
    	cin >> input;
    	
    	if(
    	    (input >= 65 && input <= 90) || 
    	    (input >= 97 && input <= 122) || 
    	    (input >= 48 && input <= 57)//isalnum()
    	) {
    	    cout << endl << "I am going to show you random sets of numbers, please tell me if your number is within the set I provide." << endl;
    	    
    	    generateRandomNumbers();
    	    int number = getUsersNumber();
    	    if(number == 0){
    	        cout << "You are trying to fool me." << endl;
    	    } else {
    	        cout << "Okay. Let me guess, your number is " << number << "." << endl;
    	    }
    	    cout << "Do you want to try again? Enter 'Y' or 'N': ";
    	    cin >> input;
    	    
    	    isRunning = (input == 'Y' || input == 'y');
    	} else {
    	    cout << "You have entered an invalid input." << endl;
    	}
    } while(isRunning);
    
    return 0;
}

bool isWithinSet(int set[5], int number){
    for(int i = 0; i < 5; i++){
        if(set[i] == number) return true;
    }
    return false;
}

void generateRandomNumbers(){
    int count = 0, randomNumber = 0;
    
    for(int i = 0; i < 5; i++) arrangement[i] = 0;
    
	// Generate and output random numbers.
	srand((unsigned) time(0));
	
	while(count < 5){
	    randomNumber = 1 + rand() % 5;
	    if(isWithinSet(arrangement, randomNumber)) continue;
	    arrangement[count] = randomNumber;
	    count++;
	}
}

bool isNumberInSet(int setIndex){
    char choice;
    for(int i = 0; i < SET_COUNT; i++){
        cout << numberSet[setIndex][i];
        if(i == SET_COUNT - 1) continue;
        cout << ", ";
        if((i+1) % 3 == 0) cout << endl;
    }
    
    cout << endl << "Is your number within this set of numbers? Enter 'Y' or 'N': ";
    cin >> choice;
    
    return (choice == 'Y' || choice == 'y');
}

int getUsersNumber(){
    int total = 0, count = 0;
    char sets[] = {'A', 'B', 'C', 'D', 'E'};
    for(int n : arrangement){
        cout << "Set " << sets[count++] << endl;
        if(isNumberInSet(n-1)) total += numberSet[n-1][0];//arrangement[i]-1
    }
    return total;
}