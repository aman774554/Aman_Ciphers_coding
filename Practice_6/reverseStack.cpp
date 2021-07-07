#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &S, int x){
    if(S.empty()){
        S.push(x);
        return;
    }
    else{
        int temp = S.top(); S.pop();
        InsertAtBottom(S,x);
        S.push(temp);
    }
}

void reverseStack(stack<int> &S)
{
    if(S.empty()){
        return;
    }
    else{
        int temp = S.top();
        S.pop();
        reverseStack(S);
        InsertAtBottom(S,temp);
    }
}

int main()
{
    stack<int> S, S2;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(10);
    S2 = S;
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
    reverseStack(S2);
    while(!S2.empty()){
        cout<<S2.top()<<" ";
        S2.pop();
    }
}
