#include <iostream>
using namespace std;

int main() {
    int choice;
    while(true) {
        cout << "\n--- Restaurant Management System ---\n"
             << "1. View Food Menu\n2. Place Order\n3. View Order Status\n"
             << "4. Generate Bill\n5. Contact Staff\n6. Exit\n"
            << "Enter your choice (1-6): ";
        cin >> choice;

        if      (choice == 1) cout << "You selected: View Food Menu." << endl;
        else if (choice == 2) cout << "You selected: Place Order." << endl;
        else if (choice == 3) cout << "You selected: View Order Status." << endl;
        else if (choice == 4) cout << "You selected: Generate Bill." << endl;
        else if (choice == 5) cout << "You selected: Contact Staff." << endl;
        else if (choice == 6) cout << "Exiting Restaurant Management System. Thank you!" << endl;
        else cout << "Invalid choice!" << endl;
    }
    return 0;
}