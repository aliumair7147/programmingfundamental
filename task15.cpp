#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) n = -n;
    if (n == 0) count = 1;
    for (; n > 0; n /= 10) count++;
    cout << "Total number of digits: " << count << endl;
    return 0;
}