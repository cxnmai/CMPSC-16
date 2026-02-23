#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {
    cout << fixed << setprecision(2);
    cout << "Enter filename: ";
    string filename;
    if (!(cin >> filename)) {
        return 0;
    }
    
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Cannot open " << filename << "\n"; // give error if can't find file
        return 1;
    }
    
    
    string last = "  ";
    string line;
    
    int rhyme_pairs = 0;
    int num_lines = 0;
    
    while (getline(inFile, line)) {
        string w = findLastWord(line);
        cleanUp(w);
        num_lines++;
        
        if (w.size() >= 2 && last.size() >= 2 && compareWords(w, last)) { // check size of words
            cout << last << " and " << w << "\n";
            rhyme_pairs++;
        }
        last = w;
    }
    
    if (rhyme_pairs == 0) {
        cout << "No rhymes found.\nThere are " << num_lines << " lines in this poem.\n";
        return 0;
    }
    
    
    if (rhyme_pairs == 1)
        cout << "There is 1 pair of rhyming words.\n";
    else
        cout << "There are " << rhyme_pairs << " pairs of rhyming words.\n";
    cout << "There are " << num_lines << " lines in this poem, so the rhyme-line density is: " << static_cast<double>(rhyme_pairs) / num_lines << "\n";
    

    return 0;
}

string findLastWord(string line) {
    int i = line.size() - 1;
    while (i >= 0 && !isalpha(line[i]) && line[i] != '\'' && line[i] != '-') { // shave off ending punctuation
        i--;
    }
    
    string word = "";
    
    while (i >= 0 && isalpha(line[i]) && line[i] || line[i] == '\'' || line[i] == '-') { // add characters to word until we hit a non-alphabetic character
        word = line[i] + word;
        i--;
    }
    
    return word;
}

void cleanUp(string &word) {
    string clean = "";
    
    for (char c : word) {
        if (isalpha(c)) {
            clean += tolower(c);
        }
    }
    word = clean;
}

bool compareWords(string word1, string word2) {
    return word1.substr(word1.size() - 2, 2) == word2.substr(word2.size() - 2, 2); // compare last 2 characters
}