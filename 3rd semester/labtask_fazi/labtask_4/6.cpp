#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void appendNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    static Node* findIntersection(LinkedList& list1, LinkedList& list2) {
        unordered_set<Node*> nodeSet;
        Node* head1 = list1.head;
        while (head1 != nullptr) {
            nodeSet.insert(head1);
            head1 = head1->next;
        }
        Node* head2 = list2.head;
        while (head2 != nullptr) {
            if (nodeSet.find(head2) != nodeSet.end()) {
                return head2;
            }
            head2 = head2->next;
        }
        return nullptr;
    }
};

int main() {
    LinkedList list1;
    list1.appendNode(1);
    list1.appendNode(2);
    list1.appendNode(3);
    list1.appendNode(4);
    list1.appendNode(5);

    LinkedList list2;
    list2.appendNode(10);
    list2.appendNode(11);
    list2.appendNode(12);
    list2.appendNode(3); 

    Node* intersectionPoint = LinkedList::findIntersection(list1, list2);

    if (intersectionPoint != nullptr) {
        cout << "Intersection point found at node with data: " << intersectionPoint->data << endl;
    } else {
        cout << "No intersection point found" << endl;
    }

    return 0;
}
