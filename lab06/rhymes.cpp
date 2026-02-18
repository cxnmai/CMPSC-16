#include <fstream>
#include <string>
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {
    // MISSING CODE HERE (you can remove these comments)
    // Create input stream object, then get a filename from user (check it too)
    // Read the lines in your file and check on rhyming, per our definition
    // Finally, print the results (see lab descriptions for examples)

    return 0;
}

string findLastWord(string line) {
    string last = "";
    int start = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            start = i + 1;
            last = "";
        } else {
            last = line.substr(start, i);
        }
    }
}

// MISSING FUNCTION DEFINITIONS HERE
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)