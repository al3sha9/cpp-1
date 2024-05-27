#include <iostream>

using namespace std;

class BinaryTree {
public:
    // Node structure
    struct Node {
        int data;
        Node* left;
        Node* right;

        // Node constructor
        Node(int data) : data(data), left(NULL), right(NULL) {}
    };

    // Root of the binary tree
    Node* root;

    // Constructor
    BinaryTree() : root(NULL) {}

    // Method to create a new node
    Node* createNode(int data) {
        return new Node(data);
    }

    // Traverse Preorder
    void traversePreOrder(Node* temp) {
        if (temp != NULL) {
            cout << " " << temp->data;
            traversePreOrder(temp->left);
            traversePreOrder(temp->right);
        }
    }

    // Traverse Inorder
    void traverseInOrder(Node* temp) {
        if (temp != NULL) {
            traverseInOrder(temp->left);
            cout << " " << temp->data;
            traverseInOrder(temp->right);
        }
    }

    // Traverse Postorder
    void traversePostOrder(Node* temp) {
        if (temp != NULL) {
            traversePostOrder(temp->left);
            traversePostOrder(temp->right);
            cout << " " << temp->data;
        }
    }

    // Methods to start traversals from the root
    void traversePreOrder() {
        traversePreOrder(root);
    }

    void traverseInOrder() {
        traverseInOrder(root);
    }

    void traversePostOrder() {
        traversePostOrder(root);
    }
};

int main() {
    BinaryTree tree;

    // Creating the tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    tree.root = tree.createNode(1);
    tree.root->left = tree.createNode(2);
    tree.root->right = tree.createNode(3);
    tree.root->left->left = tree.createNode(4);

    cout << "Preorder traversal: ";
    tree.traversePreOrder();
    cout << "\nInorder traversal: ";
    tree.traverseInOrder();
    cout << "\nPostorder traversal: ";
    tree.traversePostOrder();

    return 0;
}
