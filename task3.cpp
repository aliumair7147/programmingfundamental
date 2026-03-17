#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int large = arr[0], small = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > large) large = arr[i];
        if (arr[i] < small) small = arr[i];
    }
    cout << "Largest Number: " << large << endl;
    cout << "Smallest Number: " << small << endl;
    return 0;
}