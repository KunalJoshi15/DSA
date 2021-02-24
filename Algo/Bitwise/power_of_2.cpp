#include<bits/stdc++.h>

using namespace std;
bool isPow2(int n)
{
    if(n==0)
        return false;
    return (n&(n-1)==0);
    //These two can be clubbed into one case.
    // The logical and of both the numbers are performed.
}

int main()
{
    int n;
    cin>>n;
    // If there is only one set bit then it is definitely a power of 2.
    //The better approach will be
}