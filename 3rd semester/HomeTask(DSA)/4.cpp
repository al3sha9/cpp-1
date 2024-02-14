#include <iostream>
using namespace std;

class Calculator {
private:
    int a, b;

public:
    void getValues() {
        cout << "Enter the values for a and b: ";
        cin >> a >> b;
    }
    int addition() {
        return a + b;
    }
    int subtraction() {
        return a - b;
    }
    int multiplication() {
        return a * b;
    }
    float division() {
        if (b != 0)
            return static_cast<float>(a) / b;
        else {
            cout << "Error: Division by zero\n";
            return 0;
        }
    }
};

int main() {
    Calculator obj;
    int choice;
    cout << "Choose any one to perform\n 1. Addition 2. Subtraction 3. Multiplication 4. Division ";
    cin >> choice;
    switch (choice) {
    case 1:
        obj.getValues();
        cout << "Result = " << obj.addition() << endl;
        break;
    case 2:
        obj.getValues();
        cout << "Result = " << obj.subtraction() << endl;
        break;
    case 3:
        obj.getValues();
        cout << "Result = " << obj.multiplication() << endl;
        break;
    case 4:
        obj.getValues();
        cout << "Result = " << obj.division() << endl;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
    return 0;
}
