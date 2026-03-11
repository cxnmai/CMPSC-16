// file: functions.cpp for newanagrams
#include "headers.h"
#include <cctype>
#include <iostream>
// Define all member functions for class AString
//    as well as all other functions that need definition

AString::AString() {
    StringValue = "";
}

AString::AString(string sv) {
    StringValue = sv;
}

string AString::getStringValue() {
    return StringValue;
}

void AString::cleanUp() {
    string cleaned = "";
    for (char c : StringValue) {
        if (isalpha(c)) cleaned += tolower(c);
    }
    StringValue = cleaned;
}

void AString::countLetters(int (&letters)[26]) {
    cleanUp();
    for (char c : StringValue) letters[c - 97]++;
}

void AString::getAString() {
    cout << "Enter string value: ";
    string sv;
    getline(cin, sv);
    StringValue = sv;
}

bool compareCounts(int a[], int b[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}