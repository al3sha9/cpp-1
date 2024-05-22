#include <iostream>
#include <queue>
using namespace std;

struct treeNode
{
    int value;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int data)
    {
        value = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

treeNode *insertNode(treeNode *rootNode, int data)
{
    if (rootNode == nullptr)
    {
        return new treeNode(data);
    }
    if (data < rootNode->value)
    {
        rootNode->leftChild = insertNode(rootNode->leftChild, data);
    }
    else
    {
        rootNode->rightChild = insertNode(rootNode->rightChild, data);
    }
    return rootNode;
}

bool findNode(treeNode *rootNode, int data)
{
    if (rootNode == nullptr)
    {
        return false;
    }
    if (rootNode->value == data)
    {
        return true;
    }
    if (data < rootNode->value)
    {
        return findNode(rootNode->leftChild, data);
    }
    else
    {
        return findNode(rootNode->rightChild, data);
    }
}

treeNode *findMin(treeNode *rootNode)
{
    while (rootNode->leftChild != nullptr)
    {
        rootNode = rootNode->leftChild;
    }
    return rootNode;
}

treeNode *deleteNode(treeNode *rootNode, int data)
{
    if (rootNode == nullptr)
    {
        return rootNode;
    }
    if (data < rootNode->value)
    {
        rootNode->leftChild = deleteNode(rootNode->leftChild, data);
    }
    else if (data > rootNode->value)
    {
        rootNode->rightChild = deleteNode(rootNode->rightChild, data);
    }
    else
    {
        if (rootNode->leftChild == nullptr)
        {
            treeNode *tempNode = rootNode->rightChild;
            delete rootNode;
            return tempNode;
        }
        else if (rootNode->rightChild == nullptr)
        {
            treeNode *tempNode = rootNode->leftChild;
            delete rootNode;
            return tempNode;
        }
        treeNode *tempNode = findMin(rootNode->rightChild);
        rootNode->value = tempNode->value;
        rootNode->rightChild = deleteNode(rootNode->rightChild, tempNode->value);
    }
    return rootNode;
}

void preorderTraversal(treeNode *rootNode)
{
    if (rootNode != nullptr)
    {
        cout << rootNode->value << endl;
        preorderTraversal(rootNode->leftChild);
        preorderTraversal(rootNode->rightChild);
    }
}

treeNode *createBST()
{
    treeNode *rootNode = new treeNode(4);
    rootNode->leftChild = new treeNode(2);
    rootNode->rightChild = new treeNode(7);
    rootNode->leftChild->leftChild = new treeNode(1);
    rootNode->leftChild->rightChild = new treeNode(3);
    rootNode->rightChild->rightChild = new treeNode(9);
    rootNode->rightChild->rightChild->rightChild = new treeNode(10);
    return rootNode;
}

int main()
{
    treeNode *rootNode = createBST();
    int choice, value;
    while (true)
    {
        cout << "1. insert" << endl;
        cout << "2.search" << endl;
        cout << "3.delete" << endl;
        cout << "4.display" << endl;
        cout << "5. exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter value to insert" << endl;
            cin >> value;
            rootNode = insertNode(rootNode, value);
            break;
        case 2:
            cout << "enter value to search" << endl;
            cin >> value;
            if (findNode(rootNode, value))
            {
                cout << "value found" << endl;
            }
            else
            {
                cout << "vlaue not found" << endl;
            }
            break;
        case 3:
            cout << "enter value to delete" << endl;
            cin >> value;
            rootNode = deleteNode(rootNode, value);
            break;
        case 4:
            cout << "preorder traversal" << endl;
            preorderTraversal(rootNode);
            cout << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "invlaid" << endl;
        }
    }
    return 0;
}
