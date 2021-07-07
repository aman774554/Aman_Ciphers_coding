#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerNumber(vector<int> vec){

    if(vec.size()==0)
    {
        return vec;
    }
    stack<int> S;
    vector<int> res;
    res.push_back(-1);
    S.push(vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i]>S.top())
        {
            res.push_back(S.top());
            S.push(vec[i]);
        }
        else{
            while(!S.empty() && vec[i] <= S.top()){
                S.pop();
            }
            if(S.empty())
                res.push_back(-1);
            else
                res.push_back(S.top());

            S.push(vec[i]);
        }
    }
    return res;


}

int main()
{
    vector<int> vec ={1,2,3,4,5,6};
    vector<int> ans = nearestSmallerNumber(vec);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}