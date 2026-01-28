#include <iostream>
#include <string>
using namespace std;

struct hello {
    string world;
};


int main() {
    
    int num = 4;
    
    cout << &num << endl;
    
    int *num_address = &num;
    
    cout << num_address << " : " << *num_address << endl;

    return 0;
}
