#include<bits/stdc++.h>
using namespace std;

class minStack{
    private:
    vector<int> v1;
    vector<int> v2;

    public:
        void push(int x){
            v1.push_back(x);
            if( v2.size()==0 || x<=getMin())
            {
                v2.push_back(x);
            }
        }

        void pop(){
            if(v1.back()==getMin())
            {
                v2.pop_back();
            }
            v1.pop_back();
        }

        int top(){
            return v1.back();
        }

        int getMin(){
            return v2.back();
        }

};

int main()
{
    minStack *s = new minStack();
    s->push(10);
    s->push(2);
    s->push(10);
    cout<<s->top()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    cout<<s->getMin();
    return 0;
}