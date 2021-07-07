#include<bits/stdc++.h>
using namespace std;
int findMeet(int x1, int x2, int v1, int v2){
if(x1 <= x2 && v1 < v2 )
{
    return 0;
}
if (x2 <= x1 && v2 < v1){
    return 0;
}
if(x1<x2){
    int y=x1;
    x1= x2;
    x2=y;

    y=v1;
    v1=v2;
    v2=y;
}
if(x1==x2 && v1==v2)
return 1;
else if((x1-x2)%(v1-v2)==0)
return 1;
return 0;
}
int main()
{
    int x1, x2, v1, v2;
    cout << "Enter the positions: ";
    cin >> x1 >> x2;
    cout << "Enter their step size: ";
    cin >>v1 >> v2;
    if(findMeet( x1 , x2 , v1 , v2 ))
    cout<<"they meet";
    else
    cout<<"they don't meet";
    return 0;
}