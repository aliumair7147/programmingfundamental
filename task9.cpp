#include <iostream>
#include <string>
using namespace std;

int main() {
    string books[100];
    int bookCount = 0, choice;

    do {
        cout << "\n--- Library System ---\n"
             << "1. Add Books\n2. View Books\n3. Borrow Books\n4. Return Books\n5. Exit\n"
             << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter book name: ";
            getline(cin, books[bookCount++]);
            cout << "Book added successfully." << endl;
        } else if (choice == 2) {
            if (bookCount == 0) cout << "No books available." << endl;
            else for (int i = 0; i < bookCount; i++)
                cout << i + 1 << ". " << books[i] << endl;
        } else if (choice == 3 || choice == 4) {
            string name;
            cout << "Enter book name: ";
            getline(cin, name);
            cout << (choice == 3 ? "You borrowed: " : "You returned: ") << name << endl;
        } else if (choice == 5) cout << "Exiting Library System." << endl;
        else cout << "Invalid choice!" << endl;
    } while (choice != 5);
    return 0;
}