#include <iostream>
using namespace std;

void displayGeometricSequence(int firstTerm, int commonRatio, int numTerms) {
    int term = firstTerm;
    
    cout << "Geometric Sequence: ";
    
    for (int i = 0; i < numTerms; ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << term;
        term *= commonRatio;
    }
    
    cout << endl;
}

void run_geometric_seq() {
    cout << "Geometric Sequence Simulator" << endl;
    
    int firstTerm, commonRatio, numTerms;
    
    cout << "Enter the first term: ";
    cin >> firstTerm;
    
    cout << "Enter the common ratio: ";
    cin >> commonRatio;
    
    cout << "Enter the number of terms: ";
    cin >> numTerms;
    
    displayGeometricSequence(firstTerm, commonRatio, numTerms);
}