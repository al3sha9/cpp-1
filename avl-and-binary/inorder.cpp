// Include the entire standard library, which is not recommended for most use cases, but commonly used in competitive programming for convenience.
#include <bits/stdc++.h>
// Standard namespace for using standard library components.
using namespace std;

// Definition of the Node class, representing each node in the tree.
class Node {
public:
    int data;           // Integer member to hold the data value of the node.
    Node* left;         // Pointer to the left child node.
    Node* right;        // Pointer to the right child node.
    
    // Constructor of the Node class, initializing the node with a specific integer value 'v'.
    Node(int v)
    {
        this->data = v;         // Set the node's data to the provided value.
        this->left = this->right = NULL; // Initialize both child pointers to NULL, meaning the node initially has no children.
    }
};

// Function to perform an inorder traversal of a binary tree.
void printInorder(Node* node)
{
    // Base case: If the current node is NULL, return immediately as there is nothing to process.
    if (node == NULL)
        return;

    // Recursively call printInorder for the left subtree first.
    printInorder(node->left);

    // Print the data of the current node. This is the 'visit' step in inorder traversal.
    cout << node->data << " ";

    // Recursively call printInorder for the right subtree.
    printInorder(node->right);
}

// The main function: starting point of the program.
int main()
{
    // Create the root of the tree and initialize it with a value of 100.
    Node* root = new Node(100);

    // Construct the rest of the tree.
    root->left = new Node(20);          // Assign a new Node with value 20 to the left child of the root.
    root->right = new Node(200);        // Assign a new Node with value 200 to the right child of the root.
    root->left->left = new Node(10);    // Further expand the left subtree.
    root->left->right = new Node(30);   // Assign new children to the left child of the root.
    root->right->left = new Node(150);  // Continue expanding the right subtree.
    root->right->right = new Node(300); // Add another node to the right subtree.

    // Perform the inorder traversal of the tree.
    cout << "Inorder Traversal: ";
    printInorder(root);

    // End of the main function
    return 0;
}

