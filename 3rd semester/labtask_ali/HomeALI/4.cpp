#include <iostream>
using namespace std;

class Calculator {
private:
    int a, b;

public:
    Calculator(int x, int y) {
        a = x;
        b = y;
    }

    friend int addition(const Calculator &obj);
    friend int subtraction(const Calculator &obj);
    friend int multiplication(const Calculator &obj);
    friend float division(const Calculator &obj);
};

int addition(const Calculator &obj) {
    return obj.a + obj.b;
}

int subtraction(const Calculator &obj) {
    return obj.a - obj.b;
}

int multiplication(const Calculator &obj) {
    return obj.a * obj.b;
}

float division(const Calculator &obj) {
    if (obj.b != 0)
        return static_cast<float>(obj.a) / obj.b;
    else {
        cout << "Error: Division by zero\n";
        return 0;
    }
}

int main() {
    int a, b;
    cout << "Enter the values for a and b: ";
    cin >> a >> b;

    Calculator obj(a, b);
    int choice;
    cout << "Choose any one to perform\n 1. Addition 2. Subtraction 3. Multiplication 4. Division ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Result = " << addition(obj) << endl;
        break;
    case 2:
        cout << "Result = " << subtraction(obj) << endl;
        break;
    case 3:
        cout << "Result = " << multiplication(obj) << endl;
        break;
    case 4:
        cout << "Result = " << division(obj) << endl;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
    return 0;
}
