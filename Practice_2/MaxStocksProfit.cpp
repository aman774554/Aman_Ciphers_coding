#include<bits/stdc++.h>
using namespace std;
int findMaxProfit(vector<int> prices){
    int n= prices.size();
    int sum=0;
    if(n==1)
        return 0;
    int i=0;
    while(i<n-1)
    {
        while((i<n-1) && (prices[i+1]<=prices[i]))
        {
            i++;
        }
        if(i==n-1)
        {
            return 0;
        }    
        int buy=i++;
        while((i<n) && (prices[i]>=prices[i-1]))
            i++;
        int sell =i-1;

        sum+= prices[sell]-prices[buy];  
}

return sum;
}
int main()
{
    vector<int> prices ={ 100, 180, 260, 310, 40, 535, 695};
    cout<<"Gross Profit: "<<findMaxProfit(prices);
    return 0;
}