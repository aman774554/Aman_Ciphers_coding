
#include<bits/stdc++.h>
using namespace std;
void segregate0s1s(vector<int> &vec){
    int start=0, end = vec.size()-1;
    while(start<end)
    {
        while(start < end && vec[start]==0) start++;

        while(start<end && vec[end]==1) end--;

        if(start < end ) {
            swap(vec[start],vec[end]);
            start++;
            end--;
        }
    }


}
int main()
{
    vector<int> vec;
    int n,x;
    cout<<"Enter no of inputs: ";
    cin>>n;
    cout<<"Enter "<<n<<" 0s and 1s:\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    segregate0s1s(vec);
    for(int i=0;i<=5;i++)
    {
        cout<<vec[i];
    }
    return 0;
}


//find recursive solution for spiral matrix
//find logn solution for searching in rotated sorted array