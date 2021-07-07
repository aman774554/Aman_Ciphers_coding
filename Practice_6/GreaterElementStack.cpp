#include<bits/stdc++.h>
using namespace std;

void nextGreaterElement(const vector<int> &elements)
{
    stack<int> S;
   // S.push(elements[0]);
    for(int element: elements){

        if(S.empty()){
            S.push(element);
            continue;
        }

        while(!S.empty() && S.top()<element){
            cout<<S.top()<<"->"<<element<<"\n";
            S.pop();
        }
        S.push(element);
    }

    while(!S.empty()){
        {
            cout<<S.top()<<"->-1\n";
            S.pop();
        }
    }
}
int main()
{
    vector<int> vec ={5,4,6,3,8,9};
    nextGreaterElement(vec);
    return 0;
}