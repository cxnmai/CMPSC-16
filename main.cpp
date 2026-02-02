#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 0;
    
    int* x_ref = &x;
    
    int y = 5;
    int* y_ref = &y;
    
    int z = 10;
    int* z_ref = &z;
    
    int a = 15;
    int* a_ref = &a;
    
    cout << x_ref << "\n";
    cout << y_ref << "\n";
    cout << z_ref << "\n";
    cout << a_ref << "\n";
}
