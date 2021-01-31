#include<bits/stdc++.h>

using namespace std;

int countNoDigits(int a)
{
    if(a==0)
        return 0;
    return 1+countNoDigits(a/10);
}

int main()
{
    int n;
    cin>>n;
    int p = countNoDigits(n);
    cout<<p<<endl;
}
/*
Similarly this code can be written by using the concept of iterative solution.
*/