//level order also called breadth first traversal 
//a type of tree traversal

#include <iostream>
#include <queue>  // Include queue for level order traversal

using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* left;  
    Node* right;
    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    Node* root;

    // Constructor
    BinaryTree() : root(nullptr) {}

    // Method to perform level order traversal
    void printLevelOrder() {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
};

int main() {
    // Create a BinaryTree object
    BinaryTree tree;

    // Create nodes and build the tree
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);

    // Print level order traversal
    cout << "Level Order Traversal of binary tree is: ";
    tree.printLevelOrder();

    // Clean up the dynamically allocated memory
    delete tree.root->right->right;
    delete tree.root->right->left;
    delete tree.root->right;
    delete tree.root->left->right;
    delete tree.root->left->left;
    delete tree.root->left;
    delete tree.root;

    return 0;
}
