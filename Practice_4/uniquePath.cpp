#include<bits/stdc++.h>
using namespace std;


int countPath(int row, int col){
    vector<vector<int>> paths(row,vector<int>(col,0));
    for(int i=0;i<row;i++)
    {
        paths[i][0]=1;
    }
    for(int i=0;i<col;i++)
    {
        paths[0][i]=1;
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            paths[i][j]= paths[i-1][j] + paths[i][j-1];
        }
    }
    return paths[row-1][col-1];
}

int main()
{
    cout<<countPath(3,7);
    return 0;
}