#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    vector<int> v1;

    public:
        void push(int x){
            v1.push_back(x);
        }

        void pop(){
            v1.pop_back();
        }

        int top(){
            return v1.back();
        }

        bool empty(){
            return v1.empty();
        }
        int size(){
            return v1.size();
        }

};

int main()
{
    Stack *s = new Stack();
    s->push(10);
    s->push(2);
    s->push(10);
    cout<<s->top()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    cout<<s->empty()<<endl;
    cout<<s->size();
    return 0;
}