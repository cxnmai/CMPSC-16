/*
/ Skeleton File for FUNCTIONS.CPP for CS16, UCSB
/ Copyright © 2026 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 5 LINES - DO NOT ADD TO THEM
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// INCLUDE HEADER FILE(S) HERE:
#include "constants.h"

// The following function is defined for you. ***Do not change it AT ALL.***
//
// Pre-Condition: takes in an ifstream object for input file,
//              a string for an input filename, an integer array and its size
// Post-Condition: the array will be populated with all the numbers from the input file
void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() )
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}

// Add your 8 functions definitions below:
//

void print_array(int arr[], int asize) {
    for (int i = 0; i < asize; i++) { // iterate every element of arr[]
        if (i == asize - 1) cout << arr[i]; // if last element, only print value without comma
        else cout << arr[i] << ", ";
    }
    cout << endl;
}

int maxArray(int arr[], int asize) {
    int max = arr[0]; // start max at first element

    for (int i = 0; i < asize; i++) { // iterate every element of arr[]
        if (arr[i] > max) max = arr[i]; // if value is larger than current max, update it
    }

    return max;
}

int minArray(int arr[], int asize) {
    int min = arr[0]; // start min at first element

    for (int i = 0; i < asize; i++) { // iterate every element of arr[]
        if (arr[i] < min) min = arr[i]; // if value is smaller than current min, update it
    }

    return min;
}

int sumArray(int arr[], int asize) {
    int sum = 0;

    for (int i = 0; i < asize; i++) { // iterate every element of arr[]
        sum += arr[i]; // add value to sum
    }

    return sum;
}

void evensArray(int arr[], int asize) {
    cout << "Evens: ";
    for (int i = 0; i < asize; i++) { // iterate every element of arr[]
        if (arr[i] % 2 == 0) { // check if it's even
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl; // mark end
}

void primesArray(int arr[], int asize) {
    cout << "Primes: ";
    bool printed_any = false;
    for (int i = 0; i < asize; i++) {
        int num = arr[i]; // declare variable for value under current iteration for conciseness

        if (num < 2) continue;
        bool isPrime = (num == 2);
        if (num > 2) {
            isPrime = true;
            for (int j = 2; j < num; j++) { // iterate every number from 2 to num - 1
                if (num % j == 0) { // check if it's a factor; if it's divisble then not prime
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            if (printed_any) cout << ", ";
            cout << num;
            printed_any = true;
        }
    }
    if (printed_any) cout << ", ";
    cout << "end" << endl;
}

int SeqSearch(int arr[], int array_size, int target) {
    for (int i = 0; i < array_size; i++) {
        if (arr[i] == target) return i; // return index of value if it's equal to target
    }

    return -1; // -1 if value is not present
}

void AllSearches(int array[], int array_size) {
    cout << "Searches:" << endl;
    for (int i = 0; i < NSEARCHES; i++) { // iterate every value of SEARCHES
        cout << "Looking for " << SEARCHES[i] << ". ";

        int index = SeqSearch(array, array_size, SEARCHES[i]); // call SeqSearch on array[]

        if (index == -1) cout << "Not Found!" << endl; // if index is -1 then not found
        else cout << "Found at index: " << index << endl;
    }
}
