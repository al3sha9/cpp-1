#include <iostream>
#include <climits>

using namespace std;

class StackOverflow {
private:
    int* arr;
    int* min_arr;
    int stack_capacity;
    int top;

public:
    StackOverflow(int initial = 10) {
        stack_capacity = initial;
        arr = new int[stack_capacity];
        min_arr = new int[stack_capacity]; 
        top = -1;
    }

    ~StackOverflow() {
        delete[] arr;
        delete[] min_arr;
    }

    void push(int val) {
        if (limitReached()) {
            resize();
        }
        arr[++top] = val;

        if (empty() || val < min_arr[top - 1]) {
            min_arr[top] = val;
        } else {
            min_arr[top] = min_arr[top - 1];
        }
    }

    int pop() {
        if (empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int popped = arr[top--];
        if (!empty()) {
            min_arr[top] = min_arr[top + 1];
        } else {
            min_arr[top] = INT_MAX; // Reset min value when stack becomes empty
        }

        return popped;
    }

    int minimum() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return min_arr[top];
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
        int* new_min_arr = new int[new_capacity];

        for (int i = 0; i <= top; ++i) {
            new_arr[i] = arr[i];
            new_min_arr[i] = min_arr[i];
        }

        delete[] arr;
        delete[] min_arr;

        arr = new_arr;
        min_arr = new_min_arr;

        stack_capacity = new_capacity;
    }
};

int main() {
    StackOverflow stack(3);

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);

    cout << "Min elements: " << stack.minimum() << endl;

    stack.pop();
    cout << "Min elements after popping: " << stack.minimum() << endl;

    return 0;
}
