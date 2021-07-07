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
void push(Node** head_ref, char val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}
int getSize(Node *head){
    Node *ptr = head;
    int size =0;
    while(ptr !=  NULL){
        size++;
        ptr= ptr->next;
    }
    return size;
}
Node* findIntersection(Node *larger, Node *smaller, int d){
    Node *ptr = larger, *qtr = smaller;
    for(int i=0; i<d && ptr!= NULL; i++){
        ptr = ptr->next;
    }
    while(ptr!=NULL && qtr!=NULL){
        if(ptr==qtr)
            return ptr;
        ptr = ptr->next;
        qtr = qtr->next;
    }
    return NULL;
}
Node* findIntersection(Node *a, Node *b){
    if(a==NULL || b == NULL){
        return NULL;
    }
    int cntA = getSize(a);
    int cntB = getSize(b);
    int d = cntA - cntB;
    if(d>=0){
        return findIntersection(a,b,d);
    }
    else
    {
        return findIntersection(b,a,d);
    }

}


int main()
{
    /* Start with the empty list */
    Node *head = NULL, *hd =NULL;
 
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&hd,1);
    push(&hd,2);
    push(&hd,3);
    push(&hd,4);
    head->next->next->next= hd->next;
    Node *ptr = findIntersection(head,hd);
    if(ptr!=NULL)
    cout<<ptr->data;
    else
    cout<<"No Intersection";
   
    
 
    return 0;
}