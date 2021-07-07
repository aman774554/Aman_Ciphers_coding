#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Stack {
    queue<T> Q;
    public:
    void push(T x){
        Q.push(x);
        int size = Q.size();
        for(int i=0;i< size -1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
    void pop(){
        Q.pop();
    }
    T top(){
        return Q.front();
    }
    int size(){
        return Q.size();
    }
    bool empty(){
        return Q.empty();
    }
};

int main()
{
Stack<char> S;
for(int i=0;i<10;i++)
{
S.push(char('a'+i));
}
while(S.size()>0)
{
cout<<S.top()<<" ";
S.pop();
}
cout<<S.empty();
}