// file: functions.cpp for newanagrams
#include "headers.h"
#include <cctype>
#include <iostream>
// Define all member functions for class AString
//    as well as all other functions that need definition

AString::AString() {
    // pre condition - none, constructor
    // psot condition - initializes AString with empty stirng
    StringValue = "";
}

AString::AString(string sv) {
    // pre condition - string value
    // post condition - initializes AString with given string
    StringValue = sv;
}

string AString::getStringValue() {
    // pre condition - initialized AString
    // post condition - returns StringValue
    return StringValue;
}

void AString::cleanUp() {
    // pre condition - initialized stringvalue
    // post condition - removes all non alpha characters and converts remaining to lowercase
    string cleaned = "";
    for (char c : StringValue) {
        if (isalpha(c)) cleaned += tolower(c);
    }
    StringValue = cleaned;
}

void AString::countLetters(int (&letters)[26]) {
    // pre condition - array of length 26
    // post condition - array values equivalent to number occurrences of that letter in AString
    cleanUp();
    for (char c : StringValue) letters[c - 97]++;
}

void AString::getAString() {
    // pre condition - constructed A string
    // post condition - initializes StringValue as user's input
    cout << "Enter string value: ";
    string sv;
    getline(cin, sv);
    StringValue = sv;
}

bool compareCounts(int a[], int b[]) {
    // pre condition - two arrays of length 26
    // post condition - true if all array values are equal, false if otherwise
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}