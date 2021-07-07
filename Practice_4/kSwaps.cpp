#include<bits/stdc++.h>
using namespace std;

int kSwaps(string number,int k){
    
    int max = stoi(number);
    if(k==0)
        return max;
    string cpy = number;
    for(int s=0; s<k;s++)
    {
        for(int i=0;i<number.size();i++)
        {
            for(int j=number.size()-1; j>=0;j--)
            {
                if(cpy[i] < cpy[j])
                {
                char tmp =cpy[i];
                cpy[i]=cpy[j];
                cpy[j]=tmp;
                }
                int temp = stoi(cpy);
                if(temp > max){
                    max = temp;
                }
            }
            cpy = number;
        }
        number = to_string(max);
    }
    return max;
}

int main()
{
    string str ="1234599";
    cout<<kSwaps(str,3);
}