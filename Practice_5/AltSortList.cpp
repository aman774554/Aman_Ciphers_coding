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

Node* rearrange(Node *head){
    if(head==NULL || head->next ==NULL)
    return head;
    Node *odd=head, *even=head->next, *nxt = even;
    while(1){
        if(odd == NULL || even == NULL || even->next== NULL){
            odd -> next = nxt;
            break;
        }
        odd->next = even->next;
        odd = even->next;

        if(odd->next ==NULL){
            even -> next =NULL;
            odd->next = nxt;
            break;
        }
        
        even-> next = odd->next;
        even = odd->next;
    }
return head;
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
    push(&head, 4);
    push(&head, 0);
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1 );
    printList(head);
    head = rearrange(head);
    printList(head);
    return 0;
}

