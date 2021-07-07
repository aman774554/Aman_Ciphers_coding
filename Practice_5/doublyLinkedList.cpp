#include<bits/stdc++.h>
using namespace std;

class doublyLinkedList{
    public:
    int data;
    doublyLinkedList *next;
    doublyLinkedList *prev;
};


void push(doublyLinkedList **head_ref, int val){
    doublyLinkedList *newNode = new doublyLinkedList();
    newNode->data = val;
    newNode->next =(*head_ref);
    newNode->prev = NULL;

    if((*head_ref)!=NULL){
        (*head_ref)->prev = newNode;
    }
    (*head_ref)= newNode;

}


void deleteNode(doublyLinkedList **head_ref, doublyLinkedList *del){
    if(*head_ref == NULL || del == NULL){
        return;
    }

    if(*head_ref==del){
        *head_ref = del->next;
    }

    if(del->next !=NULL){
        del->next->prev = del->prev;
    }

    if(del->prev!=NULL){
        del->prev->next == del->next;
    }

    free(del);
    return;
}

void printListForward(doublyLinkedList* node)
{
    while (node != NULL) {
        cout<<node->data<<" ";
        node = node->next;
    }    
}

void printListBackward(doublyLinkedList* last)
{
    while (last != NULL) {
        cout<< last->data<<" ";
        last = last->prev;
    }
}
  

int main()
{
    doublyLinkedList* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
 
    cout << "Original Linked list ";
    printListForward(head);
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    return 0;
}