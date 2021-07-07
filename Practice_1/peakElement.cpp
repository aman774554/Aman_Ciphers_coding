#include<bits/stdc++.h>
using namespace std;
int  search(vector<int> vec, int l, int r)
    {
        
        int mid= l+(r-1)/2;
        if((mid==0 || vec[mid]>vec[mid-1]) &&( mid == vec.size() - 1 || vec[mid]> vec[mid + 1]))
        return mid;
        if(vec[mid+1]>vec[mid])
        return search(vec,mid+1,r);
        else
        return search(vec,l,mid-1);
    }
int main()
{
    vector<int> vec;
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t; vec.push_back(t);
    }

    cout<<"Peak Element :"<<search(vec,0,vec.size());
}
