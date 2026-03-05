// file: r_functions.cpp
// Chinmay Khaladkar
// Define the functions, per the list in r_headers.h
#include <string>
#include <iostream>
using namespace std;

void NameSort(UndergradStudents array[], int size) {
    // pre condition: array of UndergradStudents structs, and size of array
    // post condition: sorts by first letter of last name
    UndergradStudents temp;
    for (int i = size; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (array[j - 1].last_name[0] > array[j].last_name[0]) {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void InitializeStructures(UndergradStudents us[], int &size) {
    cout << "STUDENT RECORDS:\n";
    size = 0;
    int i = 1;
    while (i < 21) {
        if (i < 10) cout << "Student 0" << i << ":Enter first name (or x to quit): ";
        else cout << "Student " << i << ":Enter first name (or x to quit): ";
        string first_name;
        cin >> first_name;
        if (first_name == "x" || first_name == "X") break;
        us[i - 1].first_name = first_name;

        us[i - 1].id = i;

        if (i < 10) cout << "Student 0" << i << ":Enter last name: ";
        else cout << "Student " << i << ":Enter last name: ";
        string last_name;
        cin >> last_name;
        us[i - 1].last_name = last_name;

        if (i < 10) cout << "Student 0" << i << ":Enter major: ";
        else cout << "Student " << i << ":Enter major: ";
        string major;
        cin >> major;
        us[i - 1].major = major;

        for (int year = 0; year < 4; year++) {
            if (i < 10) cout << "Student 0" << i << ":Enter GPA Year " << year + 1 << ": ";
            else cout << "Student " << i << ":Enter GPA Year " << year + 1 << ": ";
            cin >> us[i - 1].GPA[year];
        }

        size++;
        i++;
        cout << endl;
    }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
    // pre condition: file output stream, array of undergrad students, and size of array
    // post condition: writes details about students to file
    NameSort(us, size);
    outf.open(OUTPUTFILE);
    outf << fixed << setprecision(2);
    outf << "These are the results sorted by last name:" << endl;

    for (int i = 0; i < size; i++) {
        float avg = 0.0;
        for (int y = 0; y < 4; y++) {
            avg += us[i].GPA[y];
        }
        avg = avg / 4.0;
        outf << "ID# " << us[i].id << ": "
             << us[i].last_name << ": "
             << us[i].first_name << ": "
             << us[i].major << ": "
             << avg << endl;
    }

    outf.close();
}
