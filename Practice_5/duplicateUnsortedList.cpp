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

void push(Node **head_ref, int val){
     Node* newNode = new Node();
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

void removeDuplicates(Node* head){
    Node *ptr, *qtr, *duplicate;
    ptr = head;

    while(ptr !=NULL && ptr->next != NULL){
        qtr = ptr;
        while(qtr->next != NULL){
            if(ptr->data == qtr->next->data){
                duplicate = qtr->next;
                qtr->next = qtr->next->next;
                delete(duplicate);
            }
            else{
                qtr = qtr->next;
            }
        }
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 5);
    push(&head, 3);
    push(&head, 0);
    push(&head, 1);
    push(&head, 1);
    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}
