#include <iostream>
using namespace std;

int main() {
    int N, X, P;
    cout << "Enter Lilly's age: ";
    cin >> N;
    cout << "Enter price of washing machine: ";
    cin >> X;
    cout << "Enter unit price of each toy: ";
    cin >> P;

    double saved = 0, gift = 10.0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) { saved += gift - 1.0; gift += 10.0; }
        else { saved += P - 1.0; }
    }

    double diff = saved - X;
    cout << (diff >= 0 ? "Yes! " : "No! ") << (diff >= 0 ? diff : -diff) << endl;
    return 0;
}