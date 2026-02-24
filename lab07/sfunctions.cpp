// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments
void swap_values(int& v1, int& v2) {
    // pre condition: two integers
    // post condition: value of integers is swapped
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int find_index_of_swap(bool desc, int a[], int start_index, int number_used) {
    // pre condition: boolean indicating descending or not, integer array, start index, and number used
    // post condition: returns index of smallest/largest value in array
    int current = a[start_index];
    int res = start_index;
    for (int i = 0; i < number_used; i++) {
        if (desc) {
            if (a[i + start_index] > current) {
                res = i + start_index;
                current = a[i + start_index];
            }
        } else {
            if (a[i + start_index] < current) {
                res = i + start_index;
                current = a[i + start_index];
            }
        }
    }
    return res;
}

void sort(bool desc, int a[], int number_used, int index) {
    // pre condition: boolean indicating descending or not, integer array, size of subarray, and starting index
    // post condition: sorts the array in ascending/descending order
    if (number_used == 1 || number_used == 0) return;
    else {
        int swap_index = find_index_of_swap(desc, a, index, number_used);
        swap(a[index], a[swap_index]);
        sort(desc, a, number_used - 1, index + 1);
    }
}

int getFileSize(ifstream& inf, string fname) {
    // pre condition: input file stream and filename
    // post condition: returns number of ints in file
    int res = 0;
    while (inf) {
        int tmp;
        inf >> tmp;
        res++;
    }
    return res;
}

void getArray(ifstream& in, string fname, int arr[], int size) {
    // pre condition: input file stream, file name, output array, and size
    // post condition: array filled with integer elements from the input file
    int i = 0;
    
    while (in >> arr[i] && i < size) {
        i++;
    }
}