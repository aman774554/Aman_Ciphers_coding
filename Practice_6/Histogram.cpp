#include<bits/stdc++.h>
using namespace std;

int maxArea(const vector<int> &hist){
    if(hist.size() == 0){
        return 0;
    }
    if(hist.size()==1){
        return hist[0];
    }
    //stores indexes
    stack<int> S;
    int maxArea = 0, currArea, topElement;
    int i=0;
    while(i<hist.size()){
        if(S.empty() || hist[S.top()]<= hist[i]){
            S.push(i);
            i++;
        }
        else{
            topElement = S.top();
            S.pop();
            if(S.empty()){
                currArea = hist[topElement]*i;
            }
            else{
                currArea =  hist[topElement] * (i- 1 - S.top());
            }
            maxArea = max(maxArea, currArea);
        }
        
    }
    while(!S.empty()){
            topElement = S.top();
            S.pop();
            if(S.empty()){
                currArea = hist[topElement]*i;
            }
            else{
                currArea =  hist[topElement] * (i- 1 - S.top());
            }
            maxArea = max(maxArea, currArea);
        }
    return maxArea;
}

int main()
{
    vector<int> hist = {6,2,2,6,6,1};
    cout<<maxArea(hist);
    return 0;
}