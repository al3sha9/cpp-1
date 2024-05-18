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
void preOrder(Node* node){
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);    
}
int main(){
    Node *p = new Node(4);
    Node *p1 = new Node(1);
    Node *p2 = new Node(6);
    Node *p3 = new Node(5);
    Node *p4 = new Node(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout<<"Pre order traversal: ";
    preOrder(p);    
}