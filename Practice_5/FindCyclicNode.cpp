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

Node* FindCyclicNode(Node *head){
    if(head == NULL|| head->next == NULL){
        return NULL;
    }
    if(head->next == head){
        return head;
    }
    bool isCylic = false;
    Node *slowPtr = head, *fastPtr = head;
    while(fastPtr != NULL && fastPtr->next == NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr){
            isCyclic = true;
            break;
        }
    }
    if(isCylic){
        slowPtr = head;
        while(fastPtr!=NULL){
            if(slowPtr == fastPtr){
                return slowPtr;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    return NULL;
}