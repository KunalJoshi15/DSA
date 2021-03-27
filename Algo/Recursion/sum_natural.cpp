#include<bits/stdc++.h>
using namespace std;

int fun(int n){
    if(n==0) return 0;
    int smallAns = fun(n-1);
    return n+fun(n-1);
}

int main()
{
    int n;
    cin>>n;
    int sum = fun(n);
    cout<<sum;
}
// Base cases are the one which cannot be split into further smaller steps.