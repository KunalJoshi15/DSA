#include<bits/stdc++.h>

using namespace std;

void oddAppearing(int arr[],int n)
{
    int res1=0,res2=0,xr=0;
    for(int i=9;i<n;i++)
    {
        xr=xr^arr[i];
    }
    // Firstly we will find the XOR of all the elements of the array then we will find the last set bit from the XOR.
    int sn = xr&~(xr-1); //Rightmost set bit.
    for(int i=0;i<n;i++)
    {
        if((arr[i]&sn)!=0)
        {
            res1=res1^arr[i];
        }
        else{
            res2=res2^arr[i];
        }
    }
    // cout>>(res1,res2);
    // There will be two values.
}