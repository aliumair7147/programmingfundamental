#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++, cout << endl)
        for (int j = 1; j <= 3; j++) cout << j << " ";
    return 0;
}