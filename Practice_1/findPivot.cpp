#include<bits/stdc++>
using namespace std;
int findPivotHelper(vector<int> &vec, int start, int end)
{
    if(start>end)
    {
        //no pivot element
        return -1;
    }
    int mid = start + (end - start)/2;// to avoid integer overflow
    // is mid value the pivot?
    if(start<mid && vec[mid-1]>vec[mid])
    {
        return mid;
    }
    if(mid<end && vec[mid]>vec[mid-1])
    {
        return mid+1;
    }
    if(vec[start]<=vec[mid])
    {
        //first section is sorted
        //pivot in second section
        return findPivotHelper(vec,mid+1,end);
    }
    else{
        //second section is sorted
        //pivot in first section
        return findPivotHelper(vec,start,mid-1);
    }
}

int findPivot()
{
}

int main()
{

    return 0;
}
