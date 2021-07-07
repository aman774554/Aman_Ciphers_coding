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

Node *mergeKLL(Node * arr[], int k){
    for(int i=1; i<=k;i++)
    {
        while(1){
            Node *head_first = arr[0], *head_i = arr[i];
            if(head_i == NULL)
                break;

            if( head_first->data >= head_i->data){
                arr[i] = head_i->next;
                head_i->next = head_first;
                arr[0] = head_i;
            }
            else{
                while(head_first ->next!= NULL){
                    if( head_first->next->data >= head_i->data){
                        arr[i] = head_i->next;
                        head_i->next = head_first->next;
                        head_first->next = head_i;
                        break;
                    }
                    head_first = head_first->next;

                    if(head_first->next == NULL)
                    {
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_first->next = head_i;
                        head_first->next->next = NULL;
                        break;
                    }
                }
            }
        }
    }
    return arr[0];
}
int main()
{
	int k = 3;
	Node *arr[k];

    arr[0]=NULL;
	push(&arr[0],7 );
    push(&arr[0],5 );
    push(&arr[0],1 );
    
    arr[1]=NULL;
	push(&arr[1],100);
    push(&arr[1],10 );
    push(&arr[1],9 );
    
    arr[2]=NULL;
    push(&arr[2],11 );
    push(&arr[2],2 );
    push(&arr[2],1 );    

	Node* head = mergeKLL(arr, k - 1);
    
	printList(head);

	return 0;
}
