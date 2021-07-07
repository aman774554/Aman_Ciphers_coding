#include<bits/stdc++.h>
using namespace std;
pair<int,int> searchMatrix(vector<vector<int>> matrix, int row, int key)
{
    for(int i=0;i<matrix[i].size();i++)
    {
        if(matrix[row][i]==key)
        return {row,i};
    }
    return {-1,-1};
}
pair<int,int> findInMatrix(vector<vector<int>> matrix, int key){
    if(matrix.size()==0)
       {
            return {-1,-1};
       }
    int min = matrix[0][0];
    int max = matrix[matrix.size()-1][matrix[0].size()-1];
    if(key> max || key<min)
    {
        return {-1,-1};
    }
    for(int i=0;i<matrix.size();i++)
    {
        if(key>=matrix[i][0] && key<=matrix[i][matrix[i].size()-1])
        {
            pair<int,int> result = searchMatrix(matrix,i,key);
            return result;
        }
    }
    return {-1,-1};
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix = {  {10,20,30,40,50},
                                    {60,70,80,90,100},
                                    {110,120,130,140,150},
                                    {160,170,180,190,200} };
    pair<int,int> result = findInMatrix(matrix,n);
    cout<<"("<<result.first<<","<<result.second<<")";
 
}