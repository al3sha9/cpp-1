// Include the iostream standard header file that contains definitions of objects like cin, cout, cerr etc., used for input/output operations
#include <iostream>

// Use the standard namespace to avoid writing "std::" before standard functions and objects like cout, endl, etc.
using namespace std;

// Define a structure named 'node' to represent each node in the BST
struct node {
    int key;                // Integer to hold the key value of the node
    struct node *left, *right; // Pointers to the left and right children of the node
};

// A function that creates a new node with a given key and initializes its children to NULL
struct node* newNode(int item)
{
    struct node* temp = new struct node; // Dynamically allocate memory for a new node and point to it with 'temp'
    temp->key = item;                    // Set the key of the new node
    temp->left = temp->right = NULL;     // Initialize the left and right children to NULL
    return temp;                         // Return the pointer to the newly created node
}

// A function to insert a new key into the BST and return the root of the modified tree
struct node* insert(struct node* node, int key)
{
    // If the node is NULL, create a new node with the key and return it
    if (node == NULL)
        return newNode(key);

    // If the key is smaller than the current node's key, insert the key into the left subtree
    if (key < node->key)
        node->left = insert(node->left, key);
    // If the key is larger, insert the key into the right subtree
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the unchanged pointer to the current node
    return node;
}

// A function to search for a key in the BST and return a pointer to the node containing the key, if found
struct node* search(struct node* root, int key)
{
    // If the tree is empty or the root node matches the key, return the root pointer
    if (root == NULL || root->key == key)
        return root;

    // If the key is greater than the root's key, search the right subtree
    if (root->key < key)
        return search(root->right, key);

    // If the key is smaller than the root's key, search the left subtree
    return search(root->left, key);
}

// Main function where the program execution begins
int main()
{
    struct node* root = NULL; // Start with an empty BST

    // Insert various keys into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Set a key to search in the BST
    int key = 65; // Mistake in the question, should likely be 65 instead of 6 based on the output messages

    // Search the BST for the key and print the result
    if (search(root, key) == NULL)
        cout << key << " not found" << endl; // If the key is not found, print "not found"
    else
        cout << key << " found" << endl; // If the key is found, print "found"

    // Set another key to search
    key = 60;

    // Repeat the search for the new key
    if (search(root, key) == NULL)
        cout << key << " not found" << endl; // If the key is not found, print "not found"
    else
        cout << key << " found" << endl; // If the key is found, print "found"

    // End of program
    return 0;
}

