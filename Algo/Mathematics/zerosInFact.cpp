#include<bits/stdc++.h>

using namespace std;

int zeros(int n)
{
    if(n==0)
        return 0;
    return n+zeros(n/5);
}

int main()
{
    int n;
    cin>>n;
    int no = zeros(n/5);
    cout<<no<<endl;
}