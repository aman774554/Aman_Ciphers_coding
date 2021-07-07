#include<bits/stdc++.h>
using namespace std;

int countTrailingZeroes(int n){
    if(n<0)
        return 0;
    int cnt = 0;
    for(int i= 5 ; n / i >= 1; i*=5)
    {
        cnt += n/i;
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    cout<<"No of trailing zeroes in "<<n<<"! : "<<countTrailingZeroes(n);
    return 0;
}