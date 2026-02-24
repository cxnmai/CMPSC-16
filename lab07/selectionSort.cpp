/* Main function for selectionSort.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

int main() {
    // 1. Get filename from user and check it
    // 2. Get size of file to then create dynamic array
    //      Note: You HAVE to use the functions:
    //      getFileSize() and getArray() here
    // 3. Print original array (see PDF lab description for details)
    // 4. Ask user for ascending or descending sort
    // 5. Run selection sort on the array
    //      Note: You HAVE to use the function sort() here
    // 6. Print sorted array (see PDF lab description for details)
    
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    ifstream inf(filename);
    if (!inf) {
        cout << "invalid \n";
        return 1;
    }
    cout << "Original array:\n";
    int size = getFileSize(inf, filename);
    inf.clear();
    inf.seekg(0);
    int arr[size] = {0};
    getArray(inf, filename, arr, size);
    
    for (int num : arr) cout << num << " ";
    cout << "\n";
    
    cout << "Ascending (0) or Descending (1): ";
    bool desc;
    cin >> desc;
    
    cout << "Sorted array:\n";
    
    sort(desc, arr, size, 0);
    for (int num : arr) cout << num << " ";
    cout << "\n";
    

    return 0;
}
