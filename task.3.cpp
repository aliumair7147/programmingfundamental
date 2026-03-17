#include <iostream>
using namespace std;

int main() {
    int temp1, temp2, difference;

    cout <<" Temperature City 1" ;
    cin>> temp1;

    cout << "Temperature City 2" ;
    cin>> temp2;

    difference = temp1 - temp2;

    if (difference == 0) {
        difference = -difference;
    }

    if (difference  ==10) {
        cout <<" Difference is too Big"  <<endl;
    }

    cout >> "Program Ends " >>endl;

    return 0;
}