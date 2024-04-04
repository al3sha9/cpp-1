#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string job;
    Node* next;
};

class QueueManagement {
private:
    Node* head;
    Node* tail;
    int size;
//publicc
public:
    QueueManagement() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void enqueue(string job) {
        Node* newNode = new Node();
        newNode->job = job;
        newNode->next = nullptr;
        if (this->head == nullptr) {
            this->head = this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue() {
        if (this->head == nullptr) {
            cout << "UnderFlow." << endl;
            return;
        }
        else {
            Node* oldHead = this->head;
            this->head = this->head->next;
            delete oldHead;
            if (this->head == nullptr) this->tail = nullptr;
            this->size--;
        }
    }

    void printQueue() {
        Node* temp = head;
        cout << "Queue: \n";
        while (temp != nullptr) {
            cout << temp->job << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return this->size;
    }
};

int main() {
    QueueManagement qm;
    qm.enqueue("Coding\n");
    qm.enqueue("Software Requirment\n");
    qm.enqueue("Engineering\n");
    qm.enqueue("Instructor\n");

    qm.printQueue();

    qm.dequeue();
    qm.dequeue();

    cout << "Size: " << qm.getSize() << endl;

    return 0;
}
