#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    string productNames[n];
    double prices[n];
    int quantity[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of product " << i + 1 << ": ";
        cin >> productNames[i];
        cout << "Enter price of " << productNames[i] << ": $";
        cin >> prices[i];
        cout << "Enter quantity of " << productNames[i] << ": ";
        cin >> quantity[i];
    }
    for (int i = 0; i < n; i++)
        cout << productNames[i] << ": $" << prices[i]
             << ", " << quantity[i] << " in stock, Total value: $"
             << prices[i] * quantity[i] << endl;
    return 0;
}