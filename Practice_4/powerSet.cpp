#include<bits/stdc++.h>
using namespace std;

template <typename T>

void printMatrix(vector<vector<T>> matrix){
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        cout<<matrix[i][j]<<" ";
         cout<<endl;
    }
   
}

void powerSetHelper(vector<int> &Set, vector<vector<int>> &result, vector<int> &subSet, int index){
    result.push_back(subSet);
    for(int i = index; i< Set.size();i++)
    {
        subSet.push_back(Set[i]);
        powerSetHelper(Set, result, subSet , i+1);
        subSet.pop_back();
    }
}

vector<vector<int>> powerSet(vector<int> Set){
    vector<int> subset;
    vector<vector<int>> result;

    powerSetHelper(Set, result, subset,0);
    return result;
}


int main()
{
    vector<int> vec = {1,2,3,4};
    vector<vector<int>> result = powerSet(vec);
    printMatrix(result);
    return 0;
}