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
    Node *last = *head_ref;
    newNode->data = val;
    newNode->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = newNode;
        return;
    } 
    while(last->next!=NULL){
        last = last ->next;
    }
    last->next = newNode;
}


void printList(Node *head){
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

bool isPresent(Node *head, int val){
    if(head == NULL)
        return false;
    while(head!=NULL){
        if(head->data==val)
            return true;
        head = head->next;
    }
    return false;
}
Node *getUnion( Node *a , Node *b){
    Node *result = NULL;
    Node *head_a =a, *head_b =b;

    while(head_a!= NULL){
        push(&result, head_a->data);
        head_a = head_a->next;
    }

    while(head_b!=NULL){
        if(!isPresent(result, head_b->data))
            push(&result, head_b->data);
            head_b = head_b->next;
    
    }
    return result;
}

Node *getIntersection( Node *a , Node *b){
    Node * res =NULL;
    Node* head_a = a;
    while(head_a!=NULL){
        if(isPresent(b,head_a->data)){
            push(&res,head_a->data);
        }
        head_a = head_a->next;
    }
    return res;
}

int main()
{
    Node *a = NULL, *b =NULL;
    push(&b, 2);
    push(&b, 1);

    push(&a,9);
    push(&a,1);
    printList(a);
    printList(b);
    Node *ptr = getUnion(a,b);
    Node *qtr = getIntersection(a,b);
    printList(ptr);
    printList(qtr);
    return 0;
}
