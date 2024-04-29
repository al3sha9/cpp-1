// Include the entire standard library, which is not recommended, but often used in competitive programming for convenience.
#include <bits/stdc++.h>
// Standard namespace for using standard library components.
using namespace std;

// Definition of the Binary Search Tree (BST) class.
class BST {
    int data;           // Integer data stored in the node.
    BST *left, *right; // Pointers to the left and right child nodes.
    
public:
    // Default constructor of the BST class.
    BST();

    // Parameterized constructor of the BST class.
    BST(int);

    // Insert function to insert a node into the BST.
    BST* Insert(BST*, int);

    // Inorder traversal function to print the BST in sorted order.
    void Inorder(BST*);
};

// Default Constructor definition.
BST::BST()
    : data(0), left(NULL), right(NULL)
{
}

// Parameterized Constructor definition.
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST* BST::Insert(BST* root, int value)
{
    // If root is NULL, create a new node with the given value and return it as the new root.
    if (!root) {
        return new BST(value);
    }

    // Insert data.
    if (value > root->data) {
        // If the value to be inserted is greater than the current node's data, insert it into the right subtree.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data) {
        // If the value to be inserted is smaller than the current node's data, insert it into the left subtree.
        root->left = Insert(root->left, value);
    }

    // Return the root node after insertion.
    return root;
}

// Inorder traversal function definition.
// This function prints the nodes of the BST in sorted order.
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Driver code
int main()
{
    BST b, *root = NULL; // Create a BST object and a pointer to the root node, initialized as NULL.
    
    // Insert nodes into the BST.
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    // Perform inorder traversal to print the BST in sorted order.
    b.Inorder(root);

    // End of the main function
    return 0;
}

