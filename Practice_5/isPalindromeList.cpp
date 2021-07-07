#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
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

bool isPalindrome(Node **left, Node *right){
    if(right==NULL){
        return true;
    }

    bool isPalin = isPalindrome(left, right->next);
    if(!isPalin){
        return false;
    }
    bool isDataEqual = ((*left)->data== right->data);
    (*left) = (*left)->next;
    return isDataEqual;
}

bool isPalindrome(Node * head){
    return isPalindrome(&head,head);
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
    /* Start with the empty list */
    Node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
        printList(head);
        isPalindrome(head) ? cout << "Is Palindrome\n\n" : cout << "Not Palindrome\n\n";
    }
 
    return 0;
}