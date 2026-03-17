#include <iostream>
using namespace std;

int main() {
    int number, digit, count = 0;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the digit to check: ";
    cin >> digit;
    if (number < 0) number = -number;
    for (; number > 0; number /= 10)
        if (number % 10 == digit) count++;
    cout << "Frequency: " << count << endl;
    return 0;
}