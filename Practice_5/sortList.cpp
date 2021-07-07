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

void sortList(Node *head){
    Node *curr = head, *index = NULL;
    int temp;

    if(head == NULL)
        return;
    while(curr != NULL){
        index = curr->next;
        while(index != NULL){
            if(curr->data > index->data){
                temp = curr ->data;
                curr->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        curr = curr->next;        
    }
}


int main()
{
    Node *head = NULL;
    push(&head, 6);
    push(&head, 9);
    push(&head, 0);
    push(&head, 11);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    sortList(head);
    printList(head);
    return 0;
}
