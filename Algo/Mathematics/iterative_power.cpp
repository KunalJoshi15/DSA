// The time complexity for this particular solution as well is O(log n)
#include<bits/stdc++.h>

using namespace std;

int power(int x,int n)
{
    int res=1;
    while(n>0)
    {
        if(n%2!=0)
        {
            res=res*x;
        }
        x=x*x;
        n=n/2;
    }
    // If the last bit is 1 then we multiply the result with the value of x and in each iteration the value of x is multiplied with itself.
    return res;
}

int main()
{
    int n;
    cin>>n;
}