#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Palindrome {
public:
    Node* head;

    Palindrome() : head(nullptr) {}

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

    bool isPalindrome() {
        stack<int> stack;
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            stack.push(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        while (slow != nullptr) {
            if (stack.top() != slow->data) {
                return false;
            }
            stack.pop();
            slow = slow->next;
        }

        return true;
    }

    bool isCircular() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Palindrome list;

    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(2);
    list.appendNode(1);

    cout << "Is the linked list a palindrome? " << (list.isPalindrome() ? "Yes, it is" : "No, it isn't") << endl;

    list.head->next->next->next->next = list.head;

    cout << "Is the linked list circular? " << (list.isCircular() ? "Yes, it is" : "No, it isn't") << endl;

    return 0;
}
