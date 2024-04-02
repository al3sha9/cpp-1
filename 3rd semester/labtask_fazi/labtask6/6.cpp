#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string message;
    Node* next;
};

class TransmitMessage {
public:
    string sender;
    string Reciever;
    string message;

    TransmitMessage(string sender, string Reciever, string message) {
    this->sender = sender;
    this->Reciever = Reciever;
    this->message = message;
}

};

class Queue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(TransmitMessage transmit_message) {
        Node* newNode = new Node();
        newNode->message = transmit_message.message;
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
            cout << "Under flow." << endl;
            return;
        }
        else {
            Node* oldhead = this->head;
            this->head = this->head->next;
            delete oldhead;
            if (this->head == NULL) this->tail = NULL;
            this->size--;
        }
    }

    void printQueue() {
        Node* temp = head;
        cout << "Queue: \n";
        while (temp != NULL) {
            cout << temp->message << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return this->size;
    }
};

int main() {
    Queue q;
    q.enqueue(TransmitMessage("Fazila", "Roshan", "Hello Roshan!\n"));
    q.enqueue(TransmitMessage("Roshan", "Fazila", "Hi Fazila!\n"));
    q.enqueue(TransmitMessage("Fazila", "Khan", "Hey Khan!\n"));
    q.enqueue(TransmitMessage("Khan", "Fazila", "Hi Fazila!"));

    q.printQueue();

    q.dequeue();
    q.dequeue();

    cout << "Size of the queue is:" << q.getSize() << endl;

    return 0;
}
