#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    string names[n];
    cout << "Enter names of " << n << " students:" << endl;
    for (int i = 0; i < n; i++) cin >> names[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (names[j] > names[j + 1]) swap(names[j], names[j + 1]);
    cout << "Students in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) cout << names[i] << endl;
    return 0;
}