#include<bits/stdc++.h>
using namespace std;
int trappingRain(const vector<int> &vec)
{
    int n=vec.size();
    if(n<=1)
        return 0;
    vector<int> left(n,0), right(n,0);
    left[0]=vec[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],vec[i]);
    }
    right[n-1]=vec[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],vec[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x=min(left[i],right[i])-vec[i];
        if(x>0)
        {
            sum+=x;
       }
    }
    return sum;
}
int main()
{
    vector<int> vec ={ 2,3,1,2,4,2,3};
    cout<<trappingRain(vec);
}

/*
1. Sorting programs
2. Peak element
3. equilibrium point
4. dynamic array(should have the same functions like vector)
5. Alternative sorting (multiple peaks)
*/