#include <iostream>
#include <string>

using namespace std;

const int size = 100; 

class Stack {
private:
    char arr[size]; int top; 

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
    string text;
    cout << "Enter a string: ";
    getline(cin, text); 

    Stack charStack;

    for (char c : text) {
        charStack.push(c);
    }

    bool palidromeorNot = true;
    for (char c : text) {
        if (c != charStack.pop()) {
            palidromeorNot = false;
            break;
        }
    }

    if (palidromeorNot) {
        cout << "The text is palidrome "<< endl;
    } else {
        cout << "The text is  not plaidrome"<<endl;
    }

    return 0;
}
