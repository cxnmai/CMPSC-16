/*
/ Skeleton File for ARRAYS.CPP for CS16, UCSB
/ Copyright © 2026 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
#include <string>   // for string (used in headers.h)
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);

    print_array(array, MAXSIZE); // calling print_array


    int max_int = maxArray(array, MAXSIZE);
    cout << "Max = " << max_int << endl; // printing output of max_int


    int min_int = minArray(array, MAXSIZE);
    cout << "Min = " << min_int << endl; // printing output of min_int

    int sum = sumArray(array, MAXSIZE);
    cout << "Sum = " << sum << endl; // printing output of sumArray


    evensArray(array, MAXSIZE); // calling evensArray
    
    primesArray(array, MAXSIZE); // calling primesArray
     
    AllSearches(array, MAXSIZE); // calling AllSearches

    return 0;
}
