#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);

    int size = 0;

    cout << "Enter number of grades: ";
    
    cin >> size;
    
    if (size == 0) {
        cout << "Error!" << "\n";
        return 0;
    }
    
    int* array = new int[size];
    
    cout << "Enter grades (each on a new line):" << "\n";
    
    int i = 0;
    
    while (i < size) {
        cin >> array[i];
        i++;
    }
    
    cout << "Here are some statistics:" << "\n";
    cout << "Average: " << average(array, size) << "\n";
    cout << "Median: " << median(array, size) << "\n";
    cout << "StdDev: " << stddev(array, size) << "\n";
    
    delete[] array;
    
    return 0;
}

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

double average(int* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

double median(int* array, int size) {
    bubbleSort(array, size);

    if (size % 2 == 1) return array[size / 2];
    else return (array[(size / 2) - 1] + array[size / 2]) / 2.0;
}

double stddev(int* array, int size) {
    double sum = 0;
    double avg = average(array, size);
    for (int i = 0; i < size; i++) {
        sum += pow((array[i] - avg), 2);
    }
    return pow((sum / (size - 1)), 0.5);
}
