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

int getSize(Node *head){
    int cnt =0;
    while(head!=NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void swapKFromEnd(Node **head, int k){
    int n = getSize(*head);
    if(n < k)
        return;
    
    if(2*k -1 == n)
        return;
    
    Node *ptr = *head;
    Node *qtr = NULL;
    for(int i=1;i<k;i++)
    {
        qtr = ptr;
        ptr = ptr->next;
    }

    Node *p = *head;
    Node *q = NULL;
    for(int i=1;i< n-k +1;i++)
    {
        q=p;
        p=p->next;
    }

    if(qtr!=NULL){
        qtr->next= p;
    }

    if(q!=NULL){
        q->next = ptr;
    }

    Node *temp = ptr->next;
    ptr->next = p->next;
    p->next = temp;

    if(k==1)
        *head = p;
    if(k==n)
        *head = ptr;

}


int main()
{
    Node *a = NULL;
    push(&a,6 );
    push(&a,5 );
    push(&a,4 ); 
    push(&a,3 );
    push(&a,2 );
    push(&a,1 );   
    printList(a);
    swapKFromEnd(&a,2);
    printList(a);
}