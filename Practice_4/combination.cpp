#include<bits/stdc++.h>
using namespace std;
void findCombinationHelper(vector<vector<int>> &result, vector<int> &arr, int n, int left, int k){
    if(k==0)
    {
        result.push_back(arr);
        return;
    }

    for(int i=left; i<=n;i++)
    {
        arr.push_back(i);
        findCombinationHelper(result, arr, n, i+1, k-1);
        arr.pop_back();
    }
}
vector<vector<int>> findCombination(int n,int k){
    vector<int> arr;
    vector<vector<int>> result;
    findCombinationHelper(result, arr, n, 1, k);
    return result;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<"total combinations from 1 to "<<n<<" of length "<<k<<" : \n";
    vector<vector<int>> combinations = findCombination(n,k);
    for(int i=0;i<combinations.size();i++)
    {
        for(int j=0; j<combinations[i].size();j++)
        {
            cout<<combinations[i][j]<<" ";
        }
        cout<<endl;
    }
}