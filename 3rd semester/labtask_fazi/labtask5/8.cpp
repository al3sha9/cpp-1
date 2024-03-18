#include <iostream>

using namespace std;

class StackOverflow {
private:
    int* arr;
    int stack_capacity;
    int top;

public:
    StackOverflow(int initial = 10) {
        stack_capacity = initial;
        arr = new int[stack_capacity];
        top = -1;
    }

    ~StackOverflow() {
        delete[] arr;
    }

    void push(int val) {
        if (limitReached()) {
            resize();
        }
        arr[++top] = val;
    }

    int pop() {
        if (empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool empty() {
        return top == -1;
    }

    bool limitReached() {
        return top == stack_capacity - 1;
    }

    void resize() {
        int new_capacity = stack_capacity * 2;
        int* new_arr = new int[new_capacity];

        for (int i = 0; i <= top; ++i) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        stack_capacity = new_capacity;
    }
};

int main() {
    StackOverflow stack(3);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << "Stack after pushing elements:" << endl;
    while (!stack.empty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}
