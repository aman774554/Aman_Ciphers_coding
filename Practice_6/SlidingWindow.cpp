#include<bits/stdc++.h>
using namespace std;

vector<int> SlidingWindowMax(vector<int> window, int k){
    deque<int> dq;
    int i=0;
    for(;i<k;i++)
    {
        while(!dq.empty() && window[dq.back()]<= window[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vector<int> result;
        while(i<window.size())
        {
            result.push_back(window[dq.front()]);
            while(!dq.empty() && dq.front() <= i-k ){
                dq.pop_front();
            }
            while(!dq.empty() && window[dq.back()]<= window[i]){
            dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        result.push_back(window[dq.front()]);
    return result;
}
int main(){
    vector<int> vec  = {12,1,78,90,57,89,1,2,10};
    int k =3;
    vector<int> maxWindow = SlidingWindowMax(vec,k);
    //cout<< maxWindow.size();
    for(auto it = maxWindow.begin(); it <  maxWindow.end(); it++){
        cout<<*it<<" ";
    }
}