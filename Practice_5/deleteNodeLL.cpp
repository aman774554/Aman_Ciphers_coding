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
 
 
 void deleteFromList(Node ** head, int val){
    Node *temp;
    if((*head)->data == val){
        temp =*head;
        *head = (*head)->next;
        free(temp);
    }
    else{
        Node *curr = *head;
        while(curr->next != NULL)
        {
            if(curr->next->data == val)
            {
                temp = curr->next;
                curr->next = curr->next->next;
                free(temp);
            }
            else{
                curr = curr->next;
            }
        }
    }
}
int main()
{
	Node *a=NULL;

	push(&a,7 );
    push(&a,5 );
    push(&a,1 );  

	deleteFromList(&a, 7);
    
	printList(a);

	return 0;
}