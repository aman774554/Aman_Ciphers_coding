#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:

    int data;
    Stack *next;
};

bool isEmpty(Stack *s)
{
    if(s == NULL){
        return true;
    }
    return false;
}
 
void push( Stack **s, int val){
    Stack *newNode = new Stack();
    newNode->data = val;
    newNode->next = *s;
    *s = newNode;
}

void pop(Stack **s)
{
    Stack *temp;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);

}

int top( Stack *s){
    return s->data;
}

void sortedPush(Stack **s, int val)
{
    if(isEmpty(*s) || val< top(*s)){
        push(s,val);
        return;
    }
    
    int temp = top(*s);
    pop(s);

    sortedPush(s,val);
    push(s,temp);

}

void sortedStack(Stack **s){
    if(!isEmpty(*s)){
        int x = top(*s);
        pop(s);
        sortedStack(s);
        sortedPush(s,x);
    }
}

void printStack(Stack *s)
{
    while(s){
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl;
}

int main(){
    Stack *top = new Stack();
    push(&top, 30);
    push(&top, 10);
    push(&top, 40);
    push(&top, 50);
    push(&top, 100);
    printStack(top);

    sortedStack(&top);

    printStack(top);
    return 0;
}