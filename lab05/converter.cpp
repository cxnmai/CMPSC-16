#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);
bool isValid(string sval, char type);

int main ( int argc, char *argv[] ) {
    if (argc != 3) { // check that user inputted 2 arguments in cmd line
        cout << "Usage: converter <options: d2b, d2h, b2d> <value> \n";
        return 0;
    }

    string val = argv[2]; // convert to strings for comparison and conciseness
    string type = argv[1];

    if (type != "d2h" && type != "d2b" && type != "b2d") { // make sure type is valid
        cout << "Usage: converter <options: d2b, d2h, b2d> <value> \n";
        return 0;
    }



    if (type == "d2b" ||type == "d2h") { // make sure input value is valid for conversion type
        if (!isValid(val, 'd')) {
            cout << "Decimal value contains non-decimal digits. \n";
            return 0;
        }
    } else {
        if (!isValid(val, 'b')) {
            cout << "Binary value contains non-binary digits. \n";
            return 0;
        }
    }

    cout << "The value in ";

    if (type == "d2b") {
        cout << "binary is: " << dec2bh(val, 'b');
    } else if (type == "d2h") {
        cout << "hexadecimal is: " << dec2bh(val, 'h');
    } else if (type == "b2d") {
        cout << "decimal is: " << bin2d(val);
    }

    cout << "\n";

    return 0;
}

int bin2d(string binstring) {
    // pre condition: string of binary digits
    // post condition: integer value of the binary number
    int result = 0;
    int j = binstring.size() - 1; // power index from very right, since 0th index is most significant
    for (int i = 0; i < binstring.size(); i++) {
        int val = binstring[i] - 48; // char to int by -48
        result += pow(2, j) * val;
        j--;
    }
    return result;
}

string dec2bh(string sdec, char bh) {
    // pre condition: string of decimal digits and character b or h
    // post condition: returns string of value converted to either binary or hexadecimal based on specified
    int base;
    if (bh == 'b') base = 2; // set base to user specification
    else base = 16;

    int quotient = 0; // initialize quotient - starts at int version of sdec

    for (int i = 0; i < sdec.size(); i++) {
        quotient *= 10;
        quotient += sdec[i] - 48; // char to int value by ASCII
    }

    string result = "";

    while (quotient != 0) {
        int dig = quotient % base; // quotient-remainder method, by taking remainders as digit

        char cdig;
        string sdig;
        if (dig < 10) { // convert integer digit to string
            cdig = dig + 48;
            result = cdig + result;
        } else { // if >= 10, make it A, B, C etc. for hexadecimal values
            sdig = dig + 55;
            result = sdig + result;
        }

        quotient /= base; // update quotient
    }
    
    if (sdec == "0") return "0";

    return result;
}

bool isValid(string sval, char type) { // helper function to determine if a number is valid in the input format
    if (type == 'd') {
        for (char c : sval) {
            if (c > 57 || c < 48) return false; // decimal values are between 48 and 57 inclusive (0-9 in ASCII)
        }
    } else if (type == 'b') {
        for (char c : sval) {
            if (c != '1' && c != '0') return false; // binary digits are either 0 or 1
        }
    }
    return true;
}
