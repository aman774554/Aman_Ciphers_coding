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
    if(head == NULL || head->next == NULL){
        return;
    }
    
    Node *ptr = head, *qtr = head->next;
    while(ptr!= NULL && qtr!= NULL){
        if(ptr->data == qtr->data)
        {
            ptr->next = qtr->next;
            delete qtr;
            qtr = ptr->next;
        }
        else{
            ptr =ptr->next;
            qtr = qtr->next;
        }

    }
}

int main()
{
    Node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 3);
    push(&head, 3);
    push(&head, 1);
    push(&head, 1);
    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}
