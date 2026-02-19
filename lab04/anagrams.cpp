#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2);

int main()
{
    string s1;
    string s2;
    
    cout << "Enter first string:" << endl;
    getline(cin, s1);
    cout << "Enter second string:" << endl;
    getline(cin, s2);
    
    if (isAnagram(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
}

string clean(string str) { // to clean strings prior to comparison
    string result = ""; // result to append to
    for (int i = 0; i < str.size(); i++) {
        char c = str[i]; // for conciseness

        if ((c >= 65) && (c <= 90)) { // if its capital (from ASCII)
            result += c + 32; // by decimal value
        } else if (!((c >= 97) && (c <= 122))) { // if its not a lowercase letter
            continue; // skip it
        } else {
            result += c; // if it got here it's a regular lowercase so just append it
        }
    }

    return result;
}


bool isAnagram(string s1, string s2) {
    // empty arrays of length 26, each index representing a letter
    int chars1[26] = {0};
    int chars2[26] = {0};
    
    // clean both strings
    s1 = clean(s1);
    s2 = clean(s2);
    
    // initialize letter counts for s1 and s2
    for (int i = 0; i < s1.size(); i++) {
        chars1[s1[i] - 97] += 1; // lowercases start from 97 so subtrack to get 0-25 indexes
    }

    for (int i = 0; i < s2.size(); i++) {
        chars2[s2[i] - 97] += 1;
    }


    for (int i = 0; i < 26; i++) {
        if (chars1[i] != chars2[i]) return false; // if the count of a letter doesn't match then it's not an anagram
    }

    return true; // otherwise it's true
}