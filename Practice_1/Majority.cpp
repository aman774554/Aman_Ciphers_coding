#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> vec) {
    // if(vec.size()==1)
       //  return vec[0];
        map<int, int> M;
        for(int i=0;i<vec.size();i++){
                M[vec[i]]++;
                if(M[vec[i]]> vec.size()/2)
                    return vec[i];
            }
        
        return -1;
    }
int main()
{
    int n,x;
    vector<int> vec;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    cout<<"Majority Element: "<<majorityElement(vec);
    return 0;
}