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


Node* addTwoNumbers(Node* a, Node* b){
    if(a == NULL){
        return b;
    }
    else if( b == NULL){
        return a;
    }
    else{
        Node dummy;
        Node *ptr = &dummy;
        int sum =0, carry =0;
        while(a!=NULL ||b!=NULL){
            sum = (a==NULL ? 0: a->data)+(b== NULL ?0:b->data)+carry;
            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new Node(sum);
            ptr=ptr->next;
            if(a!=NULL)
                a = a->next;
            if(b!=NULL)
                b = b->next;
        }
        if(carry > 0){
            ptr->next= new Node(carry);
            ptr=ptr->next;
        }
        return dummy.next;
    }
    
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
    Node *head = NULL, *hd =NULL;
    push(&head, 4);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&hd,9);
    push(&hd,8);
    push(&hd,6);
    push(&hd,8);
    push(&hd,9);
    printList(head);
    printList(hd);
    Node *ptr = addTwoNumbers(head, hd);
    printList(ptr);
    return 0;
}