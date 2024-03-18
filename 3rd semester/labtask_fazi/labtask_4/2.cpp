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
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    friend void addNodeAtBeginning(LinkedList& list, int value);
    friend void appendNode(LinkedList& list, int value);
    friend void deleteNodeWithValue(LinkedList& list, int value);
    friend void deleteFirstOccurrence(LinkedList& list, int value);
    friend void deleteAllOccurrences(LinkedList& list, int value);
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

void deleteNodeWithValue(LinkedList& list, int value) {
    Node* current = list.head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (previous == nullptr) {
                list.head = current->next;
                delete current;
                return;
            } else {
                previous->next = current->next;
                delete current;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
}

void deleteFirstOccurrence(LinkedList& list, int value) {
    Node* current = list.head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (previous == nullptr) {
                list.head = current->next;
                delete current;
                return;
            } else {
                previous->next = current->next;
                delete current;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
}

void deleteAllOccurrences(LinkedList& list, int value) {
    Node* current = list.head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (previous == nullptr) {
                list.head = current->next;
                delete current;
                current = list.head;
            } else {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    LinkedList list;
    list.head = new Node(7);
    list.head->next = new Node(11);
    list.head->next->next = new Node(22);

    addNodeAtBeginning(list, 3);
    appendNode(list, 33);

    cout << "List =  ";
    list.linkedListTraversal();

    int valueToDelete = 11;
    cout << "Deleting " << valueToDelete << endl;
    deleteNodeWithValue(list, valueToDelete);
    cout << "List after deleting =  " << valueToDelete << ": ";
    list.linkedListTraversal();

    int valueToDeleteFirstOccurrence = 3;
    cout << "Deleting first occurrence " << valueToDeleteFirstOccurrence << endl;
    deleteFirstOccurrence(list, valueToDeleteFirstOccurrence);
    cout << "List after deleting first occurrence =  " << valueToDeleteFirstOccurrence << ": ";
    list.linkedListTraversal();
    int valueToDeleteAllOccurrences = 22;
    cout << "Deleting all occurrences  " << valueToDeleteAllOccurrences << endl;
    deleteAllOccurrences(list, valueToDeleteAllOccurrences);
    cout << "List after deleting all occurrences =  " << valueToDeleteAllOccurrences << ": ";
    list.linkedListTraversal();
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
