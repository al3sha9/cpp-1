#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

Node* deleteNode(Node* root, int k) {
    if (root == nullptr)
        return root;

    if (k < root->key) {
        root->left = deleteNode(root->left, k);
        return root;
    } else if (k > root->key) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    Node* succParent = root;
    Node* succ = root->right;
    while (succ->left != nullptr) {
        succParent = succ;
        succ = succ->left;
    }

    root->key = succ->key;

    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    delete succ;
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Original BST: ";
    inorder(root);
  
    cout << "\n\nDelete a Leaf Node: 20\n";
    root = deleteNode(root, 20);
    cout << "Modified BST tree after deleting Leaf Node:\n";
    inorder(root);

    cout << "\n\nDelete Node with single child: 70\n";
    root = deleteNode(root, 70);
    cout << "Modified BST tree after deleting single child Node:\n";
    inorder(root);

    cout << "\n\nDelete Node with both child: 50\n";
    root = deleteNode(root, 50);
    cout << "Modified BST tree after deleting both child Node:\n";
    inorder(root);

    return 0;
}
