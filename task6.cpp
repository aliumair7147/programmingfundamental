#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    int x = a, y = b;
    for (; y != 0; y = x % y) x = y;
    
    cout << "GCD: " << x << endl;
    cout << "LCM: " << (a * b) / x << endl;
    return 0;
}