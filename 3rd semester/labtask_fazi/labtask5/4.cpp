#include <iostream>

using namespace std;

const int size = 100; 

class Stack {
private:
    int arr [size]; 
    int top; 

public:
    Stack() {
        top = -1; 
    }

 
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val; 
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--]; 
        }
    bool isEmpty() {
        return top == -1;
    }

    void copy_reverse(Stack& original, Stack& rev) {
        while (!original.isEmpty()) {
            int val = original.pop();
            rev.push(val);
        }
    }
};

int main() {

    Stack originalStack;
    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);
    originalStack.push(4);

    Stack reversedStack;

    originalStack.copy_reverse(originalStack, reversedStack);

    cout << "Reversed Stack:" << endl;
    while (!reversedStack.isEmpty()) {
        cout << reversedStack.pop() << " ";
    }
    cout << endl;

    return 0;
}
