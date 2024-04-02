#include<iostream>
using namespace std;

class Node {
public:
    int data; 
    Node* next;
};

class Queue {
    Node* head;
    Node* tail;
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (this->head == NULL) {
            this->head = this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void printQueue() {
        Node* temp = head;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(9);
    q.printQueue();

    return 0;
}
