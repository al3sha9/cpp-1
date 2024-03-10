#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data; 
    struct Node*next;
};
void linkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;

    //allocating memory dynamcily
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //linked first and second
    head -> data = 7;
    head -> next = second;

    //linked seocnd and third
    second -> data = 11;
    second -> next = third;

    //link third and null
    third ->data = 22;
    third->next = NULL;

    linkedListTraversal(head);

}
