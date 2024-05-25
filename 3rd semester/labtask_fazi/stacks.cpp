#include <iostream>
#include <stack>

using namespace std;

// Function to push multiple elements onto the stack
void pushMultiple(stack<int> &num, int *elements, int size) {
    for (int i = 0; i < size; ++i) {
        num.push(elements[i]);
    }
}

int main() {
    stack<int> num;

    // Array of elements to push
    int elements[] = {1, 2, 3};
    int size = sizeof(elements) / sizeof(elements[0]);

    // Push multiple elements onto the stack
    pushMultiple(num, elements, size);

    // Display stack elements
    cout << "Stack: ";
    while (!num.empty()) {
        cout << num.top() << " ";
        num.pop();
    }
    cout << endl;

    return 0;
}
