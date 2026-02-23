// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments

bool isPalindrome(string s) {
    // pre condition: string
    // post condition: returns true if the string reversed is equal to the string, false if otherwise
    if (s == "" || s.size() == 1) return true; // base case empty if even letters in string or 1 middle letter if odd letters
    else return (s[0] == s[s.size() - 1]) && isPalindrome(s.substr(1, s.size() - 2)); // else check first and last letters, then recursively check for next set
}

void cleanUp(string &s) {
   // pre condition: string
   // post condition: string is stripped of non alpha characters and all letters are converted to lowercase
    string res = "";
    for (char c : s) {
        if (isalpha(c)) {
            res += tolower(c);
        }
    }
    s = res;
}
