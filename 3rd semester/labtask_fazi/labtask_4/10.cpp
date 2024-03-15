#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node* arbit;
	Node(int x) {
		this->val = x;
		this->next = NULL;
		this->arbit = NULL;
	}
};

Node* cloneLinkedList(Node* head) {
	unordered_map<Node*, Node*> mp;
	Node *temp, *nhead;
	temp = head;
	nhead = new Node(temp->val);
	mp[temp] = nhead;

	while (temp->next != NULL) {
		nhead->next = new Node(temp->next->val);
		temp = temp->next;
		nhead = nhead->next;
		mp[temp] = nhead;
	}
	temp = head;

	while (temp != NULL) {
		mp[temp]->arbit = mp[temp->arbit];
		temp = temp->next;
	}
	return mp[head];
}

void printList(Node* head) {
	cout << head->val << "(" << head->arbit->val << ")";
	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->val << "(" << head->arbit->val << ")";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit = head->next->next->next->next;
	head->next->next->next->arbit = head->next->next;
	head->next->next->next->next->arbit = head->next;

	cout << "The original linked list:\n";
	printList(head);

	Node* sol = cloneLinkedList(head);

	cout << "The cloned linked list:\n";
	printList(sol);

	return 0;
}