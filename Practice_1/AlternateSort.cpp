#include<bits/stdc++.h>
using namespace std;
void AlternateSort(vector<int> arr){
sort(arr.begin(),arr.end());
int i=0,j=arr.size()-1;
while(i<j)
{
    cout<<arr[j--]<<" ";
    cout<<arr[i++]<<" ";
}
if(arr.size()%2!=0)
    cout<<arr[i];
}
int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    AlternateSort(vec);
}
