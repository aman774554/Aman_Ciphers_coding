#include<bits/stdc++.h>
using namespace std;




int titleToNumber(string s)
{
    int result = 0;
    for (int i=0;i<s.size();i++)
    {
        result *= 26;
        result +=  s[i]  - 'A' + 1;
    }
  
    return result;
}
int main(){
    string str;
    cin>>str;
    cout<<titleToNumber(str);
    return 0;
}