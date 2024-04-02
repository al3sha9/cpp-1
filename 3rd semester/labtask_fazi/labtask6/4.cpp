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
    int sum; 
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0; 
        this->sum = 0;
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
        this->sum += data; 
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
            this->sum -= oldhead->data;
            delete oldhead;
            this->size--; 
        }
    }

    double getAverage() { 
        if (this->size > 0)
            return static_cast<double>(this->sum) / this->size; 
        else
            return 0.0; 
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
    q.enqueue(4); 
    q.enqueue(5); 
    q.enqueue(2); 
    q.enqueue(1); 
    q.printQueue();

    q.dequeue(); 
    q.dequeue(); 

    cout << "Average of the elements: " << q.getAverage() << endl;

    return 0;
}
