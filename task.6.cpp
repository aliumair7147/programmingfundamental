#include <iostream>
#include <string>
using namespace std;

int main() {
    string shape;
    double area;

    cout << "Enter shape (square, rectangle, circle, triangle): ";
    cin >> shape;

    if (shape == "square") {
        double side;
        cout << "Enter side: ";
        cin >> side;
        area = side * side;
        cout << "Area = " << area << endl;

    } else if (shape == "rectangle") {
        double length, width;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
        area = length * width;
        cout << "Area = " << area << endl;

    } else if (shape == "circle") {
        double radius;
        cout << "Enter radius: ";
        cin >> radius;
        area = 3.14159 * radius * radius;
        cout << "Area = " << area << endl;

    } else if (shape == "triangle") {
        double base, height;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
        area = 0.5 * base * height;
        cout << "Area = " << area << endl;

    } else {
        cout << "Invalid shape!" << endl;
    }

    return 0;
}