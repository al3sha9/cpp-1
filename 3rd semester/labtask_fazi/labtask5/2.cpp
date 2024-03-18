#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1; 
        }
        int popped_element = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped_element;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack stack;

    stack.push(3);
    stack.push(7);
    stack.push(11);
    stack.push(5);

    cout << "Popping elements: " << endl;
    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }

    return 0;
}
