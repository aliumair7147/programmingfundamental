#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) count++;
    cout << "Total Even Numbers: " << count << endl;
    return 0;
}