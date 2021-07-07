#include<bits/stdc++.h>
using namespace std;
vector<int> spiralMatrix(int arr[][100],int rows, int cols){
    int top=0, bottom= rows-1, left=0,right = cols-1, direction=0;
    vector<int> vec;
    while(top<=bottom || left<=right)
    {
        if(direction==0)
        {
            for(int i=left;i<=right;i++)
            {
                vec.push_back(arr[top][i]);
            }
            top++;
        }
        else if(direction==1)
        {
            for(int i=top;i<=bottom;i++)
            {            
                vec.push_back(arr[i][right]);
            }
            right--;

        }
        else if(direction==2)
        {
            for(int i=right;i>=left;i--)
            {
                vec.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        else if(direction==3)
        {
            for(int i=bottom;i>=top;i--)
            {
                vec.push_back(arr[i][left]);
            }
            left++;

        }
        direction= (direction+1)%4;
    }
    return vec;
}
int main()
{
    int arr[][100]= {
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7},
    };
    vector<int> v1;

    v1=spiralMatrix(arr,4,4);
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
}