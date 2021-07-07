#include<bits/stdc++.h>
using namespace std;
 

int digit[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
 
int lastNonZeroInFactorial(int n)
{
     if (n < 10)
        return digit[n];
    if (((n/10)%10)%2 == 0) //second last digits i.e 10s place is even or not
        return (6*lastNonZeroInFactorial(n/5)*digit[n%10]) % 10;
    else
        return (4*lastNonZeroInFactorial(n/5)*digit[n%10]) % 10;
}
 
// Driver code
int main()
{
    int n = 121;
    cout << lastNonZeroInFactorial(n);
    return 0;
}