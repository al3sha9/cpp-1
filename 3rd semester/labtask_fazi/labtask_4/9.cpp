#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node* NewNode(int d)
{
    struct node *temp = new node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

node* AddToList(node *tail, int data)
{
    struct node *newnode;
    newnode = NewNode(data);

    if(tail == NULL)
    {
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }

    return tail;
}

node* Merge(node* h1, node* h2)
{
    node *t1 = new node;
    node *t2 = new node;
    node *temp = new node;

    if(h1 == NULL)
        return h2;

    if(h2 == NULL)
        return h1;

    t1 = h1;

    while (h2 != NULL)
    {
        t2 = h2;
        h2 = h2->next;
        t2->next = NULL;

        if(h1->data > t2->data)
        {
            t2->next = h1;
            h1 = t2;
            t1 = h1;
            continue;
        }

        flag:
        if(t1->next == NULL)
        {
            t1->next = t2;
            t1 = t1->next;
        }
        else if((t1->next)->data <= t2->data)
        {
            t1 = t1->next;
            goto flag;
        }
        else
        {
            temp = t1->next;
            t1->next = t2;
            t2->next = temp;
        }
    }

    return h1;
}

void MergeSort(node **head)
{
    node *first = new node;
    node *second = new node;
    node *temp = new node;
    first = *head;
    temp = *head;

    if(first == NULL || first->next == NULL)
    {
        return;
    }
    else
    {
        while(first->next != NULL)
        {
            first = first->next;
            if(first->next != NULL)
            {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = NULL;
        first = *head;
    }

    MergeSort(&first);
    MergeSort(&second);

    *head = Merge(first, second);
}

int main()
{
    int n, i, num;
    struct node *head = new node;
    struct node *tail = new node;
    head = NULL;
    tail = NULL;
    cout<<"\nEnter the number of data element to be sorted: ";
    cin>>n;

    for(i = 0; i < n; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>num;

        tail = AddToList(tail, num);
        if(head == NULL)
            head = tail;
    }

    MergeSort(&head);

    cout<<"\nSorted Data ";

    while(head != NULL) 
    {
        cout<<".."<<head->data;
        head=head->next;
    }
    return 0;	
}
