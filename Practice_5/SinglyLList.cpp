#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void push(Node** head_ref, char val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void printList(Node *head){
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

void deleteNode(Node **head,int val){
    Node *temp = *head;
    Node *prev = NULL;
    if(temp==NULL)
    return;
    if(temp->data == val){
        *head = temp->next;
        delete temp;
        return;
    }
    while(temp!=NULL && temp->data != val){
        prev = temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    prev->next = temp->next;
    delete temp;
        
    }

int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    deleteNode(&head,4);
    printList(head); 
    return 0;
}