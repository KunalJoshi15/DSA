#include<bits/stdc++.h>

using namespace std;
void primeDivisors(int n)
{
    //Naive Solution to find the prime divisors of a number;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            cout<<i;
    }
    return;
}

//Better solution using the underlying concept that the numbers always appear in a pair.
void efficientPrimeDivisors(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i;
            if(i!=n/i)
            {
                cout<<(n/i);
            }
        }
    }
}
// We can even print the divisors of the number in the sorted order.
void sortedDivisors(int n)
{
    int i=1;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
            cout<<i;
    }
    for(;i>=1;i--)
    {
        if(n%i==0)
        {
            cout<<(n/i);
        }
    }
}
int main()
{

    return 0;
}