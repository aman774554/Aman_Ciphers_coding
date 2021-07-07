#include<bits/stdc++.h>
using namespace std;


int isPartitionSubset(int arr[], int n, int sum){
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;
 
    if (arr[n - 1] > sum)
        return isPartitionSubset(arr, n - 1, sum);
 
    return isPartitionSubset(arr, n - 1, sum)
           || isPartitionSubset(arr, n - 1, sum - arr[n - 1]);
}
    
int equalPartition(int n, int arr[])
{
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2==1)
        return 0;
    sum = sum / 2;
    return isPartitionSubset(arr, n, sum);
}

int main()
{
    int array[]= {1, 4, 5};
    if(equalPartition(3,array))
        cout<<"Yes";
    else
        cout<<"No";
}