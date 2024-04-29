// Include the entire standard template library (STL) components, including containers, algorithms, etc.
#include <bits/stdc++.h>
// Use the standard namespace to avoid prefixing std:: to all standard library names.
using namespace std;

// Definition of the Node class, representing each node in the tree.
class Node {
public:
    int data;           // Data field to store the value at the node.
    Node* left;         // Pointer to the left child node.
    Node* right;        // Pointer to the right child node.

    // Constructor to initialize a node with a value v.
    Node(int v)
    {
        this->data = v;         // Set the node's data to v.
        this->left = this->right = NULL; // Initialize left and right child pointers to NULL.
    }
};

// Function to perform a preorder traversal of the tree starting from the node 'node'.
void printPreOrder(Node* node)
{
    // Base case: If the current node is NULL, return.
    if (node == NULL)
        return;

    // Print the current node's data as part of the preorder traversal.
    cout << node->data << " ";

    // Recursively traverse the left subtree.
    printPreOrder(node->left);

    // Recursively traverse the right subtree.
    printPreOrder(node->right);
}

// Main function: Entry point of the program.
int main()
{
    // Creating the root of the tree and initializing it with the value 100.
    Node* root = new Node(100);

    // Constructing the left and right subtrees of the root.
    root->left = new Node(20);
    root->right = new Node(200);

    // Further building the left subtree.
    root->left->left = new Node(10);
    root->left->right = new Node(30);

    // Further building the right subtree.
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Print the label for the output followed by the preorder traversal of the tree.
    cout << "Preorder Traversal: ";
    printPreOrder(root);

    // End of the main function.
    return 0;
}

