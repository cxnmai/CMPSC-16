#include <iostream>
using namespace std;

void compute_coins(int amount) {
    int temp = amount;
    int quarters = temp / 25;
    temp = temp - (quarters * 25);
    int dimes = temp / 10;
    temp = temp - (dimes * 10);
    int nickels = temp / 5;
    temp = temp - (nickels * 5);
    int pennies = temp;

    // 86 - 75 = 11, 11 - 10 = 1,

    if (amount == 1) cout << "1 cent can be given in ";
    else cout << amount << " cents can be given in ";

    if (quarters == 1) {
        cout << "1 quarter";
        if (dimes == 0 && nickels == 0 && pennies == 0) cout << ".";
        else cout << ", ";
    }
    else if (quarters > 0) {
        cout << quarters << " quarters";
        if (dimes == 0 && nickels == 0 && pennies == 0) cout << ".";
        else cout << ", ";
    }
    if  (dimes == 1) {
        cout << "1 dime";
        if (nickels == 0 && pennies == 0) cout << ".";
        else cout << ", ";
    }
    else if (dimes > 0) {
        cout << dimes << " dimes";
        if (nickels == 0 && pennies == 0) cout << ".";
        else cout << ", ";
    }

    if  (nickels == 1) {
        cout << "1 nickel";
        if (pennies == 0) cout << ".";
        else cout << ", ";
    }
    else if (nickels > 0) {
        cout << nickels << " nickels";
        if (pennies == 0) cout << ".";
        else cout << ", ";
    }

    if  (pennies == 1) cout << "1 penny.";
    else if (pennies > 0) cout << pennies << " pennies.";
}

int main() {
    int amount;

    while (true) {
        cout << "Enter number of cents (or zero to quit):" << endl;
        cin >> amount;

        if (amount == 0) break;

        if (amount < 0 || amount > 99) {
            cout << "Amount is out of bounds. Must be between 1 and 99.\n";
            continue;
        }

        compute_coins(amount);
        cout << endl;
    }

    return 0;

}
