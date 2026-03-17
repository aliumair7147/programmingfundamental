#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) n = -n;
    for (; n > 0; n /= 10) sum += n % 10;
    cout << "Sum of digits: " << sum << endl;
    return 0;
}