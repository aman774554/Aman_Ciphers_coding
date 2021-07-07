#include<bits/stdc++.h>
using namespace std;

void generateStringPermutationHelper(string &str, int start, int end, vector<string> &result){
    if(start>=end){
        result.push_back(str);
        return;
    }
    for(int i=start; i<=end;i++)
    {
        swap(str[i],str[start]);
        generateStringPermutationHelper(str,start+1,end,result);
        swap(str[i], str[start]);
    }
}
vector<string> generateStringPermutation(string &str){
    vector<string> result;
    generateStringPermutationHelper(str,0,str.size()-1,result);
    return result;
}
int main()
{
    string str ="abc";
    cout<<generateStringPermutation(str);
}