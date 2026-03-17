#include <iostream>
using namespace std;

int main() {
    int length;
    cout << "Enter the length of the Fibonacci series: ";
    cin >> length;

    int a = 0, b = 1;
    for (int i = 0; i < length; i++) {
        cout << a;
        if (i < length - 1) cout << ", ";
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout << endl;
    return 0;
}