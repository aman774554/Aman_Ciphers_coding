#include<bits/stdc++.h>
using namespace std;

 

int greaterThanOrEqual(int num, vector<vector<int>> mat){
    int result = 0;

    for(int i=0;i<mat.size();i++)
    {
        if(mat[i][0]>num)
            return result;

        if(mat[i][mat.size()-1]<=num){
            result += mat.size();
            continue;
        }

        int greaterThan = 0;
        for( int j = mat.size()/2; j>=1; j/=2){
            while(greaterThan + j < mat.size() && 
                   mat[i][greaterThan+ j] <= num){
                       greaterThan += j;
                   }
        }
        result += greaterThan + 1;
    }
    return result;
}

int KthSmallest( vector<vector<int>> mat, int k){
    int l = mat[0][0], r= mat[mat.size()-1][mat[0].size()-1];

    while(l<=r){
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualToMid = greaterThanOrEqual(mid, mat);
        if(greaterThanOrEqualToMid >= k)
        r =mid -1;
        else
        l = mid + 1;
    }
    return l;
}
 
int main() {
    vector<vector<int>> mat = { {10, 20, 30, 40},
                                {15, 25, 35, 45},
                                {25, 29, 37, 48},
                                {32, 33, 39, 50}};
    cout << KthSmallest(mat, 7);
    return 0;
}
