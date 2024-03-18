#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void linkedListTraversal() {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    friend void addNodeAtBeginning(LinkedList& list, int value);
    friend void appendNode(LinkedList& list, int value);
};

void addNodeAtBeginning(LinkedList& list, int value) {
    Node* newNode = new Node(value);
    newNode->next = list.head;
    list.head = newNode;
}

void appendNode(LinkedList& list, int value) {
    Node* newNode = new Node(value);
    if (list.head == nullptr) {
        list.head = newNode;
        return;
    }
    Node* ptr = list.head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int main() {
    LinkedList list;
    list.head = new Node(7);
    list.head->next = new Node(11);
    list.head->next->next = new Node(22);

    addNodeAtBeginning(list, 3);

    appendNode(list, 33);

    list.linkedListTraversal();

    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
