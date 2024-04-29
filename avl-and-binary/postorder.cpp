// Include all standard libraries available in C++, through the bits/stdc++.h header, which is commonly used for competitive programming because it includes most of the libraries needed.
#include <bits/stdc++.h>
// Use the standard namespace to avoid the need to prefix standard library functions and objects with 'std::'.
using namespace std;

// Declaration of a class named Node to define the structure of a binary tree node.
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

// Function to perform a postorder traversal of a binary tree.
void printPostOrder(Node* node)
{
    // Check if the node is NULL. If so, return immediately as there is nothing to process.
    if (node == NULL)
        return;

    // Recursively call printPostOrder for the left subtree first.
    printPostOrder(node->left);

    // Then, recursively call printPostOrder for the right subtree.
    printPostOrder(node->right);

    // After traversing both subtrees, print the current node's data. This is the 'visit' step in postorder.
    cout << node->data << " ";
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

    // Perform the postorder traversal of the tree.
    cout << "PostOrder Traversal: ";
    printPostOrder(root);
    cout << "\n"; // Print a newline at the end of the output for clarity.

    // Return 0 to indicate that the program ended successfully.
    return 0;
}

