#include <iostream>
using namespace std;

int main() {
    int var1;
    int var2;
    int var3;

    std::cout << "Please enter 3 numbers." << endl;

    std::cin >> var1;
    std::cin >> var2;
    std::cin >> var3;

    int formula = 2 * (var1 - 4 * var2) + 3 * var3;

    std::cout << "The result of the formula is: " << formula << endl;

    return 0;
}
