#include<bits/stdc++.h>
#include<sstream>
using namespace std;

bool isValidPart(string s){
    if(s.size()>3)
        return false;
    if(s[0]=='0' && s.size()>1)
        return false;
    int str =0;
    stringstream convert(s);
    convert>>str;
    return str>= 0 && str <=255;
}

vector<string> restoreIpAddress(string ip){
    vector<string> result;
    int n = ip.size();
    for(int i = 1 ; i < n && i < 4 ; ++i)
    {
        string first = ip.substr(0,i);
        if(!isValidPart(first))
        {
            continue;
        }
        for(int j = 1; i + j < n && j < 4; ++j)
            {
                string second = ip.substr(i, j); 
                if(!isValidPart(second))
                {
                    continue;
                }
                for(int k = 1; i + j + k < n && k < 4; ++k)
                {
                    string third = ip.substr(i+j, k);
                    string fourth = ip.substr(i+j+k);
                    if(!isValidPart(third) || !isValidPart(fourth))
                    {
                        continue;
                    }
                    //cout<<first<<" "<<second<<" "<<third<<" "<<fourth;
                    result.push_back(first + "."+ second +"."+third+"."+fourth);
                }   
            }
    }

    return result;
}

int main()
{
    string a = "2550255255";
    vector<string> ipAddress = restoreIpAddress(a);
    for(int i=0;i<ipAddress.size();i++)
    {
        cout<<ipAddress[i]<<" ";
    }
     
}