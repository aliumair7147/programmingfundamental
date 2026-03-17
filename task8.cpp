#include <iostream>
using namespace std;

int main() {
    double money;
    int year;
    cout << "Enter inherited money: ";
    cin >> money;
    cout << "Enter the year: ";
    cin >> year;

    double total = 0;
    for (int y = 1800; y <= year; y++)
        total += (y % 2 == 0) ? 12000 : 12000 + 50 * (18 + y - 1800);

    double diff = money - total;
    if (diff >= 0)
        cout << "Yes! He will live a carefree life and will have " << diff << " dollars left." << endl;
    else
        cout << "He will need " << -diff << " dollars to survive." << endl;
    return 0;
}