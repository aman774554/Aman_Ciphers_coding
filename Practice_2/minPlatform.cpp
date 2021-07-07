#include<bits/stdc++.h>
using namespace std;
int minPlatform(vector<int> &arrival, vector<int> &departure)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int minplat = 0, resultSoFar=0,n=arrival.size();
    int i=1,j=0;
    while(i<n && j<n){
        if(arrival[i]<=departure[j])
        {
            minplat++;
            i++;
        }
        else if(arrival[i]>departure[j]){
            minplat--;
            j++;
        }
        if(minplat>resultSoFar)
        {
            resultSoFar = minplat;
        }
    }
    return resultSoFar;
}
int main()
{
vector<int> arrival ={900, 900, 930 , 1120,700};

vector<int> departure = {1000, 1200, 1200, 900, 930};

cout<<minPlatform(arrival,departure);


}