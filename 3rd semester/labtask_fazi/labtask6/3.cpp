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
    int size;
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
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
        this->size++;
    }

    void dequeue() {
        if (this->head == NULL) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        else {
            Node* oldhead = this->head;
            this->head = this->head->next;
            if (this->head == NULL) this->tail = NULL;
            delete oldhead;
            this->size--; 
        }
    }

    int getSize() { 
        return this->size;
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
    cout<<"After dequeue: "<<endl;
    q.dequeue(); 
    q.dequeue(); 
    q.printQueue();
    cout<<"Add more elements:"<<endl;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(1);
    q.printQueue();
    return 0;
}
