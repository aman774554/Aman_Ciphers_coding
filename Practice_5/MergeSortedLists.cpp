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

Node *sortedMerge(Node *a, Node *b){
    Node *res = NULL;
    if(a == NULL)
        return b;
    
    if(b == NULL)
        return b;

    if(a->data <= b->data){
        res = a;
        res->next = sortedMerge(a->next,b);
    }
    else{
        res = b;
        res->next = sortedMerge(a,b->next);
    }
    return res;
}

int main()
{
	Node *a=NULL, *b=NULL;

	push(&a,7 );
    push(&a,5 );
    push(&a,1 );
   
	push(&b,100);
    push(&b,10 );
    push(&b,9 ); 
    push(&b,0 );    

	Node* head = sortedMerge(a,b);
    
	printList(head);

	return 0;
}