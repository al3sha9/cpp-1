#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int data) {
        if (node == nullptr) return node;
        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    bool search(Node* node, int data) {
        if (node == nullptr) return false;
        if (node->data == data) return true;
        if (data < node->data) return search(node->left, data);
        return search(node->right, data);
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = remove(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int choice, value;

    while (true) {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.remove(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << value << " found in the BST.\n";
                } else {
                    cout << value << " not found in the BST.\n";
                }
                break;
            case 4:
                cout << "BST in-order: ";
                bst.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
