
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

    void reverseLinkedList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reverseInGroups(int k) {
        head = reverseInGroupsUtil(head, k);
    }

    Node* reverseInGroupsUtil(Node* head, int k) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        int count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != nullptr) {
            head->next = reverseInGroupsUtil(next, k);
        }
        return prev;
    }

    void reverseInKnodes(int k) {
        head = reverseInKnodesUtil(head, k);
    }

    Node* reverseInKnodesUtil(Node* head, int k) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        int count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != nullptr) {
            head->next = next;
            int remaining = 0;
            Node* temp = next;
            while (temp != nullptr) {
                temp = temp->next;
                remaining++;
            }
            if (remaining >= k) {
                head->next = reverseInKnodesUtil(next, k);
            }
        }
        return prev;
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

    cout << "List: ";
    list.linkedListTraversal();

    list.reverseLinkedList();
    cout << "Reversed list: ";
    list.linkedListTraversal();
    
    int k = 2;
    cout << "Reversed in groups of " << k << ": ";
    list.reverseInGroups(k);
    list.linkedListTraversal();
    cout << "Reversed " << k << " nodes: ";
    list.reverseInKnodes(k);
    list.linkedListTraversal();
    
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
