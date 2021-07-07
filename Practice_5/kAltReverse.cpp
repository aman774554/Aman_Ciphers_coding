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


Node *KAltReverse(Node* head, int K)
{
    if(head==NULL|| head->next == NULL){
        return head;
    }
    int k = 0;
    Node *prev = NULL, *curr = head, *nxt = NULL;
    while(curr!=NULL && k < K){
        k++;
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    if(head!=NULL){
        head->next = curr;
    }
    k=0;
    while(k<K-1 && curr!=NULL)
    {
        curr = curr->next;
        k++;
    }
    if(curr!=NULL)
    {
        curr->next = KAltReverse(curr->next ,K);
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
    push(&head, 9);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    head= KAltReverse(head , 2);
    printList(head);
    return 0;
}
