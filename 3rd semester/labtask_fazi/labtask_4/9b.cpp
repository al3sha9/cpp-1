#include<iostream>

using namespace std;

struct ListNode {
    int digit;
    ListNode* next;

    ListNode(int d) : digit(d), next(nullptr) {}
};

ListNode* addDigitToList(ListNode* tail, int digit) {
    ListNode* newNode = new ListNode(digit);

    if (tail == nullptr) {
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }

    return tail;
}

ListNode* merge(ListNode* h1, ListNode* h2) {
    ListNode* t1 = h1;
    ListNode* t2 = h2;
    ListNode* temp = nullptr;

    if (h1 == nullptr) {
        return h2;
    }

    if (h2 == nullptr) {
        return h1;
    }

    if (h1->digit > h2->digit) {
        h2->next = h1;
        return h2;
    }

    while (h2 != nullptr) {
        t2 = h2;
        h2 = h2->next;
        t2->next = nullptr;

        if (h1->digit > t2->digit) {
            t2->next = h1;
            h1 = t2;
            continue;
        }

        flag:
        if (t1->next == nullptr) {
            t1->next = t2;
            t1 = t1->next;
        } else if ((t1->next)->digit <= t2->digit) {
            t1 = t1->next;
            goto flag;
        } else {
            temp = t1->next;
            t1->next = t2;
            t2->next = temp;
        }
    }

    return h1;
}

void mergeSort(ListNode** head) {
    ListNode* first = *head;
    ListNode* second = nullptr;
    ListNode* temp = *head;

    if (first == nullptr || first->next == nullptr) {
        return;
    } else {
        while (first->next != nullptr) {
            first = first->next;
            if (first->next != nullptr) {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = nullptr;
        first = *head;
    }

    mergeSort(&first);
    mergeSort(&second);

    *head = merge(first, second);
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->digit;
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, digit;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "\nEnter the number of digits to be sorted: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter digit " << i + 1 << ": ";
        cin >> digit;

        tail = addDigitToList(tail, digit);
        if (head == nullptr) {
            head = tail;
        }
    }

    mergeSort(&head);

    cout << "\nSorted Number: ";
    printLinkedList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}