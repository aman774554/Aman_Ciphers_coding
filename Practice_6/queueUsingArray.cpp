#include<bits/stdc++.h>
using namespace std;

class Queue{
vector<int> vec;
public:
    void push(int v){
        vec.push_back(v);
    }

    void pop(){
        vec.erase(vec.begin());
    }

    int front(){
        return *vec.begin();
    }

    bool empty(){
        return vec.empty();
    }
    int size(){
        return vec.size();
    }
};

int main(){

    Queue *q= new Queue();
    q->push(1);
    q->push(2);
    q->push(3);
    q->pop();
    cout<<q->front()<<endl;
    cout<<q->empty()<<endl;
    cout<<q->size()<<endl;
    return 0;
}