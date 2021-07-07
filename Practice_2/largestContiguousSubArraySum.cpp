#include<bits/stdc++.h>
using namespace std;

int largestContiguousSubarraySum(vector<int> vec){
    if(vec.size() == 0) return 0;

    int maxSum = vec[0], currMax = vec[0];
    for(int i= 1; i< vec.size();i++){
        currMax = max( currMax, currMax + vec[i]);
        currMax = max(currMax, vec[i]);
        maxSum = max(maxSum, currMax);
    }
    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<largestContiguousSubarraySum(vec);
}