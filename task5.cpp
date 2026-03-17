#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    string names[n];
    cout << "Enter the names of " << n << " customers:" << endl;
    for (int i = 0; i < n; i++) cin >> names[i];
    char letter;
    cout << "Enter a letter to check: ";
    cin >> letter;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (names[i][0] == letter) count++;
    cout << "Total names starting with '" << letter << "': " << count << endl;
    return 0;
}