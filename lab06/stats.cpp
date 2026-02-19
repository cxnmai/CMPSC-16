#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void bubbleSort(vector<int> &vec, int size);

int main() {
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Cannot open " << filename << "\n"; // give error if can't find file
        return 1;
    }
    
    vector<int> input;
    int num;
    while (inFile >> num) { // add all integer values to the vector
        input.push_back(num);
    }
    
    cout << "Here are some statistics: \n";
    cout << "      N: " << input.size() << "\n"; // number of elements in vector
    
    int sum = 0;
    for (int num : input) {
        sum += num; // sum all elements in vector to compute average
    }
   
    double average = static_cast<double>(sum) / input.size();
    
    cout << "Average: " << average << "\n";
    
    bubbleSort(input, input.size());
    if (input.size() % 2 == 0) { // if number of elemeents is even we take the average of the middle two
        cout << " Median: " << (input[input.size()/2 - 1] + input[input.size()/2]) / 2.0 << "\n";
    } else {
        cout << " Median: " << input[input.size()/2] << "\n";
    }
    
    double stdev = 0.0;
    
    for (int num : input) {
        stdev += pow(num - average, 2); // sum of squares of distance to mean
    }
    
    stdev /= input.size() - 1; // divide by N - 1
    
    stdev = sqrt(stdev);
    
    cout << " StdDev: " << stdev << "\n";
    
    
    return 0;
}

void bubbleSort(std::vector<int> &vec, int size) {
    int temp;
    for (int i = size-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (vec[j-1] > vec[j]) {
                temp = vec[j-1];
                vec[j-1] = vec[j];
                vec[j] = temp;
            } // if
        } // for j
    } // for i
}