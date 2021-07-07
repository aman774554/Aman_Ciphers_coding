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


Node *reverseInGroup(Node* head, int K)
{
    if(head==NULL|| head->next == NULL){
        return head;
    }
    int k=0;
    Node *prev = NULL, *curr = head, *nxt = NULL;
    while(curr!=NULL && k < K){
        k++;
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    if(nxt!=NULL)
    {
        head->next = reverseInGroup(nxt ,K);
    }
    return prev;
}


void printList(Node *head){
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

int main()
{
    Node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    head= reverseInGroup(head , 4);
    printList(head);
    return 0;
}
