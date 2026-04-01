// file: headers.h for newanagrams
#include <string>
using namespace std;
// Define class AString here!
// See PDF for details
class AString {
public:
    
    AString();
    AString(string sv);
    
    string getStringValue();
    
    void cleanUp();
    
    void countLetters(int (&letters)[26]);
    
    void getAString();
    
private:
    string StringValue;
};

// DO NOTE CHANGE THESE AND DO NOT ADD TO THEM!
bool compareCounts(int a[], int b[]);
const int ARRAYSIZE = 26;