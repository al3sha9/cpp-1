#include <iostream>
#include <queue>  // Include the queue library for level order traversal

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard library functions

// Define the Node class
class Node {
public:
    int data;  // Integer data stored in the node
    Node* left;  // Pointer to the left child node
    Node* right;  // Pointer to the right child node

    // Constructor to initialize a node with a given value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    Node* root;  // Pointer to the root node of the binary tree

    // Constructor to initialize the root to nullptr
    BinaryTree() : root(nullptr) {}

    // Method to perform level order traversal of the binary tree
    void printLevelOrder() {
        if (root == nullptr)  // If the tree is empty, return immediately
            return;

        queue<Node*> q;  // Create an empty queue to hold nodes for level order traversal
        q.push(root);  // Enqueue the root node

        while (!q.empty()) {  // Continue until the queue is empty
            Node* node = q.front();  // Get the front node of the queue
            cout << node->data << " ";  // Print the data of the front node
            q.pop();  // Remove the front node from the queue

            if (node->left != nullptr)  // If the left child exists
                q.push(node->left);  // Enqueue the left child
            if (node->right != nullptr)  // If the right child exists
                q.push(node->right);  // Enqueue the right child
        }
    }
};

int main() {
    // Create a BinaryTree object
    BinaryTree tree;

    // Create nodes and build the tree
    tree.root = new Node(1);  // Create the root node with data 1
    tree.root->left = new Node(2);  // Create the left child of the root with data 2
    tree.root->right = new Node(3);  // Create the right child of the root with data 3
    tree.root->left->left = new Node(4);  // Create the left child of node 2 with data 4
    tree.root->left->right = new Node(5);  // Create the right child of node 2 with data 5
    tree.root->right->left = new Node(6);  // Create the left child of node 3 with data 6
    tree.root->right->right = new Node(7);  // Create the right child of node 3 with data 7

    // Print level order traversal
    cout << "Level Order Traversal of binary tree is: ";  // Print a message
    tree.printLevelOrder();  // Call the method to print the level order traversal of the tree

    // Clean up the dynamically allocated memory
    delete tree.root->right->right;  // Delete node 7
    delete tree.root->right->left;  // Delete node 6
    delete tree.root->right;  // Delete node 3
    delete tree.root->left->right;  // Delete node 5
    delete tree.root->left->left;  // Delete node 4
    delete tree.root->left;  // Delete node 2
    delete tree.root;  // Delete the root node

    return 0;  // Return 0 to indicate successful execution
}
