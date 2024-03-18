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
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    LinkedList mergeSortedLists(LinkedList& list1, LinkedList& list2) {
        LinkedList mergedList;
        Node* ptr1 = list1.head;
        Node* ptr2 = list2.head;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->data < ptr2->data) {
                mergedList.appendNode(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                mergedList.appendNode(ptr2->data);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != nullptr) {
            mergedList.appendNode(ptr1->data);
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            mergedList.appendNode(ptr2->data);
            ptr2 = ptr2->next;
        }

        return mergedList;
    }

    pair<LinkedList, LinkedList> splitList() {
        LinkedList firstHalf;
        LinkedList secondHalf;
        if (head == nullptr || head->next == nullptr) {
            firstHalf.head = head;
            return make_pair(firstHalf, secondHalf);
        }

        Node* slowPtr = head;
        Node* fastPtr = head->next;

        while (fastPtr != nullptr) {
            fastPtr = fastPtr->next;
            if (fastPtr != nullptr) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
        }

        secondHalf.head = slowPtr->next;
        slowPtr->next = nullptr;

        firstHalf.head = head;

        return make_pair(firstHalf, secondHalf);
    }

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
};

int main() {
    LinkedList list1;
    list1.appendNode(1);
    list1.appendNode(3);
    list1.appendNode(5);

    LinkedList list2;
    list2.appendNode(2);
    list2.appendNode(4);
    list2.appendNode(6);

    cout << "List 1: " << endl;
    list1.linkedListTraversal();
    cout << "List 2: " << endl;
    list2.linkedListTraversal();

    LinkedList mergedList;
    mergedList = mergedList.mergeSortedLists(list1, list2);
    cout << "Merged List: " << endl;
    mergedList.linkedListTraversal();

    pair<LinkedList, LinkedList> splitLists = mergedList.splitList();
    cout << "First Half: " << endl;
    splitLists.first.linkedListTraversal();
    cout << "Second Half: " << endl;
    splitLists.second.linkedListTraversal();

    return 0;
}
