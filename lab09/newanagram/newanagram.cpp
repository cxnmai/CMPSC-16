/* 
 * NEWANAGRAM.CPP by Ziad Matni (c) 2024
 * For use in CS16 labs 
 *
 * DO NOT CHANGE ANYTHING ALREADY IN THIS PROGRAM!
 * Students should fill in the places where it says *** MISSING CODE HERE! ***
 */
#include <iostream>
#include <string>
using namespace std;

#include "headers.h"

int main() {
    // 1. Declare 2 objects of AString,
    //      construct as asked to (see PDF document), 
    //      get the string values using class --member function-- getStringValue(),
    //      print the string values
    AString sentence1, sentence2("nothing");
    cout << "Two objects declared with values: ";
    cout << sentence1.getStringValue() << " and ";
    cout << sentence2.getStringValue() << endl;


    // 2. Get user inputs using class --member function-- getAString()
    //      and clean up the strings using class --member function-- cleanUp()

    sentence1.getAString();
    sentence2.getAString();

    // 3. Set up 2 arrays and initialize to all zeros
    //      and count letters in the strings using class --member function-- countLetters()

    int ca1[26] = {0}, ca2[26]={0};
    sentence1.countLetters(ca1);
    sentence2.countLetters(ca2);


    // 4. Use external function compareCounts to decide
    //      if the 2 strings are anagrams of each other or not

    bool badCount = !compareCounts(ca1, ca2);

    if (badCount) {
        cout << "The strings are not anagrams.\n";
    } else {
        cout << "The strings are anagrams.\n";
    }

    return 0;
}

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