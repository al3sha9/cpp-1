#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void postOrder(Node* node){
    if (node == NULL){
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}
int main(){
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node (10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    cout<<"Post Order traversal ";
    postOrder(root);
    return 0;
}