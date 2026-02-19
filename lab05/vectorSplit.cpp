#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {
    cout << "Enter string to split:\n";

    string target;

    getline(cin, target);

    cout << "Enter delimiter string:\n";
    string delimiter;

    getline(cin, delimiter);

    vector<string> splitted_input = split(target, delimiter);
    
    if (splitted_input.size() == 0) {
        cout << "No substrings.\n";
        return 0;
    }
    cout << "The substrings are: ";
    for (int i = 0; i < splitted_input.size(); i++) {
        cout << "\"" << splitted_input[i] << "\"";
        if (i != splitted_input.size() - 1) {
            cout << ", ";
        }
    }
    cout << "\n";

    return 0;
}

vector<string> split(string target, string delimiter) {
    // pre condition: take a string of any length and a string of length 1
    // post condition: return a vector of substrings created by dividing the target by the delimiter
    vector<string> result;

    int start = 0; // indices to splice target by
    int end = 0;

    while (end < target.size()) { // ensure end can't go out of target bounds

        if (target.substr(end, 1) == delimiter) { // check if end index is a delimiter
            if (start != end) { // don't add empty substrings to result
                result.push_back(target.substr(start, end - start)); // add the substring of indices prior to the delimiter to result
            }
            start = end + 1; // reset positions to be after delimiter
            end = start;
        } else end++; // increase end index if it's not a delimiter
    }
    if (start != end) {
        result.push_back(target.substr(start, end - start)); // add substring after last delimiter if there are remaining characters
    }

    return result;
}
