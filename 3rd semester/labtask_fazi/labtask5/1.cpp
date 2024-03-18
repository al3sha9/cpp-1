#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
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

    void push_multiple(int* elements, int size) {
        for (int i = 0; i < size; ++i) {
            push(elements[i]);
        }
    }

    void display() {
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Pushing single elements: ";
    stack.display();
    int elements[] = {4, 5, 6};
    int size = sizeof(elements) / sizeof(elements[0]);
    stack.push_multiple(elements, size);
    cout << "Pushing multiple elements: ";
    stack.display();

    return 0;
}
