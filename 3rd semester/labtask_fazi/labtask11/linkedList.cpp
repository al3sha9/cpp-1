#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


class doubleLinkedlist {
private:
    Node* head;
    Node* tail;

public:

    doubleLinkedlist() {
        head = nullptr;
        tail = nullptr;
    }


    void insert_at_start(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;

        head = newNode;
    }


    void insert_at_end(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        if (tail != nullptr) {
            newNode->prev = tail;
            tail->next = newNode;
        } else {
            newNode->prev = nullptr;
            head = newNode;
        }

        tail = newNode;
    }

    void delete_from_start() {
        if (head == nullptr) {
            cout << "List is empty..\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    void delete_from_end() {
        if (tail == nullptr) {
            cout << "List is empty..\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }

    void display() {
        cout << "Doble Linked List: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    doubleLinkedlist list;
    int data[] = {22, 43, 55, 3, 2, 6, 7, 8};
    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; ++i)
        list.insert_at_start(data[i]);

    list.display();

    list.insert_at_end(100);
    list.display();

    list.delete_from_start();
    list.display();

    list.delete_from_end();
    list.display();

    return 0;
}
