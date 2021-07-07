#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2){
    vector<int> mergedArray(arr1.size() +  arr2.size());
    int i=0, j=0, k=0;
    while(i<arr1.size() && j< arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            mergedArray[k]= arr1[i];
            i++;
        }
        else{
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }
    while( i < arr1.size())
    {
        mergedArray[k] = arr1[i];
        i++; k++;
    }
    while( j < arr2.size())
    {
        mergedArray[k] = arr2[j];
        j++; k++;
    }
    return mergedArray;

}


int main(){
    
    vector<int> a ={ 1,3,5,7,9};
    vector<int> b ={ 2,4,6,8,9,10,12,14};
    vector<int> c = mergeSortedArrays(a,b);
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<" ";
    return 0;
}
