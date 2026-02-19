#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Number of arguments is incorrect." << endl;
        return 1;
    }

    int num1 = stoi(argv[1]);
    char op = argv[2][0];
    int num2 = stoi(argv[3]);

    if (op == '%' && num2 == 0) {
        cerr << "Cannot divide by zero." << endl;
        return 1;
    }

    if (op == '+') cout << num1 + num2 << endl;
    else if (op == '-') cout << num1 - num2 << endl;
    else if (op == 'x') cout << num1 * num2 << endl;
    else if (op == '%') cout << num1 % num2 << endl;
    else cerr << "Bad operation choice." << endl;

    return 0;
}
