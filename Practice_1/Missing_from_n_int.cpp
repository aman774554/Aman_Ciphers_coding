#include<iostream>
using namespace std;
int main()
{
    int n,n_sum=0,i_sum=0;
    cin>>n;
    int arr[n];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        n_sum+=arr[i];
        i_sum+=i;
    }
    i_sum+=n;
    cout<<"Missing value: "<<i_sum-n_sum;
    return 0;
}
