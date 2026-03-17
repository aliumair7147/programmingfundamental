#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[5];
    cout << "Enter names of 5 students:" << endl;
    for (int i = 0; i < 5; i++) cin >> names[i];
    cout << "Student Names are:" << endl;
    for (int i = 0; i < 5; i++) cout << names[i] << endl;
    return 0;
}