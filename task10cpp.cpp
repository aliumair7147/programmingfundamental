#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;
    while(true){
        cout << "\n--- Calculator ---\n"
             << "1. Addition\n2. Subtraction\n3. Multiplication\n"
             << "4. Division\n5. Clear Screen\n6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        if      (choice == 1) cout << "Sum: "        << a + b << endl;
        else if (choice == 2) cout << "Difference: " << a - b << endl;
        else if (choice == 3) cout << "Product: "    << a * b << endl;
        else if (choice == 4) {
            if (b == 0) cout << "Error: Division by zero!" << endl;
            else cout << "Result: " << a / b << endl;
        }
        else if (choice == 5) cout << "Screen cleared." << endl;
        else if (choice == 6) cout << "Exiting Calculator. Goodbye!" << endl;
        else cout << "Invalid choice!" << endl;
    } 
    return 0;
}