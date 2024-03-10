#include <iostream>
using namespace std;

// Define a struct for the nodes of the linked list
struct Node {
    string name;
    Node* next;
    
    Node(string n) : name(n), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Function to add a new node to the end of the linked list
    void addNode(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Function to choose the bearer of bad news
    string chooseBearer(int skipValue) {
        Node* current = head;
        Node* prev = nullptr;

        // Move to the last node in the list
        while (current->next != nullptr) {
            current = current->next;
        }

        // Perform the counting off procedure until there is only one node left
        while (size > 1) {
            for (int i = 0; i < skipValue; i++) {
                prev = current;
                current = current->next != nullptr ? current->next : head;
            }
            prev->next = current->next;
            Node* temp = current;
            current = current->next != nullptr ? current->next : head;
            delete temp;
            size--;
        }

        return current->name;
    }
};

int main() {
    int numMessengers, skipValue;
    cout << "Enter the number of messengers: ";
    cin >> numMessengers;
    cout << "Enter the skip value: ";
    cin >> skipValue;

    LinkedList messengers;
    for (int i = 0; i < numMessengers; i++) {
        string name;
        cout << "Enter name for messenger " << i + 1 << ": ";
        cin >> name;
        messengers.addNode(name);
    }

    string bearer = messengers.chooseBearer(skipValue);
    cout << "The bearer of bad news is: " << bearer << endl;

    return 0;
}
