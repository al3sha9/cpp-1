#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data; 
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

bool detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void removeLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* loopNode = NULL;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopNode = slow;
            break;
        }
    }

    if (loopNode == NULL) {
        return;
    }

    slow = head;
    while (slow->next != loopNode->next) {
        slow = slow->next;
        loopNode = loopNode->next;
    }

    loopNode->next = NULL;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = head;

    if (detectLoop(head)) {
        cout << "Loop detected and removed" << endl;
        removeLoop(head);
    } else {
        cout << "No loop detected" << endl;
    }

    cout << "Linked List after traversal:" << endl;
    linkedListTraversal(head);

    return 0;
}
