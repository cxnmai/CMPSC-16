/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;

// Declare printV() here

void printV(long num);

int main() {
    // 1. Get user input
    // 2. Check input and pass it on to printV()
    cout << "Enter integer: ";
    long num;
    cin >> num;
    
    if (num < 0) {
        cout << "Input must be a positive integer.\n";
        return 0;
    }
    printV(num);
    

    return 0;
}

void printV(long num) {
    // pre condition: positive integer value
    // post condition: prints digits of the number vertically starting from the most significant digit
    if (num < 10) { // base case, check for final digit
        cout << num << "\n";
    }
    else {
        printV(num / 10);
        cout << (num % 10) << "\n";
    }
}
