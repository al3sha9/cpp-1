#include <iostream>
#include <string>

using namespace std;

const int size = 100; 

class Stack {
private:
    char arr[size]; 
    int top; 

public:
    Stack() {
        top = -1; 
    }

    void push(char val) { 
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val; 
    }

    char pop() { 
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return '\0'; 
        }
        return arr[top--]; 
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString); 
    Stack charStack;

    for (char c : inputString) {
        charStack.push(c);
    }

    cout << "Reversed String:" << endl;
    while (!charStack.isEmpty()) {
        cout << charStack.pop();
    }
    cout << endl;

    return 0;
}
