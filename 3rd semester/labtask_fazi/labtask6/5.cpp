#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Customer {
public:
    string name;
    int items;

    Customer(string name, int items) : name(name), items(items) {}
};

class Queue {
private:
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

    void enqueue(Customer customer) {
        Node* newNode = new Node();
        newNode->data = customer.items;
        newNode->next = NULL;
        if (this->head == NULL) {
            this->head = this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
        this->sum += customer.items;
    }

    void dequeue() {
        if (this->head == NULL) {
            cout << "UnderFLow" << endl;
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
        cout << "**Queue** ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(Customer("customer1", 5));
    q.enqueue(Customer("customer2", 3));
    q.enqueue(Customer("customer3", 2));
    q.enqueue(Customer("customer4", 4));

    q.printQueue();

    q.dequeue();
    q.dequeue();

    cout << "Average: " << q.getAverage() << endl;

    return 0;
}
